import QtQuick 2.0

Rectangle {
    id: jeu;
    width: 188
    height: 188
    color: "#646464"
    radius: 5


    //property int emptyBlock: 16;

    GridView {
        id: grille;
        //keyNavigationWraps: true
        cellHeight: 46
        cellWidth: 46
        //cacheBuffer: 320
        //interactive: true
        anchors.fill: parent
        model: gridModel

        delegate: Component{
          Case {}
        }
    }

    ListModel {
      id: gridModel
      ListElement {
          value: 1//tileBoard[0][0].getValue();
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 2
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 3
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 4
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 5
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 2
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 3
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 4
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 1
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 2
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 3
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 4
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 1
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 2048
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 32
          couleur: "#dcdcdc"
      }
      ListElement {
          value: 4
          couleur: "#dcdcdc"
      }
    }




    /*Keys.onRightPressed: {
      gridModel.move(grille.currentIndex, grille.currentIndex+1, 1)
    }

    Keys.onLeftPressed: {
      gridModel.move(grille.currentIndex, grille.currentIndex-1, 1)
    }*/

    focus: true;
}
