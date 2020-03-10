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
#include <array>
#include <cppcms/json.h>
#include <fstream>
typedef std::array<std::string,4> project_t;
typedef std::vector<project_t> projects_t;
typedef cppcms::json::value json;
#define json_address "configs/data.json"
#define projects_address "data/projects/"
namespace projects_page_content{

	struct content: public cppcms::base_content{   
        projects_t projects;
        json js;
        content(){
            std::ifstream file{json_address};
            if(!file.is_open()){std::cerr << "site: can't open file";}
            file >> this->js;
            file.close();

            auto vec = this->js.at("projects").array();
            for(auto&i: vec){
                auto i_ = i.array();
                std::string title, name_of_file, mini_text, github_link;
                title = i_.at(0).str();
                name_of_file = i_.at(1).str();
                mini_text = i_.at(2).str();
                github_link = i_.at(3).str();
                this->projects.push_back({title, name_of_file, mini_text, github_link});
            }
        }          
	};

    struct content2: public cppcms::base_content{
        std::string title, name_of_file, text{""}, github_link;
        json js;
        content2(std::string project_name){
            std::ifstream file{json_address};
            if(!file.is_open()){std::cerr << "site: can't open file";}
            file >> this->js;
            file.close();

            auto vec = this->js.at("projects").array();
            for(auto&i: vec){
                auto i_ = i.array();
                std::string title = i_.at(0).str();
                if(title == project_name){
                    this->title = title;
                    this->name_of_file = i_.at(1).str();
                    //this->mini_text = i_.at(2).str();
                    this->github_link = i_.at(3).str();
                    file.open(projects_address + this->name_of_file);
                    if(!file.is_open()){std::cerr << "site: can't open file";}
                    std::string t_;
                    while(file >> t_){this->text += t_;}
                    break;
                }
            }
        }
    };

};
#endif
