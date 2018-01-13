//
// Created by cjoris on 1/13/18.
//

#include "../header/Int32.h"

Int32::Int32(const std::string &value) {
	this->type = eOperandType::Int32;
}

std::string Int32::toString() const {
	return "Int32";
}

eOperandType Int32::getType() const {
	return this->type;
}

IOperand *Int32::operator+(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Int32::operator-(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Int32::operator*(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Int32::operator/(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Int32::operator%(const IOperand& rhs) const {
	return nullptr;
}
