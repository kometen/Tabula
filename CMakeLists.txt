cmake_minimum_required(VERSION 3.2.3)
project(Tabula)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

    include_directories(/opt/local/include)
    link_libraries(/opt/local/lib/libboost_system-mt.dylib)
    link_libraries(/opt/local/lib/libboost_coroutine-mt.dylib)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11")

    include_directories(/usr/local/include)
    link_libraries(/usr/local/lib/libboost_system.so)
    link_libraries(/usr/local/lib/libboost_coroutine.so)
endif()

set(SOURCE_FILES main.cpp Button.cpp Button.h Input.cpp Input.h Html.cpp Html.h Form.cpp Form.h Content.cpp Content.h URLrecode.cpp URLrecode.h Script.cpp Script.h Link.cpp Link.h Div.cpp Div.h)
add_executable(Tabula ${SOURCE_FILES})
