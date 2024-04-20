#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "TestSignal.h"
#include "CFantasyMovies.h"
#include "creadfile.h"
#include <QDebug>
#include <QDir>
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    TestSignal test;
    CReadFile fileReader;
    CFantasyMovies CFantasyMovie;

    fileReader.readFile("input.txt");
    CFantasyMovie.setEvenStack(fileReader.getStackEven());
    CFantasyMovie.setOddStack(fileReader.getStackOdd());

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    QObject *topLevel = engine.rootObjects().at(0);
    QQuickWindow *window = qobject_cast<QQuickWindow*>(topLevel);

    QObject::connect(window, SIGNAL(changeRequest(QString)), &CFantasyMovie,SLOT(processNumber(QString)));
    QObject::connect(&CFantasyMovie, SIGNAL(movieSelected(QVariant)), window, SLOT(changeTitle(QVariant)));

    return app.exec();
}
