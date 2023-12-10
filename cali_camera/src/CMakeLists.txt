cmake_minimum_required(VERSION 3.0.0)

#---------------------------------------------------------------------------------------
# General Components
#---------------------------------------------------------------------------------------

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/include/camera)

#---------------------------------------------------------------------------------------
# Applications
#---------------------------------------------------------------------------------------

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/app/cali)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/app/camera)
