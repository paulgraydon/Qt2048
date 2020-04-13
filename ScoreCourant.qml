import QtQuick 2.0

Rectangle
{
    id: scorecourant
    color: "#ccc0b2"
    visible: true

    radius: 3
    anchors.rightMargin: 20
    //anchors.leftMargin: 4
    //anchors.bottomMargin: 4
    anchors.topMargin: 5

    Text
    {
        id: scoreaffichage
        x: 30
        y: 30

        text: "score"//vueObjetCpt.

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.bold: true
        font.family: "Tahoma"
        font.pixelSize: 24
    }


    /*function scoreUpdate()
    {
        //scoreaffichage.text = vueObjetCpt.
    }

    Connections
    {
        target: window
        onUpdate:
        {
            scoreUpdate();
        }
    }*/
}



