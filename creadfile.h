#ifndef CREADFILE_H
#define CREADFILE_H

#include <stack>
#include <string>

class CReadFile {
private:
    std::stack<std::string> stack_odd;
    std::stack<std::string> stack_even;

public:
    CReadFile();

    void readFile(const std::string& filename);

    std::stack<std::string> getStackOdd() const;

    std::stack<std::string> getStackEven() const;
};

#endif // CREADFILE_H
