import QtQuick 2.0
import QtQuick.Controls 2.0
 import QtQuick 2.14

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

        opacity: 0.0
        states: [
                State { when: vueObjetCpt.gameIsWon & vueObjetCpt.gameIsOver;
                    PropertyChanges {   target: gamewon; visible:true; opacity: 0.8    }
                },
                State { when: !vueObjetCpt.gameIsWon & !vueObjetCpt.gameIsOver;
                    PropertyChanges {   target: gamewon; visible:false; opacity: 0.0    }
                }
            ]
    }

    Lose{
        id:gamelost

        opacity: 0.0

        states: [
             State { when: !vueObjetCpt.gameIsWon & vueObjetCpt.gameIsOver;
                PropertyChanges {   target: gamelost; visible:true; opacity: 0.8    }
            },

            State { when: !vueObjetCpt.gameIsWon & !vueObjetCpt.gameIsOver;
               PropertyChanges {   target: gamelost; visible:false; opacity: 0.0    }
            }
        ]
    }

    Tempwin{
        id:gametempwin

        opacity: 0.0
        states: [
                State { when: vueObjetCpt.gameIsWon & !vueObjetCpt.gameIsOver;
                    PropertyChanges {   target: gametempwin; visible:true; opacity: 0.8    }
                },
                State { when: !vueObjetCpt.gameIsWon & !vueObjetCpt.gameIsOver;
                    PropertyChanges {   target: gametempwin; visible:false; opacity: 0.0    }
                }
            ]
    }








}


