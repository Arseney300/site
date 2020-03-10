/*
 * @project site
 * @file projects.hpp
 * @author Soundwave
 * @date Mar 10, 2020
 * @brief projects page data
 * */


#ifndef projects_h
#define projects_h
#include <cppcms/view.h>
#include <string>
#include <cppcms/form.h>
#include <utility>
#include <vector>

typedef std::tuple<std::string, std::string, std::string> project_t;
typedef std::vector<project_t> projects_t;

namespace projects_page_content{

	struct content: public cppcms::base_content{   
        projects_t projects;
        content(){
            //read json
            //read file
        }          
	};

};
#endif
