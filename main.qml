import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 350
    height: 400
    title: qsTr("2048")

    Panneau {
        id: jeu
        anchors.verticalCenterOffset: 25
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        scale: 1

    }

    Commande{
        id : panneaucommande
        width: 188
        height: 50
        anchors.top: parent.top
        anchors.topMargin: 30
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        scale: 1

    }


}
