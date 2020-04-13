import QtQuick 2.0

Rectangle {
    id: panneaucommande

    height: 90
    color: "transparent" //"#F4ECE4"
    radius: 5

    anchors {
        right: parent.right; rightMargin: 5
        left: parent.left; leftMargin: 5
        //bottom: parent.bottom; bottomMargin: 5
        top: parent.top; topMargin: 5
    }

    ScoreCourant{
        id : scorecourant
    }

    NouvellePartie{
        id: newgame
    }



}




/*import QtQuick 2.0
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


}*/
