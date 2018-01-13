//
// Created by cjoris on 1/13/18.
//

#include "../header/Int8.h"

Int8::Int8(const std::string &value) {
	this->type = eOperandType::Int8;
}

std::string Int8::toString() const {
	return "Int8";
}

eOperandType Int8::getType() const {
	return this->type;
}

IOperand *Int8::operator+(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Int8::operator-(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Int8::operator*(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Int8::operator/(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Int8::operator%(const IOperand& rhs) const {
	return nullptr;
}
