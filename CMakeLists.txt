cmake_minimum_required(VERSION 3.0.0)
project(rnd VERSION 0.1.0)

include(CTest)
enable_testing()

set(SFML_DIR "libs/SFML-2.5.1-64-windows/lib/cmake/SFML/")
find_package(SFML 2.5.1 COMPONENTS system REQUIRED)

add_executable(rnd main.cpp)
target_link_libraries(${PROJECT_NAME} sfml-system)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
