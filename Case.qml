import QtQuick 2.0

Rectangle
{
    id: creationcase
    color: "transparent"
    visible: true

    property int num ;

    Rectangle
    {
        id: fondcase
        anchors.fill: parent
        color: "#ccc0b2"
        radius: 3
        anchors.rightMargin: 4
        anchors.leftMargin: 4
        anchors.bottomMargin: 4
        anchors.topMargin: 4

        Text
        {
            id: casenum
            x: 30
            y: 30

            text: vueObjetCpt.readValue(num)

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.bold: true
            font.family: "Tahoma"
            font.pixelSize: 24
        }
    }
}


/*Item {
    Rectangle {
        width: 50; height: 50;
        color: couleur;
        border.color: "#646464"
        border.width: 4
        radius: 5

        Text {
          anchors.centerIn: parent
          font.pixelSize: 16
          text: value
        }

    }

}*/

