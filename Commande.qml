import QtQuick 2.0
import QtQuick.Controls 2.14

Rectangle {
    id: panneaucommande;
    width: 300
    height: 100
    color: "#646464"
    radius: 5


    Text {
        id: scorecourant
        width: 100
        height: 30
        text: qsTr("Score: 0")
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 20
        font.pixelSize: 12
    }

    Button {
        id : nouvellepartie
        text: "Nouvelle partie"
        //onClicked: model.submit()
        width : 100
        height : 30
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 20

    }


}
