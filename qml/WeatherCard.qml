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

    // Weather card content
    RowLayout {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 12
        ColumnLayout {
            // Location and date
            ColumnLayout {
                Layout.fillWidth: true
                spacing: 4

                Label {
                    id: locationLabel
                    text: weatherData.location
                    font.pixelSize: 24
                    font.bold: true
                    color: window.textColor
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    elide: Text.ElideRight
                }

                Label {
                    text: weatherData.timestamp.toLocaleDateString(Qt.locale(), Locale.LongFormat)
                    font.pixelSize: 14
                    color: window.lightTextColor
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            // Weather icon and condition
            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: 100

                Image {
                    id: weatherIcon
                    source: weatherData.iconSource
                    width: 80
                    height: 80
                    fillMode: Image.PreserveAspectFit
                    anchors.centerIn: parent
                }
            }

            // Weather condition
            Label {
                text: weatherData.conditionText
                font.pixelSize: 18
                color: window.textColor
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                // Capitalize first letter
                Component.onCompleted: {
                    if (text.length > 0) {
                        text = text.charAt(0).toUpperCase() + text.slice(1)
                    }
                }
            }
        }

        ColumnLayout {
            // Temperature
            Label {
                id: temperatureLabel
                text: Math.round(weatherData.temperature) + "°C"
                font.pixelSize: 48
                font.bold: true
                color: window.textColor
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
            }

            Label {
                text: "Feels like: " + Math.round(weatherData.feelsLike) + "°C"
                font.pixelSize: 16
                color: window.lightTextColor
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
            }

            // Last updated time
            Label {
                text: "Last updated: " + weatherData.timestamp.toLocaleTimeString(Qt.locale(), Locale.ShortFormat)
                font.pixelSize: 12
                color: window.lightTextColor
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignRight
            }
        }
    }
}
