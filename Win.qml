import QtQuick 2.0

Rectangle
{
    id: gamewon
    anchors.fill: parent
    color: "#bbada0"
    radius: 3
    opacity: 0.7

    Text {
        id: textwin
        anchors.fill: parent
        color: "#766d65"
        text: qsTr("VOUS AVEZ GAGNÉ!")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.family: "Verdana"
        font.bold: true
        font.pixelSize: 24
    }

}
