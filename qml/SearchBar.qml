import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: root
    height: 50
    radius: 8
    color: window.cardColor

    // Shadow effect (commented out to reduce dependencies)
    /*
    layer.enabled: true
    layer.effect: DropShadow {
        horizontalOffset: 0
        verticalOffset: 2
        radius: 8.0
        samples: 17
        color: "#20000000"
    }
    */

    // Custom properties
    property alias searchText: searchField.text

    // Custom signals
    signal settingsClicked()

    // Public methods
    function search() {
        if (searchField.text.trim() !== "") {
            weatherApi.getCurrentWeather(searchField.text.trim())
            searchField.focus = false
        }
    }

    RowLayout {
        anchors.fill: parent
        anchors.margins: 8
        spacing: 8

        // Search field
        TextField {
            id: searchField
            Layout.fillWidth: true
            placeholderText: qsTr("Enter city name...")
            selectByMouse: true

            background: Rectangle {
                implicitWidth: 200
                implicitHeight: 40
                color: "transparent"
                border.color: searchField.activeFocus ? window.accentColor : "transparent"
                border.width: searchField.activeFocus ? 1 : 0
                radius: 4
            }

            font.pixelSize: 16
            color: window.textColor

            onAccepted: root.search()

            // Clear button
            Image {
                id: clearButton
                source: "data:image/svg+xml;utf8,<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='%23757575'><path d='M19 6.41L17.59 5 12 10.59 6.41 5 5 6.41 10.59 12 5 17.59 6.41 19 12 13.41 17.59 19 19 17.59 13.41 12z'/></svg>"
                width: 20
                height: 20
                anchors.right: parent.right
                anchors.rightMargin: 8
                anchors.verticalCenter: parent.verticalCenter
                visible: searchField.text.length > 0

                MouseArea {
                    anchors.fill: parent
                    onClicked: searchField.text = ""
                }
            }
        }

        // Search button
        Rectangle {
            width: 40
            height: 40
            radius: 4
            color: window.primaryColor

            Image {
                anchors.centerIn: parent
                width: 24
                height: 24
                source: "data:image/svg+xml;utf8,<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='white'><path d='M15.5 14h-.79l-.28-.27C15.41 12.59 16 11.11 16 9.5 16 5.91 13.09 3 9.5 3S3 5.91 3 9.5 5.91 16 9.5 16c1.61 0 3.09-.59 4.23-1.57l.27.28v.79l5 4.99L20.49 19l-4.99-5zm-6 0C7.01 14 5 11.99 5 9.5S7.01 5 9.5 5 14 7.01 14 9.5 11.99 14 9.5 14z'/></svg>"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: root.search()
            }
        }

        // Settings button
        Rectangle {
            width: 40
            height: 40
            radius: 4
            color: "transparent"

            Image {
                anchors.centerIn: parent
                width: 24
                height: 24
                source: "data:image/svg+xml;utf8,<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='%23757575'><path d='M19.14 12.94c.04-.3.06-.61.06-.94 0-.32-.02-.64-.07-.94l2.03-1.58c.18-.14.23-.41.12-.61l-1.92-3.32c-.12-.22-.37-.29-.59-.22l-2.39.96c-.5-.38-1.03-.7-1.62-.94l-.36-2.54c-.04-.24-.24-.41-.48-.41h-3.84c-.24 0-.43.17-.47.41l-.36 2.54c-.59.24-1.13.57-1.62.94l-2.39-.96c-.22-.08-.47 0-.59.22L2.74 8.87c-.12.21-.08.47.12.61l2.03 1.58c-.05.3-.09.63-.09.94s.02.64.07.94l-2.03 1.58c-.18.14-.23.41-.12.61l1.92 3.32c.12.22.37.29.59.22l2.39-.96c.5.38 1.03.7 1.62.94l.36 2.54c.05.24.24.41.48.41h3.84c.24 0 .44-.17.47-.41l.36-2.54c.59-.24 1.13-.56 1.62-.94l2.39.96c.22.08.47 0 .59-.22l1.92-3.32c.12-.22.07-.47-.12-.61l-2.01-1.58zM12 15.6c-1.98 0-3.6-1.62-3.6-3.6s1.62-3.6 3.6-3.6 3.6 1.62 3.6 3.6-1.62 3.6-3.6 3.6z'/></svg>"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: root.settingsClicked()
            }
        }
    }

    // Import drop shadow effect - commented out as we're not using it now
    // import QtGraphicalEffects 1.15
}
