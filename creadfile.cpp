#include "creadfile.h"
#include <iostream>
#include <fstream>
#include <QDebug>
CReadFile::CReadFile() {}

void CReadFile::readFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "could not read file";
        return;
    }

    QString title;
    int sequence = 1; // Sequence number starts from 1

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        title = stream.readLine();
        qDebug() << "read title: " << title;
        if (sequence % 2 == 0) {
            qDebug() << "added title: " << title << " to even stack";
            stack_even.push(title);
        } else {
            qDebug() << "added title: " << title << " to odd stack";
            stack_odd.push(title);
        }
        sequence++;
    }

    file.close();
}

QStack<QString> CReadFile::getStackOdd() const {
    return stack_odd;
}

QStack<QString> CReadFile::getStackEven() const {
    return stack_even;
}
