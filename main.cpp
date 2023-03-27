#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "caromodel.h"
#include "carocontroller.h"
#include <QQmlContext>

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    // create the model, view and controller
    CaroModel model;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("CaroModel", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    carocontroller controller(&model);

    // connect signals and slots
        QObject* rootObject = engine.rootObjects().first();
        QObject::connect(rootObject, SIGNAL(cellClicked(int, int)), &controller, SLOT(cellClicked(int, int)));
        QObject::connect(&controller, SIGNAL(win()), rootObject, SLOT(onWin()));
        QObject::connect(&controller, SIGNAL(draw()), rootObject, SLOT(onDraw()));

    return app.exec();
}
