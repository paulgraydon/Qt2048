import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4


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

    Button {
            id: button1
            x: 50
            y: 193
            text: vueObjetCpt.cptQML
            onClicked:
            {
                vueObjetCpt.toStringCpp();
            }
        }


}
