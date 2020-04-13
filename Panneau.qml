import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick 2.14

// Panneau de jeu
Rectangle {
    // Rectangle de fond du panneau
    id: jeu
    property int col: 4
    property int row: 4

    radius: 3;

    anchors {
        right: parent.right; rightMargin: 5
        left: parent.left; leftMargin: 5
        bottom: parent.bottom; bottomMargin: 5
        top: parent.top; topMargin: 100
    }
    color: "#bbada0"

    // Grille des cases du jeu
    Grid {
        id: grid
        anchors.fill: parent;
        columns: col;
        rows: row;
        Repeater {
            model: grid.columns * grid.rows;

            // Case de la grille
            Case {
                num: index
                width: grid.width / grid.columns;
                height: grid.height / grid.rows;


            }
        }
    }


    // Affichage lorsque le jeu est gagné et qu'il n'y a plus de coups possibles
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
        transitions: Transition {
            NumberAnimation { property: "opacity"; duration: 500}
        }

    }

    // Affichage lorsque le jeu est perdu
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
        transitions: Transition {
            NumberAnimation { property: "opacity"; duration: 500}
        }
    }

    // Affichage lorsque le jeu est gagné et qu'il est possible de continuer
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
        transitions: Transition {
            NumberAnimation { property: "opacity"; duration: 500}
        }
    }

}


