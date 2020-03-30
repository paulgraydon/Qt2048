import QtQuick 2.0

Item {
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

}
