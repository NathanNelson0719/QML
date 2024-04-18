#include "TestSignal.h"
TestSignal::TestSignal(QObject *parent) : QObject (parent)
{

}

void TestSignal::getRequest(const QString &msg){
    qDebug() << "msg from QML: " << msg;
    std::string text;
    text = "new movie title";
    QString value = QString::fromStdString(text);
    emit returnAnswer(QVariant(value));
}
