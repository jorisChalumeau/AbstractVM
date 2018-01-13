//
// Created by cjoris on 1/13/18.
//

#include "../header/OpFloat.h"

OpFloat::OpFloat(const std::string &value) {
	this->type = eOperandType::Float;
}

std::string OpFloat::toString() const {
	return "OpFloat";
}

eOperandType OpFloat::getType() const {
	return this->type;
}

IOperand *OpFloat::operator+(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpFloat::operator-(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpFloat::operator*(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpFloat::operator/(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpFloat::operator%(const IOperand& rhs) const {
	return nullptr;
}
