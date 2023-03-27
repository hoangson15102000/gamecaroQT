#ifndef CAROMODEL_H
#define CAROMODEL_H

#include <QObject>
#include <QVector>

class CaroModel : public QObject
{
    Q_OBJECT
public:
    explicit CaroModel(QObject *parent = nullptr);
    const int BOARD_SIZE =15;
    enum CellType{
        Empty,
        X,
        O
    };
    Q_ENUM(CellType)
    Q_INVOKABLE void setCellValue(int row, int col, CellType value);
    Q_INVOKABLE CellType getCellValue(int row,int col) const;
    Q_INVOKABLE bool checkWin(int row, int col, CellType value) const;

private:
    QVector<QVector<CellType>> m_board;



signals:
    void boardChanged();

};

#endif // CAROMODEL_H
