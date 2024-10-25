project(leetcode_cpp_ds)

include_directories(include)

set(LIB_HEADERS
        include/list/list_node.hpp
        include/list/dlist_node.hpp
        include/list/utils/list_utils.hpp
        include/tree/tree_node.hpp
        include/tree/tree_parent_node.hpp
        include/exceptions/not_implemented.hpp
)

set(LIB_SOURCES
        impl/exceptions/not_implemented.cpp
)

add_library(${PROJECT_NAME} STATIC ${LIB_HEADERS} ${LIB_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)