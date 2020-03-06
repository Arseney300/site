/*
 * @project site
 * @file main.c
 * @author Soundwave
 * @date Mar 6, 2020
 * @brief main site application
 * */

//cpp headers
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <fstream>
#include <stdlib.h>
#include <filesystem>
//!cpp headers

//boost headers
#include <boost/any.hpp>
#include <boost/assert.hpp>
#include <boost/assign/std/vector.hpp>
#include <boost/assign/std/map.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/array.hpp>
//!boost headers


//cppcms headers
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/http_request.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_file.h>
#include <cppdb/frontend.h>
//!cppcms headers

//main class:
class site_application: public cppcms::application{
private:
	//some private data
public:
	site_application(cppcms::service &srv):
		cppcms::application{srv}
	{
		//default page
		dispatcher().assign("",&site_application::default_page,this);
		dispatcher().assign("/",&site_application::default_page,this);
		mapper().assign("");
		//!default page
		
		//books page
		dispatcher().assign("/books/(\\S+)", &site_application::books,this,1);
		mapper().assign("books","/books");
		//!books page

	}

	void default_page(){
		response().out() << "default page";
	}

	void books(std::string arg){
		response().out() << arg;
	}


};

int  main(int argc, char**argv){
	try{
		cppcms::service main_service{argc, argv};
		main_service.applications_pool().mount(
			cppcms::applications_factory<site_application>()
		);
		main_service.run();
	}
	catch(std::exception &e){
		std::cerr<< e.what() << std::endl;
	}
	return 0;

}
