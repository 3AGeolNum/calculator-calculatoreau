cmake_minimum_required(VERSION 3.10)

project(CalculetteProject VERSION 2.23)

configure_file(cmake/CalculetteProject.h.in CalculetteProject.h)

add_subdirectory(src/calc_lib)

#about executable
option(CalculetteProject_WITH_EXECUTABLES "Compile mains" OFF)
if(CalculetteProject_WITH_EXECUTABLES)
	#enable testing with CTest
	message(STATUS "Configuring CalculetteProject with executables")
	add_subdirectory(mains)
endif()


#option(CalculetteProject_WITH_TESTS "Compile test projects" OFF)
#if(CalculetteProject_WITH_TESTS)
#enable_testing()
#message(STATUS "Configuring CalculetteProjectwithtests")
#add_subdirectory(tests)
#endif()