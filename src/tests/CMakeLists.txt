include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(interpolation interpolation.cpp)
target_link_libraries(interpolation
    Qt5::Core
    Qt5::Widgets
    Qt5::Positioning
    interpolator
)
