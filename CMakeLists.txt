cmake_minimum_required(VERSION 3.16)
project(SpaceShooter CXX)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML")

find_package(SFML 2.6 REQUIRED COMPONENTS graphics window system)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(SpaceShooter ${SOURCES})

target_link_libraries(SpaceShooter
    sfml-graphics
    sfml-window
    sfml-system
)

add_custom_command(TARGET SpaceShooter POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:SpaceShooter>/assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/fonts $<TARGET_FILE_DIR:SpaceShooter>/fonts)