//
// Created by cjoris on 1/28/18.
//

#ifndef UNTITLED_CPU_H
#define UNTITLED_CPU_H


#include "Memory.h"

enum eCommandType {PUSH, POP, CLEAR, DUP, SWAP, DUMP, ASSERT, ADD, SUB, MUL, DIV, MOD, LOAD, STORE, PRINT};

class Cpu {
public:
    explicit Cpu(Memory *memory);

    std::string dump();
    char print();
    void memoryAction(eCommandType action);
    void assert(eOperandType type, std::string value);
    void push(eOperandType type, std::string value);
    void load(eOperandType type, std::string index);
    void store(eOperandType type, std::string index);
    void add();
    void sub();
    void mul();
    void div();
    void mod();
    ~Cpu();

private:
    Memory _memory;
};


#endif //UNTITLED_CPU_H
