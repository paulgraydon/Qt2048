import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 300
    height: 400
    title: qsTr("2048")

    Panneau {
        id: jeu
    }

    Commande{
        id : panneaucommande

    }


}
