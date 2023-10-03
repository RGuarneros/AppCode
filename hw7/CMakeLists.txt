cmake_minimum_required(VERSION 3.12)
project(hw7)

add_executable(hw7 hw7.cpp)

set(fmt_DIR "/Users/guarneros/mylibraries/installations/fmtlib/lib/cmake/fmt")
find_package(fmt REQUIRED)

target_link_libraries(hw7 fmt::fmt)
