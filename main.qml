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

    signal update()

    Panneau {
        id: jeu

        Keys.onPressed: {
            switch (event.key) {
            case Qt.Key_Up:
                vueObjetCpt.move(UP);
                window.update();
                break;
            case Qt.Key_Down:
                vueObjetCpt.move(DOWN);
                window.update();
                break;
            case Qt.Key_Left:
                vueObjetCpt.move(LEFT);
                window.update();
                break;
            case Qt.Key_Right:
                vueObjetCpt.move(RIGHT);
                window.update();
                break;
            }
        }
    }

    Commande{
        id : panneaucommande
    }

}
