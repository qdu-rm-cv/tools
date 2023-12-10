cmake_minimum_required(VERSION 3.0.0)

project(cali)

add_executable(${PROJECT_NAME} camera_calibration.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
    spdlog::spdlog
    ${OpenCV_LIBS}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)
