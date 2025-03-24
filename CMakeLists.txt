cmake_minimum_required(VERSION 3.14)

project(QtWeatherApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Try to find Qt6 first, but don't require it
find_package(Qt6 COMPONENTS Quick Core Network QuickControls2)
if(Qt6_FOUND)
    message(STATUS "Building with Qt6")
else()
    message(STATUS "Qt6 not found, trying Qt5")
    find_package(Qt5 COMPONENTS Quick Core Network QuickControls2 REQUIRED)
endif()

# Define sources
set(SOURCES
    src/main.cpp
    src/weatherapi.h
    src/weatherapi.cpp
    src/weatherdata.h
    src/weatherdata.cpp
)

# Create the resource file
file(WRITE ${CMAKE_BINARY_DIR}/resources.qrc
"<!DOCTYPE RCC>
<RCC version=\"1.0\">
    <qresource prefix=\"/qml\">
        <file alias=\"main.qml\">${CMAKE_CURRENT_SOURCE_DIR}/qml/main.qml</file>
        <file alias=\"WeatherPage.qml\">${CMAKE_CURRENT_SOURCE_DIR}/qml/WeatherPage.qml</file>
        <file alias=\"SearchBar.qml\">${CMAKE_CURRENT_SOURCE_DIR}/qml/SearchBar.qml</file>
        <file alias=\"WeatherDetails.qml\">${CMAKE_CURRENT_SOURCE_DIR}/qml/WeatherDetails.qml</file>
        <file alias=\"WeatherCard.qml\">${CMAKE_CURRENT_SOURCE_DIR}/qml/WeatherCard.qml</file>
        <file alias=\"SettingsPage.qml\">${CMAKE_CURRENT_SOURCE_DIR}/qml/SettingsPage.qml</file>
    </qresource>
    <qresource prefix=\"/icons\">
        <file alias=\"sunny.png\">${CMAKE_CURRENT_SOURCE_DIR}/src/resources/icons/sunny.png</file>
        <file alias=\"cloudy.png\">${CMAKE_CURRENT_SOURCE_DIR}/src/resources/icons/cloudy.png</file>
        <file alias=\"rainy.png\">${CMAKE_CURRENT_SOURCE_DIR}/src/resources/icons/rainy.png</file>
        <file alias=\"snowy.png\">${CMAKE_CURRENT_SOURCE_DIR}/src/resources/icons/snowy.png</file>
    </qresource>
</RCC>")

# Add executable with resources
if(Qt6_FOUND)
    qt_add_resources(RESOURCES ${CMAKE_BINARY_DIR}/resources.qrc)
else()
    qt5_add_resources(RESOURCES ${CMAKE_BINARY_DIR}/resources.qrc)
endif()

add_executable(QtWeatherApp ${SOURCES} ${RESOURCES})

# Include directories
target_include_directories(QtWeatherApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Link Qt libraries
if(Qt6_FOUND)
    target_link_libraries(QtWeatherApp PRIVATE
        Qt::Core
        Qt::Quick
        Qt::Network
        Qt::QuickControls2
    )
else()
    target_link_libraries(QtWeatherApp PRIVATE
        Qt5::Core
        Qt5::Quick
        Qt5::Network
        Qt5::QuickControls2
    )
endif()

# Install
install(TARGETS QtWeatherApp DESTINATION bin)

# Create necessary directories
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/icons)

# Make sure icon directories exist
message(STATUS "Creating icon directories if needed...")
