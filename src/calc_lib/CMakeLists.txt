set(target_name calclib)
add_library(${target_name} STATIC "")

target_sources(${target_name}
PRIVATE
"${PROJECT_SOURCE_DIR}/src/calc_lib/lexer.cpp"
)

target_include_directories(${target_name}
PUBLIC
"${PROJECT_SOURCE_DIR}/include"
"${PROJECT_BINARY_DIR}"
)