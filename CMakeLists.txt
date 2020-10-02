cmake_minimum_required(VERSION 3.10)

project(CalculetteProject VERSION 2.23)

configure_file(cmake/CalculetteProjectConfig.h.in CalculetteProjectConfig.h)

add_subdirectory(src/calc_lib)

#about executable
option(CalculetteProject_WITH_EXECUTABLES "Compile mains" OFF)
if(CalculetteProject_WITH_EXECUTABLES)
	message(STATUS "Configuring CalculetteProject with executables")
	add_subdirectory(mains)
endif()


option(CalculetteProject_WITH_TESTS "Compile test projects" OFF)
if(CalculetteProject_WITH_TESTS)
	enable_testing()
	message(STATUS "Configuring CalculetteProjectwithtests")
	add_subdirectory(tests)
endif()

include(CMakePackageConfigHelpers)
configure_package_config_file(
	cmake/CalculetteProjectConfig.cmake.in 
	CalculetteProjectCongfig.cmake
	INSTALL_DESTINATION ${PROJECT_BINARY_DIR}
)


install(FILES ${PROJECT_BINARY_DIR}/CalculetteProjectCongfig.cmake DESTINATION ${PROJECT_BINARY_DIR}/install/cmake/ )