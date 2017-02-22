cmake_minimum_required(VERSION 3.5)
project(Raytracer)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

set(root_src_dir ${CMAKE_SOURCE_DIR})
set(rt_inc_dir ${root_src_dir}/include)
set(rt_src_dir ${root_src_dir}/sources)
set(parser_src_dir ${root_src_dir}/parser)
set(online_src_dir ${root_src_dir}/online)
set(mlx_dir ${root_src_dir}/minilibx)

include_directories(${rt_inc_dir})

file(GLOB rt_headers ${rt_inc_dir}/*.h)
file(GLOB rt_sources ${rt_src_dir}/*.c)
file(GLOB parser_sources ${parser_src_dir}/*.c)
file(GLOB online_sources ${online_src_dir}/*.c)

set(SOURCE_FILES
        ${rt_headers}
        ${rt_sources}
        ${parser_sources}
        ${online_sources}
        ${other_sources})

add_executable(Raytracer ${SOURCE_FILES})
target_link_libraries(Raytracer -L ${mlx_dir} m X11 mlx Xext pthread openmp)