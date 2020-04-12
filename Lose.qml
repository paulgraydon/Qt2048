import QtQuick 2.0

Rectangle
{
    id: gamelost
    anchors.fill: parent
    color: "#bbada0"
    radius: 3
    opacity: 0.7

    Text {
        id: textlost
        anchors.fill: parent
        color: "#766d65"
        text: qsTr("VOUS AVEZ PERDU!")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.family: "Verdana"
        font.bold: true
        font.pixelSize: 24
    }

}
