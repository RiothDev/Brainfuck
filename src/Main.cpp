#include "Interpreter.hpp"

int main(int argc, char* argv[]) {
    std::string filePath, fileContent;

    std::cout << "> File path: ";
    std::cin >> filePath;

    Interpreter interpreter(filePath);

    if(interpreter.getFileContent(fileContent)) {
        interpreter.readCode(fileContent);   
    } else {
        std::cerr << "Incorrect file path" << std::endl;
    }

    return 0;
}