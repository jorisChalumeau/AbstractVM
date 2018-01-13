//
// Created by cjoris on 1/13/18.
//

#include "../header/Int16.h"

Int16::Int16(const std::string &value) {
	this->type = eOperandType::Int16;
}

std::string Int16::toString() const {
	return "Int16";
}

eOperandType Int16::getType() const {
	return this->type;
}

IOperand *Int16::operator+(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Int16::operator-(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Int16::operator*(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Int16::operator/(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Int16::operator%(const IOperand& rhs) const {
	return nullptr;
}
