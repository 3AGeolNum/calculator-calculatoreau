#add the executable

add_executable(main_calculette main.cpp)
target_link_libraries(main_calculette PRIVATE calclib)