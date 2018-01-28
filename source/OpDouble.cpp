//
// Created by cjoris on 1/13/18.
//

#include "../header/OpDouble.h"

OpDouble::OpDouble(const std::string &value) {
	this->type = eOperandType::Double;
	this->string = value;
}

std::string OpDouble::toString() const {
	return this->string;
}

eOperandType OpDouble::getType() const {
	return this->type;
}

IOperand *OpDouble::operator+(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpDouble::operator-(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpDouble::operator*(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpDouble::operator/(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpDouble::operator%(const IOperand& rhs) const {
	return nullptr;
}

std::string OpDouble::typeToString() const {
    return "double";
}
