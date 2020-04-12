import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4
import QtQuick 2.3
import QtQuick.Window 2.2
import Qt.labs.settings 1.0
import QtQuick 2.14


Window {
    id: window
    visible: true
    width: 300
    height: 400
    title: qsTr("2048")

    signal update()

    Panneau {
        id: jeu
        visible: true
        focus: true

        Keys.onPressed: {

            switch (event.key) {
            case Qt.Key_Up:
                vueObjetCpt.performMove(1);
                window.update();
                break;
            case Qt.Key_Down:
                vueObjetCpt.performMove(2);
                window.update();
                break;
            case Qt.Key_Left:
                vueObjetCpt.performMove(3);
                window.update();
                break;
            case Qt.Key_Right:
                vueObjetCpt.performMove(4);
                window.update();
                break;
            }
        }
    }

    Commande{
        id : panneaucommande
    }



}
