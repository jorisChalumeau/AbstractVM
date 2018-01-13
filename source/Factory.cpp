//
// Created by apaca on 12/01/2018.
//

#include "../header/Factory.h"
#include "../header/OpInt8.h"
#include "../header/OpInt16.h"
#include "../header/OpInt32.h"
#include "../header/OpFloat.h"
#include "../header/OpDouble.h"
#include "../header/OpBigDecimal.h"

IOperand *Factory::createOperand(eOperandType type, const std::string& value) {
	switch (type) {
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
    return (new OpInt8(value));
}

IOperand *Factory::createInt16(const std::string& value) {
    return (new OpInt16(value));
}

IOperand *Factory::createInt32(const std::string& value) {
    return (new OpInt32(value));
}

IOperand *Factory::createFloat(const std::string& value) {
	return (new OpFloat(value));
}

IOperand *Factory::createDouble(const std::string& value) {
	return (new OpDouble(value));
}

IOperand *Factory::createBigDecimal(const std::string& value) {
	return (new OpBigDecimal(value));
}
