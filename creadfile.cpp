#include "creadfile.h"
#include <iostream>
#include <fstream>

CReadFile::CReadFile() {}

void CReadFile::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string title;
    int sequence = 1; // Sequence number starts from 1

    while (std::getline(file, title)) {
        if (sequence % 2 == 0) {
            stack_even.push(title);
        } else {
            stack_odd.push(title);
        }
        sequence++;
    }

    file.close();
}

std::stack<std::string> CReadFile::getStackOdd() const {
    return stack_odd;
}

std::stack<std::string> CReadFile::getStackEven() const {
    return stack_even;
}
