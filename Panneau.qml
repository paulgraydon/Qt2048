import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
    id: jeu
    property int col: 4
    property int row: 4

    radius: 3;

    /*Connections
        {
            target:vueObjetCpt
            onChangementCPP:
            {
                affichageCpp.text = text;
            }
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

    Text {
            id: affichageCpp
            x: 177
            y: 245
            text: qsTr("Text")
            font.pixelSize: 12
        }*/


    anchors {
        right: parent.right; rightMargin: 5
        left: parent.left; leftMargin: 5
        bottom: parent.bottom; bottomMargin: 5
        top: parent.top; topMargin: 100
    }
    color: "#bbada0"

    Grid {
        id: grid
        anchors.fill: parent;
        columns: col;
        rows: row;
        Repeater {
            model: grid.columns * grid.rows;

            Case {
                num: index
                width: grid.width / grid.columns;
                height: grid.height / grid.rows;
            }
        }
    }


    Win{
        id:gamewon
        visible:false
    }

    Lose{
        id:gamelost
        visible:false
    }

}


