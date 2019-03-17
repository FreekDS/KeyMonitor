#include <iostream>
#include "Keyboard.h"
#include <fstream>

using namespace std;

int main() {
    std::ifstream input("helper.txt");
    std::ofstream output("output.txt");
    if (!input.is_open() || !output.is_open())
        return -1;
    std::string line;
    while (std::getline(input, line)) {
        output << "case " << line << ":" << endl;
        output << "\treturn \"" << line.substr(4, line.size() - 4) << "\";" << endl;
    }

    input.close();
    output.close();
    return 0;
}