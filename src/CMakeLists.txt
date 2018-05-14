add_library(interpolator SHARED lineinterpolator.cpp)
target_link_libraries(interpolator
    Qt5::Core
    Qt5::Widgets
    Qt5::Positioning
)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
