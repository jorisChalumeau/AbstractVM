//
// Created by apaca on 13/01/2018.
//

#include "../header/Memory.h"

Memory::Memory() = default;

int Memory::addToRegister(int registerNB, IOperand& value) {
	if (registerNB < 0 || registerNB > 15) {
		//TODO : gestion des erreurs
		return -1;
	}
	this->registers[registerNB] = &value;
	return EXIT_SUCCESS;
}

IOperand *Memory::getRegisterValue(int registerNB) {
	if (registerNB < 0 || registerNB > 15) {
		//TODO : gestion des erreurs
	}
	return this->registers[registerNB];
}