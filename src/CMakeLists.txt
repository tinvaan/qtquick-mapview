add_library(interpolator SHARED lineinterpolator.cpp)
target_link_libraries(interpolator
    Qt5::Core
    Qt5::Widgets
    Qt5::Positioning
)

qt5_add_resources(RESOURCES qml/mapview.qrc)
add_executable(mapview lineinterpolator.cpp main.cpp ${RESOURCES})
target_link_libraries(mapview
    Qt5::Core
    Qt5::Quick
    Qt5::Positioning
)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
