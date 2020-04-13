import QtQuick 2.0
import QtQuick 2.14

// Bouton Nouvelle Partie
Rectangle {
    id: newgame
    width: parent.width/2
    height: 30
    color: "#bbada0"
    //color: "#8c7963"
    radius: 3

    anchors {
        right: parent.right; rightMargin: 5
        top: parent.top; topMargin: 40
    }

    // Zone de texte
    Text {

        anchors.fill: parent
        color: "#F4ECE4"
        text: "Nouvelle Partie"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.family: "Verdana"
        font.bold: true
        font.pixelSize: 12
    }

    // Espace où l'utilisateur peut cliquer pour lancer une nouvelle partie
    MouseArea {
        id: newgamemouseArea
        anchors.fill: parent;
        onClicked:
        {
            vueObjetCpt.restartGame();
            window.update();
        }
    }

}

