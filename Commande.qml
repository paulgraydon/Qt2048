import QtQuick 2.0

Rectangle {
    id: panneaucommande

    height: 90
    color: "transparent"
    radius: 5

    anchors {
        right: parent.right; rightMargin: 5
        left: parent.left; leftMargin: 5
        top: parent.top; topMargin: 5
    }

    Rectangle {
        id: titre
        width: 80
        height: 70
        color: "transparent" //"#F4ECE4"
        radius: 5

        anchors {
            left: parent.left; leftMargin: 15
            top: parent.top; topMargin: 5
        }

        Text {

            anchors.fill: parent
            color: "#eea15d"
            text: "2048"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "Verdana"
            font.bold: true
            font.pixelSize: 32
        }

    }

    ScoreCourant{
        id : scorecourant
    }

    NouvellePartie{
        id: newgame
    }

}

