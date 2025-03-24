import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: root
    radius: 12
    color: window.cardColor
    border.color: "#E0E0E0"
    border.width: 1

    // Get the weather data from the API
    property var weatherData: weatherApi.currentWeather

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 16

        Label {
            text: "Weather Details"
            font.pixelSize: 18
            font.bold: true
            color: window.textColor
        }

        // Weather details grid
        GridLayout {
            Layout.fillWidth: true
            columns: 2
            rowSpacing: 20
            columnSpacing: 20

            // Humidity
            ColumnLayout {
                Layout.fillWidth: true
                spacing: 2

                Label {
                    text: "Humidity"
                    font.pixelSize: 14
                    color: window.lightTextColor
                }

                Label {
                    text: weatherData.humidity + "%"
                    font.pixelSize: 16
                    font.bold: true
                    color: window.textColor
                }
            }

            // Wind speed
            ColumnLayout {
                Layout.fillWidth: true
                spacing: 2

                Label {
                    text: "Wind Speed"
                    font.pixelSize: 14
                    color: window.lightTextColor
                }

                Label {
                    text: weatherData.windSpeed + " m/s"
                    font.pixelSize: 16
                    font.bold: true
                    color: window.textColor
                }
            }

            // Wind direction
            ColumnLayout {
                Layout.fillWidth: true
                spacing: 2

                Label {
                    text: "Wind Direction"
                    font.pixelSize: 14
                    color: window.lightTextColor
                }

                Label {
                    text: weatherData.windDirection
                    font.pixelSize: 16
                    font.bold: true
                    color: window.textColor
                }
            }

            // Weather condition
            ColumnLayout {
                Layout.fillWidth: true
                spacing: 2

                Label {
                    text: "Condition"
                    font.pixelSize: 14
                    color: window.lightTextColor
                }

                Label {
                    property var conditions: ["Unknown", "Sunny", "Cloudy", "Rainy", "Snowy"]
                    text: conditions[weatherData.condition]
                    font.pixelSize: 16
                    font.bold: true
                    color: window.textColor
                }
            }
        }

        // Humidity progress bar
        ColumnLayout {
            Layout.fillWidth: true
            spacing: 8

            Label {
                text: "Humidity Level"
                font.pixelSize: 14
                color: window.lightTextColor
            }

            Rectangle {
                Layout.fillWidth: true
                height: 8
                radius: 4
                color: "#E0E0E0"

                Rectangle {
                    width: parent.width * (weatherData.humidity / 100)
                    height: parent.height
                    radius: 4
                    color: window.accentColor
                }
            }
        }

        // Refresh button
        Button {
            Layout.alignment: Qt.AlignRight
            text: "Refresh"

            contentItem: Text {
                text: parent.text
                font.pixelSize: 14
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 36
                color: window.primaryColor
                radius: 4
            }

            onClicked: {
                if (weatherData.location !== "") {
                    weatherApi.getCurrentWeather(weatherData.location)
                }
            }
        }
    }
}
