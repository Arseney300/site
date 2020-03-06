LIB_FLAGS = -lcppcms -l cppdb -l booster
TMPL_SOURCE = default_page.tmpl
TMPL_CPP = $(TMPL_SOURCE:.tmpl=.cpp)
TMPL_OBJECTS = $(TMPL_CPP:.cpp=.o) $(MAIN_FILE:.cpp=.o)
MAIN_FILE = main.cpp

all:site


site:TMPL_OBJECTS
	g++-9 -std=c++17 -O3 $(TMPL_OBJECTS) $(LIB_FLAGS) -o site.out
	rm *.o
TMPL_OBJECTS: TMPL_CPP
	g++-9 -c -std=c++17 -O3 $(addprefix pages/,$(TMPL_CPP)) $(MAIN_FILE)
	rm pages/*.cpp
TMPL_CPP:
	cppcms_tmpl_cc tmpl/default_page.tmpl -o pages/default_page.cpp
