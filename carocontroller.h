#pragma once
#include <QObject>
#include "caromodel.h"

class carocontroller : public QObject
{
    Q_OBJECT

public:
    carocontroller(CaroModel* model, QObject* parent = nullptr);

signals:
    void win();
    void draw();
public slots:
    void cellClicked(int row, int col);

private:
    CaroModel* m_model;
    // ???
    CaroModel::CellType m_currentPlayer = CaroModel::X;
};
