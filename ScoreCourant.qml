import QtQuick 2.0

Rectangle
{
    id: scorecourant
    color: "#ccc0b2"
    visible: true
    width: parent.width/2
    height: 30
    radius: 3

    anchors {
        right: parent.right; rightMargin: 5
        top: parent.top; topMargin: 5
    }

    Text
    {
        id: scoreaffichage
        anchors.fill: parent
        text: "Score : " + vueObjetCpt.getScore()
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        font.family: "Verdana"
        font.pixelSize: 16
    }


    function scoreUpdate()
    {
        scoreaffichage.text = "Score : " + vueObjetCpt.getScore()
    }

    Connections
    {
        target: window
        onUpdate:
        {
            scoreUpdate();
        }
    }
}



