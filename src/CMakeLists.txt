cmake_minimum_required(VERSION 3.0.0)
 
project(examples)
 
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -pthread")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

#设置源文件目录
set(SRC_ROOT_PATH IO)
#MESSAGE("SRC_ROOT_PATH: "${SRC_ROOT_PATH})
file(GLOB APP_SOURCES "${SRC_ROOT_PATH}/*.c")

foreach( sourcefile IN LISTS APP_SOURCES )
    STRING( REGEX REPLACE "^.*/" "" basename ${sourcefile} )
    STRING( REGEX REPLACE ".c$" "" out ${basename} )
    add_executable( ${out} ${sourcefile} )
endforeach( sourcefile )