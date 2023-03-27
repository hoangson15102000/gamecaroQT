import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 800
    height: 800
    visible: true
    title: qsTr("Caro")
    Rectangle {
        width: 480
        height: 480
anchors.centerIn: parent
        property int cellSize: 30
        property int fontSize: 30

        // board
        Grid {
            id: board
            columns: 15
            rows: 15
            width: 30 * columns
            height: 30 * rows
            //            color: "grey"
            anchors.centerIn: parent

            // cells
            Repeater {
                model: board.rows * board.columns
                Rectangle {
                    width: 30
                    height: 30
                    color: "white"
                    border.color: "black"
                    border.width: 1

                    // text for X or O
                    Text {
                        text: (CaroModel.getCellValue(index / board.columns, index % board.columns) === CaroModel.X) ? "X" :
                                                                                                                       (CaroModel.getCellValue(index / board.columns, index % board.columns) === CaroModel.O) ? "O" : ""
                        font.pointSize: 30
                        anchors.centerIn: parent
                    }

                    // handle cell click
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
//                            cellClicked(index / board.columns, index % board.columns)
//
                            console.log(Math.floor(index / board.columns), index % board.columns)
                        }
                    }
                }
            }
        }

        // label to show the winner or draw
        Text {
            id: resultLabel
            font.pointSize: 30 * 2
            color: "red"
            anchors.centerIn: parent
            visible: false
        }

        // handle win
        function onWin() {
            resultLabel.text = "Người chơi " + (controller.currentPlayer === CaroModel.X ? "X" : "O") + " thắng!"
            resultLabel.visible = true
        }

        // handle draw
        function onDraw() {
            resultLabel.text = "Hòa!"
            resultLabel.visible = true
        }
    }
    Button {

        text: "Chơi lại"
        onClicked: {
            // clear the board
            for (var r = 0; r < CaroModel.BOARD_SIZE; r++) {
                for (var c = 0; c < CaroModel.BOARD_SIZE; c++) {
                    CaroModel.setCellValue(r, c, CaroModel.Empty);
                }
            }
        }
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
