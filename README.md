### Mescheryakov Arseney`s site
---
### DEPENDENCIES:

```cppcms, cppdb, booster, mysql, gcc-8 and later, cmake, make, boost```
    
---
### INSTALLATION AND RUN
```git clone http://github.com/Arseney300/site && make && ./site.out -c configs/main_config.json```

---
### HOW TO SETUP BLOG
make automatically create  empty json config: ``` configs/blog.json ```, which have signature: ```{ "blog": ["title","name_of_file_with_text","preview_text"],["title2","name_of_file_with_text2","preview_text2"]....  }``` and create ```data/blog/``` directory, where you need to create files (f.e. name_of_file_with_text, name_of_file_with_text2), which will have text of blog pages.
