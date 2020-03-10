/*
 * @project site
 * @file blog.hpp
 * @author Soundwave
 * @date Mar 10, 2020
 * @brief blog page data
 * */


#ifndef blog_h
#define blog_h
#include <cppcms/view.h>
#include <string>
#include <cppcms/form.h>
#include <utility>
#include <vector>
#include <cppcms/json.h>
#include <fstream>
#include <array>
typedef std::array<std::string,3> blog_element;
typedef std::vector<blog_element> blog_t;
typedef cppcms::json::value json;

#define json_address  "configs/blog.json"
#define blog_address "data/blog/"
namespace blog_page_content{

	struct content: public cppcms::base_content{
        blog_t blog;
        json file_with_names;
        content(){
            std::ifstream file{json_address};
            if(!file.is_open()){std::cerr << "site: can't open file";}
            file >> this->file_with_names;
            file.close();

            auto vec = this->file_with_names.at("blog").array();
            for(auto&i:vec){
                auto i_ = i.array();
                std::string title,name_of_file, mini_text;
                title = i_.at(0).str();
                name_of_file = i_.at(1).str();
                mini_text = i_.at(2).str();
                blog.push_back({title, mini_text, name_of_file});
            }
            
        }

	};
    struct content_2 : public cppcms::base_content{
        std::string title{"undefined"},text{"undefined"};
        json js;
        content_2(std::string name_of_blog_element){
            std::ifstream file{json_address};
            if(!file.is_open()){std::cerr << "site: can't open file";}
            file >> this->js;
            file.close();
            auto vec = this->js.at("blog").array();
            for(auto&i:vec){
                auto i_ = i.array();
                std::string title,name_of_file,mini_text;
                title = i_.at(0).str();
                name_of_file = i_.at(1).str();
                mini_text = i_.at(2).str();
                if(title == name_of_blog_element){
                    this->title = title;
                    file.open(blog_address+ name_of_file);
                    std::string t_;
                    this->text = "";
                    while(file >> t_){this->text+=t_;}
                    break;
                }
            }
        }
    };
};
#endif
