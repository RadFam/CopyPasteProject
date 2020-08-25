#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "gamecontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<CpPstModel>("CopyPaste", 1, 0, "CopyPasteModel_qml");
    qmlRegisterType<GameController>("CopyPaste", 1, 0, "CopyPasteController_qml");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //engine.setObjectOwnership();

    return app.exec();
}
