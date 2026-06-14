cmake_minimum_required(VERSION 4.1)
project(raytracing)

set(CMAKE_CXX_STANDARD 20)

add_executable(raytracing main.cpp
        vec3.h
        color.h
        ray.h
        hittable.h
        sphere.h
        hittable_list.h
        utils.h
        camera.h)

# Build the raytracer and render the image in one step.
# Usage: cmake --build <build-dir> --target render
add_custom_target(render
        COMMAND raytracing > ${CMAKE_SOURCE_DIR}/image.ppm
        DEPENDS raytracing
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Building raytracer and rendering to image.ppm")


