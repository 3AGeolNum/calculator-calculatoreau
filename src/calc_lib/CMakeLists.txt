set(target_name calclib)
add_library(${target_name} STATIC "")

target_sources(${target_name}
PRIVATE
"${PROJECT_SOURCE_DIR}/src/calc_lib/lexer.cpp"
"${PROJECT_SOURCE_DIR}/src/calc_lib/bloc.cpp"
PRIVATE
"${PROJECT_SOURCE_DIR}/include/calc_lib/lexer.h"
"${PROJECT_SOURCE_DIR}/include/calc_lib/bloc.h"
"${PROJECT_SOURCE_DIR}/include/calc_lib/DynArray.h"
)

target_include_directories(${target_name}
PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
	$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
	$<INSTALL_INTERFACE:include>
)

export(TARGETS ${target_name}
	FILE ${PROJECT_BINARY_DIR}/${target_name}_target.cmake
)

install(TARGETS ${target_name} EXPORT ${target_name} DESTINATION ${PROJECT_BINARY_DIR}/install/lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION ${PROJECT_BINARY_DIR}/install/include/ )

install(EXPORT ${target_name} FILE calclib_target.cmake DESTINATION ${PROJECT_BINARY_DIR}/install/cmake/)
