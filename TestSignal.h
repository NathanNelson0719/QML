#ifndef TESTSIGNAL_H
#define TESTSIGNAL_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QVariant>
#include <QStack>
class TestSignal : public QObject
{
    Q_OBJECT

public:
    explicit TestSignal(QObject *parent = nullptr);
    void setOddStack(QStack<QString> stack);
    void setEvenStack(QStack<QString> stack);
signals:
    void returnTitle(QString title);

public slots:
    void getEvenTitle();
    void getOddTitle();

private:
    QStack<QString> stack_odd;
    QStack<QString> stack_even;
};
#endif // TESTSIGNAL_H
