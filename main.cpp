


#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <fstream>
#include <stdlib.h>
#include <filesystem>



#include <boost/any.hpp>
#include <boost/assert.hpp>
#include <boost/assign/std/vector.hpp>
#include <boost/assign/std/map.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/array.hpp>

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

class site_application: public cppcms::application{
private:
	//some praviate data
public:
	site_application(cppcms::service &srv):
		cppcms::application{srv}
	{
		dispatcher().assign("",&site_application::default_page,this);
		dispatcher().assign("/",&site_application::default_page,this);
		mapper().assign("");

	}

	void default_page(){
		response().out() << "default page";
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
