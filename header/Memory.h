//
// Created by apaca on 13/01/2018.
//

#ifndef UNTITLED_MEMORY_H
#define UNTITLED_MEMORY_H

#include <stack>
#include "IOperand.h"

class Memory {
public:
	Memory();

	int addToRegister(int registerNB, IOperand& value);

	IOperand *getRegisterValue(int registerNB);

private:
	std::stack<IOperand> stack;
	IOperand *registers[16];
};


#endif //UNTITLED_MEMORY_H
