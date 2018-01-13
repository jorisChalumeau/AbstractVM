//
// Created by apaca on 12/01/2018.
//

#ifndef UNTITLED_FACTORY_H
#define UNTITLED_FACTORY_H

#include <string>
#include "IOperand.h"

class Factory {
public:
	static IOperand *createOperand(eOperandType type, const std::string& value);

private:
	static IOperand *createInt8(const std::string& value);

	static IOperand *createInt16(const std::string& value);

	static IOperand *createInt32(const std::string& value);

	static IOperand *createFloat(const std::string& value);

	static IOperand *createDouble(const std::string& value);

	static IOperand *createBigDecimal(const std::string& value);

};


#endif //UNTITLED_FACTORY_H
