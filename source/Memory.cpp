//
// Created by apaca on 13/01/2018.
//

#include "../header/Memory.h"
#include "../header/Exceptions.h"

Memory::Memory() = default;

int Memory::addToRegister(int registerNB, IOperand& value) {
	if (registerNB < 0 || registerNB > 15) {
		throw OutOfBound("can't add value in register " + std::to_string(registerNB) + ".");
	}
	this->registers[registerNB] = &value;
	return EXIT_SUCCESS;
}

IOperand *Memory::getRegisterValue(int registerNB) {
	if (registerNB < 0 || registerNB > 15) {
		throw OutOfBound("can't add value in register " + std::to_string(registerNB) + ".");
	}
	return this->registers[registerNB];
}