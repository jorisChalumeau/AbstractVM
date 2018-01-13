//
// Created by cjoris on 1/13/18.
//

#include "../header/Float.h"

Float::Float(const std::string &value) {
	this->type = eOperandType::Float;
}

std::string Float::toString() const {
	return "Float";
}

eOperandType Float::getType() const {
	return this->type;
}

IOperand *Float::operator+(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Float::operator-(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Float::operator*(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Float::operator/(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Float::operator%(const IOperand& rhs) const {
	return nullptr;
}
