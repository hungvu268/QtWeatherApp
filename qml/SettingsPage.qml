import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
// import QtGraphicalEffects 1.15 // Commented out to reduce dependencies
import Qt.labs.settings 1.0

Page {
    id: settingsPage

    // Store settings
    Settings {
        id: appSettings
        property string apiKey: "YOUR_API_KEY"
        // property string apiKey: "96d813439905e612339e195a31fc5212"
        property string defaultCity: "London"
        property string tempUnit: "celsius" // "celsius" or "fahrenheit"
    }

    // Apply settings when component is loaded
    Component.onCompleted: {
        apiKeyField.text = appSettings.apiKey
        defaultCityField.text = appSettings.defaultCity
        tempUnitCombo.currentIndex = appSettings.tempUnit === "celsius" ? 0 : 1
    }

    // Header with back button
    header: ToolBar {
        height: 56

        background: Rectangle {
            color: window.primaryColor
        }

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: 16
            anchors.rightMargin: 16

            // Back button
            ToolButton {
                Layout.preferredWidth: 40
                Layout.preferredHeight: 40

                contentItem: Image {
                    source: "data:image/svg+xml;utf8,<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='white'><path d='M20 11H7.83l5.59-5.59L12 4l-8 8 8 8 1.41-1.41L7.83 13H20v-2z'/></svg>"
                    fillMode: Image.PreserveAspectFit
                }

                onClicked: window.showWeather()
            }

            Label {
                text: "Settings"
                color: "white"
                font.pixelSize: 20
                font.bold: true
                Layout.fillWidth: true
            }
        }
    }

    // Content
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 24

        // API Key settings
        ColumnLayout {
            Layout.fillWidth: true
            spacing: 8

            Label {
                text: "OpenWeatherMap API Key"
                font.pixelSize: 16
                font.bold: true
                color: window.textColor
            }

            Label {
                text: "Enter your API key from OpenWeatherMap.org"
                font.pixelSize: 14
                color: window.lightTextColor
                Layout.fillWidth: true
                wrapMode: Text.WordWrap
            }

            TextField {
                id: apiKeyField
                Layout.fillWidth: true
                placeholderText: "Your API Key"
                selectByMouse: true

                background: Rectangle {
                    implicitHeight: 40
                    color: "transparent"
                    border.color: apiKeyField.activeFocus ? window.accentColor : "#E0E0E0"
                    border.width: 1
                    radius: 4
                }
            }
        }

        // Default City
        ColumnLayout {
            Layout.fillWidth: true
            spacing: 8

            Label {
                text: "Default City"
                font.pixelSize: 16
                font.bold: true
                color: window.textColor
            }

            Label {
                text: "City to load when app starts"
                font.pixelSize: 14
                color: window.lightTextColor
            }

            TextField {
                id: defaultCityField
                Layout.fillWidth: true
                placeholderText: "City name"
                selectByMouse: true

                background: Rectangle {
                    implicitHeight: 40
                    color: "transparent"
                    border.color: defaultCityField.activeFocus ? window.accentColor : "#E0E0E0"
                    border.width: 1
                    radius: 4
                }
            }
        }

        // Temperature Unit
        ColumnLayout {
            Layout.fillWidth: true
            spacing: 8

            Label {
                text: "Temperature Unit"
                font.pixelSize: 16
                font.bold: true
                color: window.textColor
            }

            ComboBox {
                id: tempUnitCombo
                Layout.fillWidth: true
                model: ["Celsius (°C)", "Fahrenheit (°F)"]

                background: Rectangle {
                    implicitHeight: 40
                    color: "transparent"
                    border.color: "#E0E0E0"
                    border.width: 1
                    radius: 4
                }
            }
        }

        // App information
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: infoLayout.implicitHeight + 32
            color: Qt.rgba(0, 0.6, 0.9, 0.1)
            radius: 8

            ColumnLayout {
                id: infoLayout
                anchors.fill: parent
                anchors.margins: 16
                spacing: 8

                Label {
                    text: "About Qt Weather App"
                    font.pixelSize: 16
                    font.bold: true
                    color: window.textColor
                }

                Label {
                    text: "Version 1.0"
                    font.pixelSize: 14
                    color: window.lightTextColor
                }

                Label {
                    text: "A simple weather application built with Qt and QML"
                    font.pixelSize: 14
                    color: window.lightTextColor
                    Layout.fillWidth: true
                    wrapMode: Text.WordWrap
                }

                Label {
                    text: "Weather data provided by OpenWeatherMap.org"
                    font.pixelSize: 14
                    color: window.lightTextColor
                    Layout.fillWidth: true
                    wrapMode: Text.WordWrap
                }
            }
        }

        Item {
            Layout.fillHeight: true
        }

        // Save and cancel buttons
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
                    appSettings.apiKey = apiKeyField.text
                    appSettings.defaultCity = defaultCityField.text
                    appSettings.tempUnit = tempUnitCombo.currentIndex === 0 ? "celsius" : "fahrenheit"

                    // Apply API key
                    weatherApi.setApiKey(apiKeyField.text)

                    // Get weather for default city if needed
                    if (weatherApi.currentWeather.location === "") {
                        weatherApi.getCurrentWeather(defaultCityField.text)
                    }

                    // Go back to weather page
                    window.showWeather()
                }
            }
        }
    }
}
