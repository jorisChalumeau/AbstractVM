//
// Created by cjoris on 1/13/18.
//

#include "../header/OpFloat.h"

OpFloat::OpFloat(const std::string &value) {
	this->type = eOperandType::Float;
	this->string = value;
}

std::string OpFloat::toString() const {
	return this->string;
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

std::string OpFloat::typeToString() const {
    return "float";
}
