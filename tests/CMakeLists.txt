if(NOT TARGET calclib)
  project(CalculetteProject VERSION 1.0)
  find_package(CalculetteProject REQUIRED CONFIG)
  enable_testing()
endif()

add_executable(test_lexer test_lexer.cpp)
target_link_libraries(test_lexer PUBLIC calclib)
add_test(NAME test_lexer COMMAND test_lexer)