import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    id: window
    width: 420
    height: 680
    visible: true
    title: qsTr("Qt Weather App")

    // Use system font
    font.family: Qt.application.font.family

    // Custom colors
    property color primaryColor: "#1976D2"
    property color accentColor: "#03A9F4"
    property color textColor: "#212121"
    property color lightTextColor: "#757575"
    property color backgroundColor: "#F5F5F5"
    property color cardColor: "#FFFFFF"

    // Global properties
    property bool isSettingsOpen: false

    // Initial component to ensure StackView has a valid item
    Component {
        id: initialPageComponent

        Rectangle {
            color: window.backgroundColor

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 20
                spacing: 20

                Rectangle {
                    Layout.fillWidth: true
                    height: 60
                    color: window.primaryColor
                    radius: 8

                    RowLayout {
                        anchors.fill: parent
                        anchors.leftMargin: 16
                        anchors.rightMargin: 16

                        Text {
                            Layout.fillWidth: true
                            text: "Qt Weather App"
                            color: "white"
                            font.pixelSize: 22
                            font.bold: true
                        }

                        Button {
                            text: "Settings"
                            flat: true

                            contentItem: Text {
                                text: parent.text
                                color: "white"
                                font.pixelSize: 14
                            }

                            background: Rectangle {
                                color: "transparent"
                            }

                            onClicked: window.showSettings()
                        }
                    }
                }

                // Search field
                RowLayout {
                    Layout.fillWidth: true
                    spacing: 8

                    TextField {
                        id: cityInput
                        Layout.fillWidth: true
                        placeholderText: "Enter city name"

                        background: Rectangle {
                            implicitHeight: 40
                            radius: 4
                            border.color: "#E0E0E0"
                            border.width: 1
                        }
                    }

                    Button {
                        text: "Search"

                        contentItem: Text {
                            text: parent.text
                            color: "white"
                            font.pixelSize: 14
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }

                        background: Rectangle {
                            implicitWidth: 80
                            implicitHeight: 40
                            color: window.primaryColor
                            radius: 4
                        }

                        onClicked: {
                            if (cityInput.text.trim() !== "") {
                                weatherApi.getCurrentWeather(cityInput.text.trim())
                            }
                        }
                    }
                }

                // Loading indicator
                BusyIndicator {
                    Layout.alignment: Qt.AlignCenter
                    running: weatherApi.loading
                    visible: weatherApi.loading
                }

                // Error message
                Text {
                    Layout.fillWidth: true
                    text: weatherApi.errorMessage
                    color: "red"
                    visible: weatherApi.errorMessage !== ""
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.WordWrap
                }

                // Weather data display - only visible when we have data
                Item {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    visible: weatherApi.currentWeather.location !== ""

                    ColumnLayout {
                        anchors.fill: parent
                        spacing: 16

                        Loader {
                            id: weatherCardLoader
                            Layout.fillWidth: true
                            Layout.preferredHeight: 200
                            source: "qrc:/qml/WeatherCard.qml"
                        }

                        Loader {
                            id: weatherDetailsLoader
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            source: "qrc:/qml/WeatherDetails.qml"
                        }
                    }
                }

                // Placeholder when no data is available
                Item {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    visible: weatherApi.currentWeather.location === "" && !weatherApi.loading

                    Column {
                        anchors.centerIn: parent
                        spacing: 20

                        Text {
                            text: "No Weather Data"
                            font.pixelSize: 24
                            color: window.lightTextColor
                            anchors.horizontalCenter: parent.horizontalCenter
                        }

                        Text {
                            text: "Search for a city to get weather information"
                            color: window.lightTextColor
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }
                }
            }
        }
    }

    // Component for settings page
    Component {
        id: settingsPageComponent

        Rectangle {
            color: window.backgroundColor

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 20
                spacing: 20

                Rectangle {
                    Layout.fillWidth: true
                    height: 60
                    color: window.primaryColor
                    radius: 8

                    RowLayout {
                        anchors.fill: parent
                        anchors.leftMargin: 16
                        anchors.rightMargin: 16

                        Button {
                            text: "Back"
                            flat: true

                            contentItem: Text {
                                text: parent.text
                                color: "white"
                                font.pixelSize: 14
                            }

                            background: Rectangle {
                                color: "transparent"
                            }

                            onClicked: window.showWeather()
                        }

                        Text {
                            Layout.fillWidth: true
                            text: "Settings"
                            color: "white"
                            font.pixelSize: 22
                            font.bold: true
                            horizontalAlignment: Text.AlignHCenter
                        }
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: window.cardColor
                    radius: 8
                    border.color: "#E0E0E0"
                    border.width: 1

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 20
                        spacing: 20

                        Text {
                            text: "API Key Settings"
                            font.pixelSize: 18
                            font.bold: true
                            color: window.textColor
                        }

                        Text {
                            text: "Enter your OpenWeatherMap API key"
                            font.pixelSize: 14
                            color: window.lightTextColor
                            Layout.fillWidth: true
                            wrapMode: Text.WordWrap
                        }

                        TextField {
                            Layout.fillWidth: true
                            placeholderText: "Your API Key"
                            id: apiKeyField

                            background: Rectangle {
                                implicitHeight: 40
                                radius: 4
                                border.color: "#E0E0E0"
                                border.width: 1
                            }
                        }

                        Text {
                            text: "Default City"
                            font.pixelSize: 18
                            font.bold: true
                            color: window.textColor
                            Layout.topMargin: 10
                        }

                        Text {
                            text: "City to load when app starts"
                            font.pixelSize: 14
                            color: window.lightTextColor
                            Layout.fillWidth: true
                            wrapMode: Text.WordWrap
                        }

                        TextField {
                            Layout.fillWidth: true
                            placeholderText: "City name"
                            id: defaultCityField

                            background: Rectangle {
                                implicitHeight: 40
                                radius: 4
                                border.color: "#E0E0E0"
                                border.width: 1
                            }
                        }

                        Item {
                            Layout.fillHeight: true
                        }

                        RowLayout {
                            Layout.fillWidth: true
                            spacing: 16

                            Button {
                                Layout.fillWidth: true
                                text: "Cancel"

                                contentItem: Text {
                                    text: parent.text
                                    font.pixelSize: 14
                                    color: window.textColor
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                }

                                background: Rectangle {
                                    implicitHeight: 48
                                    color: "#E0E0E0"
                                    radius: 4
                                }

                                onClicked: window.showWeather()
                            }

                            Button {
                                Layout.fillWidth: true
                                text: "Save"

                                contentItem: Text {
                                    text: parent.text
                                    font.pixelSize: 14
                                    color: "white"
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                }

                                background: Rectangle {
                                    implicitHeight: 48
                                    color: window.primaryColor
                                    radius: 4
                                }

                                onClicked: {
                                    // Save settings
                                    if (apiKeyField.text.trim() !== "") {
                                        weatherApi.setApiKey(apiKeyField.text.trim())
                                    }

                                    // Get weather for default city if specified
                                    if (defaultCityField.text.trim() !== "") {
                                        weatherApi.getCurrentWeather(defaultCityField.text.trim())
                                    }

                                    // Go back to weather page
                                    window.showWeather()
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Stack view for navigation
    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: initialPageComponent
    }

    // Show settings
    function showSettings() {
        stackView.push(settingsPageComponent)
        isSettingsOpen = true
    }

    // Return to weather page
    function showWeather() {
        if (stackView.depth > 1) {
            stackView.pop()
        }
        isSettingsOpen = false
    }
}
