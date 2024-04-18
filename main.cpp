#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "TestSignal.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    TestSignal test;
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    QObject *topLevel = engine.rootObjects().at(0);
    QQuickWindow *window = qobject_cast<QQuickWindow*>(topLevel);

    QObject::connect(window, SIGNAL(changeRequest(QString)), &test,SLOT(getRequest(QString)));
    QObject::connect(&test, SIGNAL(returnAnswer(QVariant)), window, SLOT(changeTitle(QVariant)));


    return app.exec();
}
