if(NOT TARGET calclib)
  project(CalculetteProject VERSION 1.0)
  find_package(CalculetteProject REQUIRED CONFIG)
  enable_testing()
endif()

add_executable(test_checker test_checker.cpp)
target_link_libraries(test_checker PUBLIC calclib)
add_test(NAME test_checker COMMAND test_checker)

add_executable(test_lexer test_lexer.cpp)
target_link_libraries(test_lexer PUBLIC calclib)
add_test(NAME test_lexer COMMAND test_lexer)

add_executable(test_parser test_parser.cpp)
target_link_libraries(test_parser PUBLIC calclib)
add_test(NAME test_parser COMMAND test_parser)

add_executable(test_evaluator test_evaluator.cpp)
target_link_libraries(test_evaluator PUBLIC calclib)
add_test(NAME test_evaluator COMMAND test_evaluator)