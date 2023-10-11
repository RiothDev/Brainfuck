#include "Interpreter.hpp"

int main(int argc, char* argv[]) {
    std::string fileContent;
    Interpreter interpreter(argv[1]);

    if(interpreter.getFileContent(fileContent)) {
        interpreter.readCode(fileContent);   
    } else {
        std::cerr << "Incorrect file path" << std::endl;
    }

    return 0;
}