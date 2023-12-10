cmake_minimum_required(VERSION 3.5)
project(camera_lib)

file(GLOB ${PROJECT_NAME}_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCES})

target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    MvCameraControl
    Threads::Threads
    spdlog::spdlog
)

target_link_directories(${PROJECT_NAME} PUBLIC 
    if (CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
        /opt/MVS/lib/aarch64/
    else()
        /opt/MVS/lib/64/
    endif()
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    /opt/MVS/include
)

