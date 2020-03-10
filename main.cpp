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

//pages headers
#include "pages/default_page/default_page.hpp"
#include "pages/blog/blog.hpp"
//!pages headers


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

		//blog
		dispatcher().assign("/blog",&site_application::blog, this);
		mapper().assign("blog","/blog");
		dispatcher().assign("/blog/(\\S+)", &site_application::blog,this,1);
		mapper().assign("blog","/blog/(\\S+)");
		//!blog

		//add blog
		dispatcher().assign("/post/add_blog", &site_application::add_blog,this);
		mapper().assign("add_blog","/post/add_blog");
		//!add blog

		//books page
		dispatcher().assign("/books", &site_application::books,this);
		mapper().assign("books","/books");
		dispatcher().assign("/books/(\\S+)", &site_application::books,this,1);
		mapper().assign("books","/books/(\\S+)");
		//!books page

		//projects page
		dispatcher().assign("/project", &site_application::project, this);
		mapper().assign("project", "/project");
		dispatcher().assign("/project/(\\S+)", &site_application::project, this,1);
		mapper().assign("project", "/project/(\\S+)");
		//!projects page
		
		//add project
		dispatcher().assign("/project/add_project", &site_application::add_project_page, this);
		mapper().assign("add_project","/project/add_project");
		dispatcher().assign("/post/add_project",&site_application::add_project,this);
		mapper().assign("add_project","/post/add_project");
		//!add project
		
		//delete project
		//!delete project
		
		

	}

	void default_page(){
		default_page_content::content c;
		render("default_page_view",c);	
	}
	void blog(){
		blog_page_content::content c;
		render("blog_page_view",c);
	}
	void blog(std::string blog){
		blog_page_content::content_2 c{blog};
		render("blog_page_view_2",c);
	}

	void add_blog(){
		if(request().request_method() == "POST"){
			
		}
	}



	void books(){
		//nothing

	}
	void books(std::string str){
		//nothing
	}
	void project(){

	}
	void project(std::string str){}
	void add_project_page(){}
	void add_project(){}


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
