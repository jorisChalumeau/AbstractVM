//
// Created by apaca on 12/01/2018.
//

#include "../header/Factory.h"

IOperand *Factory::createOperand(eOperandType type, const std::string& value) {
	switch (type){
		case Int8:
			return Factory::createInt8(value);
		case Int16:
			return Factory::createInt16(value);
		case Int32:
			return Factory::createInt32(value);
		case Float:
			return Factory::createFloat(value);
		case Double:
			return Factory::createDouble(value);
		case BigDecimal:
			return Factory::createBigDecimal(value);
		default:
			return nullptr;
	}
}

IOperand *Factory::createInt8(const std::string& value) {
	return nullptr;
}

IOperand *Factory::createInt16(const std::string& value) {
	return nullptr;
}

IOperand *Factory::createInt32(const std::string& value) {
	return nullptr;
}

IOperand *Factory::createFloat(const std::string& value) {
	return nullptr;
}

IOperand *Factory::createDouble(const std::string& value) {
	return nullptr;
}

IOperand *Factory::createBigDecimal(const std::string& value) {
	return nullptr;
}
