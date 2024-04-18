#ifndef TESTSIGNAL_H
#define TESTSIGNAL_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QVariant>
class TestSignal : public QObject
{
    Q_OBJECT

public:
    explicit TestSignal(QObject *parent = nullptr);

signals:
    void returnAnswer(QVariant s);

public slots:
    void getRequest(const QString &msg);
};
#endif // TESTSIGNAL_H
