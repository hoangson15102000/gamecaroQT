#include "caromodel.h"

CaroModel::CaroModel(QObject *parent) : QObject(parent)
{
     m_board= QVector<QVector<CellType>>(BOARD_SIZE,QVector<CellType>(BOARD_SIZE,Empty));
}

void CaroModel::setCellValue(int row, int col, CellType value)
{

m_board[row][col]= value;
emit boardChanged();
}

CaroModel::CellType CaroModel::getCellValue(int row, int col) const
{
    return m_board[row][col];
}

bool CaroModel::checkWin(int row, int col, CellType value) const
{
    int count =0;
    // check row

    for(int c =0;c<BOARD_SIZE;c++){
        if(m_board[row][c]==value){
            count++;
        }
        else
        {
            count =0;

        }
        if(count>=5){
            return true;
        }
    }
    // check column
        count = 0;
        for (int r = 0; r < BOARD_SIZE; r++) {
            if (m_board[r][col] == value) {
                count++;
            } else {
                count = 0;
            }
            if (count >= 5) {
                return true;
            }
        }

       // check duong cheo 1
        count =0;
        int r= row,c=col;
        while(r>0&&c>0){
            r--;
            c--;
        }
        while(r<BOARD_SIZE&&c<BOARD_SIZE){
            if(m_board[r][c]==value){
                count++;
            }
            else{
                count =0;
            }
            if(count>=5){
                return true;
            }
            r++;
            c++;
        }
        // check diagonal 2
            count = 0;
            r = row;
            c = col;
            while (r > 0 && c < BOARD_SIZE - 1) {
                r--;
                c++;
            }
            while (r < BOARD_SIZE && c >= 0) {
                if (m_board[r][c] == value) {
                    count++;
                } else {
                    count = 0;
                }
                if (count >= 5) {
                    return true;
                }
                r++;
                c--;
            }
            return false;
}


