import QtQuick 2.0

// Affichage lorsque le jeu est gagné et qu'il n'est plus possible de continuer à jouer
Rectangle
{
    id: gamewon
    anchors.fill: parent
    color: "#bbada0"
    radius: 3
    opacity: 0.7

    // Zone de texte
    Text {
        id: textwin
        anchors.fill: parent
        color: "#766d65"
        text: qsTr("FIN DE PARTIE !")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.family: "Verdana"
        font.bold: true
        font.pixelSize: 24
    }

}
