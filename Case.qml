import QtQuick 2.0

// Case de la grille de jeu
Rectangle{
    id: creationcase
    color: "transparent"
    visible: true

    property int num ;

    // Rectangle de texte
    Rectangle
    {
        id: fondcase
        anchors.fill: parent
        color: vueObjetCpt.readColor(num) //"#ccc0b2"
        radius: 3
        anchors.rightMargin: 4
        anchors.leftMargin: 4
        anchors.bottomMargin: 4
        anchors.topMargin: 4

        // Zone de texte pour afficher le nombre de la case
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

    // Fonction pour mettre à jour la couleur et la valeur de la case
    function caseUpdate()
    {
        casenum.text = vueObjetCpt.readValue(num)
        fondcase.color = vueObjetCpt.readColor(num)
    }

    // Lien avec la partie logique pour la mise à jour de la case
    Connections
    {
        target: window
        onUpdate:
        {
            caseUpdate();
        }
    }



}


