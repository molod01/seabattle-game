import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: window
    visible: true
    width: 500
    height: 500
    title: qsTr("Sea Battle Game")
    Board{
       anchors.fill: parent
    }
}
