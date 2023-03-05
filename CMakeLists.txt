cmake_minimum_required(VERSION 3.0.0)
project(bing-bong-fsm VERSION 0.1.0)

# include(CTest)
# enable_testing()

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(bing-bong-fsm ${SRC_FILES})
target_include_directories(bing-bong-fsm PRIVATE ${PROJECT_SOURCE_DIR}/include)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
