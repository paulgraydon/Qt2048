import QtQuick 2.0

// Affichage du score
Rectangle
{
    id: scorecourant
    color: "#ccc0b2"
    visible: true
    width: parent.width/2
    height: 30
    radius: 3

    anchors {
        right: parent.right; rightMargin: 5
        top: parent.top; topMargin: 5
    }

    // Zone de texte
    Text
    {
        id: scoreaffichage
        anchors.fill: parent
        text: "Score : " + vueObjetCpt.getScore()
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        font.family: "Verdana"
        font.pixelSize: 16
    }

    // fonction permettant de mettre à jour l'affichage du score
    function scoreUpdate()
    {
        scoreaffichage.text = "Score : " + vueObjetCpt.getScore()
    }

    // Lien avec la partie logique du programme
    Connections
    {
        target: window
        onUpdate:
        {
            scoreUpdate();
        }
    }
}



