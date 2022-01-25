import QtQuick 2.0
import Model 1.0
import Game 1.0

GridView {
    id: root
    cellHeight: window.height / root.model.dimension
    cellWidth: window.width / root.model.dimension
    delegate: Component {
        Cell {
            id: cellWrapper
            width: root.cellWidth
            height: root.cellHeight
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    root.model.click(index);
                }
            }
        }
    }

    Controller{
        id: _gameController
    }
    Component.onCompleted: {
        root.model =  _gameController.getModel();
    }
}
