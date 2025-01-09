cmake_minimum_required(VERSION 3.28...3.30)

find_package(Vulkan REQUIRED)

option(ENABLE_VULKAN_VIDEO "Build Vulkan Video Encoder Plugin" ON)

if(NOT ENABLE_VULKAN_VIDEO)
    target_disable_feature(obs-vkvideo "Vulkan Video Encoder")
    target_disable(obs-vkvideo)
    return()
endif()

if(NOT TARGET OBS::opts-parser)
    add_subdirectory("${CMAKE_SOURCE_DIR}/shared/opts-parser" "${CMAKE_BINARY_DIR}/shared/opts-parser")
endif()

add_library(obs-vkvideo MODULE)
add_library(OBS::vkvideo ALIAS obs-vkvideo)

target_sources(
        obs-vkvideo
        PRIVATE
        obs-vkvideo.c
        obs-vkvideo.h
)

target_link_libraries(
        obs-vkvideo
        PRIVATE OBS::libobs OBS::opts-parser
)

set_target_properties_obs(obs-vkvideo PROPERTIES FOLDER plugins/obs-vkvideo PREFIX "")
