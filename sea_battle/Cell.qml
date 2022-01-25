import QtQuick 2.0
import QtQuick 2.15
Rectangle {
    id: cell
    state: "sea"
    color: "blue"

    property int row: index / root.model.dimension
    property int col: index % root.model.dimension

    property string sea: "file:../sea_battle/images/water.jpg"
    property string exp: "file:../sea_battle/images/exploded.png"

    Image {

        id: image
        width: root.cellWidth
        height: root.cellHeight
        //source: root.model.data(root.model.index(row, col), 0).exploded ? exp : sea
        source: sea
    }
    states: [
        State {
            name: "exploded"
                PropertyChanges{
                    target: image
                    source: exp
                }
        },
        State {
            name: "water"
                PropertyChanges{
                    target: image
                    source: sea
                }
        }
    ]
}
