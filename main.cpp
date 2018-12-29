#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "test.h"
#include "scanner.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<Test>("ali.test",1,0,"Test");
    qmlRegisterType<Scanner>("leica.scanner",1,0,"Scaner");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
