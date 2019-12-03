import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: page
    visible: true
    width: 640
    height: 480
    color: "#ee5d5d"
    title: qsTr("Movie Night")

    signal qmlSignal(string num)

    function updateText(text)
    {
        output.text = text
    }

    TextEdit {
        id: input
        x: 288
        y: 148
        width: 77
        height: 37
        text: qsTr("123")
        font.pixelSize: 32
    }

    Text {
        id: output
        x: 49
        y: 366
        width: 543
        height: 53
        text: qsTr("Text")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 32
    }

    MouseArea {
        id: mouseArea
        x: 265
        y: 200
        width: 107
        height: 100

        onClicked: {
            page.qmlSignal(input.text)
        }
    }

    Image {
        id: image
        x: 21
        y: 328
        width: 603
        height: 152
        source: "tv-icon.png"
        fillMode: Image.Stretch
    }

    Image {
        id: image1
        x: 66
        y: -83
        width: 526
        height: 205
        source: "lights.png"
        fillMode: Image.Stretch

        Text {
            id: element
            x: 129
            y: 115
            text: qsTr("Enter Any Number")
            font.pixelSize: 32
        }
    }

    Image {
        id: image2
        x: 265
        y: 200
        width: 100
        height: 100
        source: "clapperboard.png"
        fillMode: Image.PreserveAspectFit
    }
}
