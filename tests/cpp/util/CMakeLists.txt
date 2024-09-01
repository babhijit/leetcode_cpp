project(leetcode_cpp_tests_util)

find_package(Boost COMPONENTS json REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

include_directories(include)


set(RES_HEADERS
        include/comp/list/list_comparator.hpp
        include/comp/list/dlist_comparator.hpp
        include/comp/stl/stl_compare_utils.hpp
        include/res/test_resource_utils.hpp
        include/res/json/mapper/mapper.hpp
        include/res/json/json_parser.hpp
        include/res/json/mapper/bst_mapper.hpp
)

set(RES_SOURCES
       impl/res/test_resource_utils.cpp
)

set(LOADER_HEADERS
        include/loader/base_loader.hpp
        include/loader/json_loader.hpp
        include/loader/test_case_loader.hpp
        include/loader/tree/load_bst.hpp
        include/loader/arrays/load_int_array.hpp
        include/loader/arrays/load_t_array.hpp
        include/loader/arrays/load_int_matrix.hpp
        include/loader/arrays/load_t_matrix.hpp
        include/comp/list/list_comparator.hpp
        include/comp/list/dlist_comparator.hpp
)

set(LOADER_SOURCES impl/loader/base_loader.cpp
        impl/loader/json_loader.cpp
        impl/loader/tree/load_bst.cpp
        impl/loader/test_case_loader.cpp
        impl/loader/arrays/load_int_array.cpp
        impl/loader/arrays/load_int_matrix.cpp
)

set(TEST_UTIL_HEADERS ${RES_HEADERS} ${LOADER_HEADERS})

set(TEST_UTIL_SOURCES ${RES_SOURCES} ${LOADER_SOURCES}
        include/loader/list/load_int_list.hpp
        impl/loader/list/load_int_list.cpp
        include/loader/list/load_int_dlist.hpp
        impl/loader/list/load_int_dlist.cpp)

add_library(${PROJECT_NAME} STATIC ${TEST_UTIL_HEADERS} ${TEST_UTIL_SOURCES})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES}
        leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)