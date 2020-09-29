set(target_name calclib)
add_library(${target_name} STATIC "")

target_sources(${target_name}
PRIVATE
"${PROJECT_SOURCE_DIR}/src/calc_lib/lexer.cpp"
"${PROJECT_SOURCE_DIR}/src/calc_lib/bloc.cpp"
"${PROJECT_SOURCE_DIR}/include/calc_lib/parser.cpp"
#"${PROJECT_SOURCE_DIR}/src/calc_lib/DynArray.cpp"
PRIVATE
"${PROJECT_SOURCE_DIR}/include/calc_lib/lexer.h"
"${PROJECT_SOURCE_DIR}/include/calc_lib/bloc.h"
"${PROJECT_SOURCE_DIR}/include/calc_lib/DynArray.h"
"${PROJECT_SOURCE_DIR}/include/calc_lib/parser.h"
)

target_include_directories(${target_name}
PUBLIC
"${PROJECT_SOURCE_DIR}/include"
"${PROJECT_BINARY_DIR}"
)