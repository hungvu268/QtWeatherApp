import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import com.example.weather 1.0

Page {
    id: weatherPage
    anchors.fill: parent

    Rectangle {
        anchors.fill: parent
        color: window.backgroundColor

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 20

            Text {
                Layout.alignment: Qt.AlignHCenter
                text: "Weather Page"
                font.pixelSize: 24
                color: window.textColor
            }

            TextField {
                Layout.fillWidth: true
                placeholderText: "Enter city name"
                onAccepted: weatherApi.getCurrentWeather(text)
            }

            Button {
                Layout.alignment: Qt.AlignHCenter
                text: "Get Weather"
                onClicked: weatherApi.getCurrentWeather("London")
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: window.cardColor
                radius: 8

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 10

                    Text {
                        Layout.alignment: Qt.AlignHCenter
                        text: weatherApi.currentWeather.location || "No location data"
                        font.pixelSize: 22
                        font.bold: true
                        color: window.textColor
                    }

                    Text {
                        Layout.alignment: Qt.AlignHCenter
                        text: weatherApi.currentWeather.temperature ?
                              "Temperature: " + weatherApi.currentWeather.temperature + "°C" :
                              ""
                        font.pixelSize: 18
                        color: window.textColor
                        visible: weatherApi.currentWeather.location !== ""
                    }

                    Text {
                        Layout.alignment: Qt.AlignHCenter
                        text: "Status: " + (weatherApi.loading ? "Loading..." : "Ready")
                        font.pixelSize: 16
                        color: window.lightTextColor
                    }
                }
            }
        }
    }
}
