cmake_minimum_required(VERSION 3.6)
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
project(geotest)


set(CMAKE_CXX_STANDARD 11)
#set (CMAKE_EXE_LINKER_FLAGS "-lglfw3 -framework OpenGL -framework cocoa -framework IOKit -framework CoreVideo")
#set (GCC_COVERAGE_LINK_FLAGS "-lglfw3 -framework OpenGL -framework cocoa -framework IOKit -framework CoreVideo")
find_package(OpenGL REQUIRED)

if (OPENGL_FOUND)
    MESSAGE(STATUS "OPENGL founds")
    link_directories(${OPENGL_LIBRARY_DIRS})
    include_directories(${OPENGL_INCLUDE_DIR}
            ${GLFW_INCLUDE_DIRS})
endif (OPENGL_FOUND)

set(SOURCE_FILES

        gl3w.c
        LoadShaders.cpp
        viewer.cpp
        loadObj.cpp
        BlinnPhong.vert
        BlinnPhong.frag
        ReadScene.cpp
        ReadScene.h)
add_executable(geotest ${SOURCE_FILES})


find_package(OpenGL REQUIRED)


set(INCLUDE_DIRS "./include" CACHE PATH "" FORCE)
set(INCLUDE_DIRS "./data" CACHE PATH "" FORCE)

set(LOCAL_INCLUDE "/usr/local/include" CACHE PATH "" FORCE)

find_library(COCOA_LIBRARY Cocoa)
find_library(IOKIT NAMES IOKit)
find_library(COREVIDEO_LIB NAMES CoreVideo)

include_directories( ${INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${LOCAL_INCLUDE})
target_link_libraries(geotest ${OPENGL_LIBRARIES} ${COCOA_LIBRARY} ${IOKIT} ${COREVIDEO_LIB} glfw)
configure_file(BlinnPhong.vert ${CMAKE_CURRENT_BINARY_DIR}/BlinnPhong.vert COPYONLY)
configure_file(BlinnPhong.frag ${CMAKE_CURRENT_BINARY_DIR}/BlinnPhong.frag COPYONLY)
configure_file(geometry.geom ${CMAKE_CURRENT_BINARY_DIR}/geometry.geom COPYONLY)
