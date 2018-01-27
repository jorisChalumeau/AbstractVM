//
// Created by apaca on 13/01/2018.
//

#ifndef UNTITLED_MEMORY_H
#define UNTITLED_MEMORY_H

#include <stack>
#include <string>
#include <iostream>
#include "IOperand.h"

#define REG_MAX 15
#define REG_MIN 0

class Memory {
public:
	Memory();

	int addToRegister(int registerNB, IOperand &value);
	IOperand *getRegisterValue(int registerNB);
	void push(eOperandType type, std::string value);
	void pop();
	void clear();
	void dup();
	void swap();
	void dump();
	void assert(eOperandType type, std::string value);
	void add();
	void sub();
	void mul();
	void div();
	void mod();
	void load(eOperandType type, int registerInd);
	void store(eOperandType type, int registerInd);
	void print();
	~Memory();

private:
	std::stack<IOperand> stack;
	IOperand *registers[16];
};


#endif //UNTITLED_MEMORY_H
