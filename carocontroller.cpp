#include "carocontroller.h"

carocontroller::carocontroller(CaroModel* model, QObject* parent)
    : QObject(parent), m_model(model)
{
}

void carocontroller::cellClicked(int row, int col)
{
    // check if the cell is empty
    if (m_model->getCellValue(row, col) != CaroModel::Empty) {
        return;
    }
    // set the value of the cell to X or O depending on the current player
    m_model->setCellValue(row, col, m_currentPlayer);
    // check if the current player has won
    if (m_model->checkWin(row, col, m_currentPlayer)) {
        emit win();
        return;
    }
    // check if the board is full
    bool boardFull = true;
    for (int r = 0; r < m_model->BOARD_SIZE; r++) {
        for (int c = 0; c < m_model->BOARD_SIZE; c++) {
            if (m_model->getCellValue(r, c) == CaroModel::Empty) {
                boardFull = false;
                break;
            }
        }
        if (!boardFull) {
            break;
        }
    }
    if (boardFull) {
        emit draw();
        return;
    }
    // switch to the other player
    m_currentPlayer = (m_currentPlayer == CaroModel::X) ? CaroModel::O : CaroModel::X;
}

