# CMake generated Testfile for 
# Source directory: O:/Documents/ENSG_3A/Projet_calculette/Clonage/tests
# Build directory: O:/Documents/ENSG_3A/Projet_calculette/Clonage/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(test_lexer "O:/Documents/ENSG_3A/Projet_calculette/Clonage/build/tests/Debug/test_lexer.exe")
  set_tests_properties(test_lexer PROPERTIES  _BACKTRACE_TRIPLES "O:/Documents/ENSG_3A/Projet_calculette/Clonage/tests/CMakeLists.txt;9;add_test;O:/Documents/ENSG_3A/Projet_calculette/Clonage/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(test_lexer "O:/Documents/ENSG_3A/Projet_calculette/Clonage/build/tests/Release/test_lexer.exe")
  set_tests_properties(test_lexer PROPERTIES  _BACKTRACE_TRIPLES "O:/Documents/ENSG_3A/Projet_calculette/Clonage/tests/CMakeLists.txt;9;add_test;O:/Documents/ENSG_3A/Projet_calculette/Clonage/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(test_lexer "O:/Documents/ENSG_3A/Projet_calculette/Clonage/build/tests/MinSizeRel/test_lexer.exe")
  set_tests_properties(test_lexer PROPERTIES  _BACKTRACE_TRIPLES "O:/Documents/ENSG_3A/Projet_calculette/Clonage/tests/CMakeLists.txt;9;add_test;O:/Documents/ENSG_3A/Projet_calculette/Clonage/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(test_lexer "O:/Documents/ENSG_3A/Projet_calculette/Clonage/build/tests/RelWithDebInfo/test_lexer.exe")
  set_tests_properties(test_lexer PROPERTIES  _BACKTRACE_TRIPLES "O:/Documents/ENSG_3A/Projet_calculette/Clonage/tests/CMakeLists.txt;9;add_test;O:/Documents/ENSG_3A/Projet_calculette/Clonage/tests/CMakeLists.txt;0;")
else()
  add_test(test_lexer NOT_AVAILABLE)
endif()
