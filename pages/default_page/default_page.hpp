/*
 * @project site
 * @file default_page.hpp
 * @author Soundwave
 * @date Mar 6, 2020
 * @brief default page data
 * */


#ifndef default_page_h
#define default_page_h
#include <cppcms/view.h>
#include <string>
#include <cppcms/form.h>
#include <utility>
namespace default_page_content{

	struct content: public cppcms::base_content{
		std::string_view text = "I am studend of the Russian's lyceum. I have been studying programming for ~4 years. I like c/c++ languages and linux. There are books, guides, manuals about programming in this site. I try to collect and structure all useful information, that i find.";
	};
};
#endif
