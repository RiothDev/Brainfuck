#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Interpreter {
    private:
    std::string filePath;

    public:
    Interpreter(const std::string& f) : filePath(f) {}

    bool getFileContent(std::string& content) {
        std::ifstream file(filePath);

        if(file.is_open()) {
            content.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            file.close();

            return true;
        } else {
            return false;
        }
    }

    void readCode(const std::string& code) {
        std::vector<unsigned char> memory(30000, 0);
        int ptr = 0;

        int codePtr = 0;
        int codeLen = code.length();

        while(codePtr < codeLen) {
            char instruction = code[codePtr];

            switch(instruction) {
                case '>': ++ptr; break;
                case '<': --ptr; break;
                case '+': ++memory[ptr]; break;
                case '-': --memory[ptr]; break;
                case '.': std::cout.put(memory[ptr]); break;
                case ',': memory[ptr] = std::cin.get(); break;
                case '[':
                if(memory[ptr] == 0) {
                    int loopCount = 1;

                    while(loopCount > 0) {
                        ++codePtr;
                        
                        if(code[codePtr] == '[') {
                            ++loopCount;

                        } else if(code[codePtr] == ']') {
                            --loopCount;
                        }
                    }
                }

                break;

                case ']':
                if(memory[ptr] != 0) {
                    int loopCount = 1;

                    while(loopCount > 0) {
                        --codePtr;

                        if(code[codePtr] == ']') {
                            ++loopCount;

                        } else if(code[codePtr] == '[') {
                            --loopCount;
                        }
                    }
                }

                break;
                default: break;
            }

            ++codePtr;
        }
    }
};