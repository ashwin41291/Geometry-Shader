
cmake_minimum_required(VERSION 3.6)
project(GeometryShader)
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 11)

#set (CMAKE_EXE_LINKER_FLAGS "-lglfw3 -framework OpenGL -framework cocoa -framework IOKit -framework CoreVideo -lSOIL")
#set (GCC_COVERAGE_LINK_FLAGS "-lglfw3 -framework OpenGL -framework cocoa -framework IOKit -framework CoreVideo")
find_package(OpenGL REQUIRED)

if (OPENGL_FOUND)
    MESSAGE(STATUS "OPENGL founds")
    link_directories(${OPENGL_LIBRARY_DIRS})
    include_directories(${OPENGL_INCLUDE_DIR}
            ${GLFW_INCLUDE_DIRS})
endif (OPENGL_FOUND)

include_directories(./include)
set(SOURCE_FILES

        gl3w.c
        LoadShaders.cpp
        geometryshader.cpp
        triangles2.geom
        points2.geom
        lines.geom
        lines2.geom
        points.geom
        triangles.geom
        geometry.frag
        geometry.vert
        triangle2.frag
        triangle2.vert)
link_directories(./include)
add_executable(GeometryShader ${SOURCE_FILES})


find_package(OpenGL REQUIRED)


set(INCLUDE_DIRS "./include" CACHE PATH "" FORCE)
set(INCLUDE_DIRS "./data" CACHE PATH "" FORCE)

set(LOCAL_INCLUDE "/usr/local/include" CACHE PATH "" FORCE)

find_library(COCOA_LIBRARY Cocoa)
find_library(IOKIT NAMES IOKit)
find_library(COREVIDEO_LIB NAMES CoreVideo)

include_directories( ${INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${LOCAL_INCLUDE})
target_link_libraries(GeometryShader ${OPENGL_LIBRARIES} ${COCOA_LIBRARY} ${IOKIT} ${COREVIDEO_LIB} glfw)
configure_file(geometry.vert ${CMAKE_CURRENT_BINARY_DIR}/geometry.vert COPYONLY)
configure_file(geometry.frag ${CMAKE_CURRENT_BINARY_DIR}/geometry.frag COPYONLY)
configure_file(triangle2.frag ${CMAKE_CURRENT_BINARY_DIR}/triangle2.frag COPYONLY)
configure_file(triangle2.vert ${CMAKE_CURRENT_BINARY_DIR}/triangle2.vert COPYONLY)
configure_file(triangles2.geom ${CMAKE_CURRENT_BINARY_DIR}/triangles2.geom COPYONLY)
configure_file(triangles.geom ${CMAKE_CURRENT_BINARY_DIR}/triangles.geom COPYONLY)
configure_file(points.geom ${CMAKE_CURRENT_BINARY_DIR}/points.geom COPYONLY)
configure_file(points2.geom ${CMAKE_CURRENT_BINARY_DIR}/points2.geom COPYONLY)
configure_file(lines.geom ${CMAKE_CURRENT_BINARY_DIR}/lines.geom COPYONLY)
configure_file(lines2.geom ${CMAKE_CURRENT_BINARY_DIR}/lines2.geom COPYONLY)
