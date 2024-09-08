#pragma once
#include <iostream>
#include <string.h>

class MyString {
    int sizeL{};
    char* Line{};


public:
    explicit MyString(int sizeL) : sizeL{ sizeL }, Line{ new char[sizeL] {} } {}
    explicit MyString() : sizeL{ 80 }, Line{ new char[sizeL] {} } {}
    explicit MyString(const char* LINE) :sizeL{ (int)strlen(LINE) + 1 }, Line{ new char[sizeL] {} } {
        strcpy_s(Line, sizeL, LINE);
    }
    ~MyString() {
        delete Line;
    }
    void set_size(int Size) {
        Size = sizeL;
    }
    int get_size()const {
        return sizeL;
    }
    void print()const {
        for (int i{}; i < sizeL; ++i) {
            std::cout << Line[i];
        }
        std::cout << std::endl;
    }
    void setL(const char* Line) {
        delete[] this->Line;
        this->Line = new char [strlen(Line) + 1] {};
        sizeL = strlen(Line) + 1;
        strcpy_s(this->Line, sizeL, Line);
    }
    void genL() {
        char str[300];
        std::cin.getline(str, 300);
        setL(str);
    }
};