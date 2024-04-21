#ifndef CREADFILE_H
#define CREADFILE_H

#include <QStack>
#include <QString>
#include <QFile>
#include <QTextStream>
class CReadFile {
private:
    QStack<QString> stack_odd;
    QStack<QString> stack_even;

public:
    CReadFile();

    void readFile(const QString& filename);

    QStack<QString> getStackOdd() const;

    QStack<QString> getStackEven() const;
};

#endif // CREADFILE_H
