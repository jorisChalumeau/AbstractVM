//
// Created by cjoris on 1/13/18.
//

#include "../header/OpInt16.h"

OpInt16::OpInt16(const std::string &value) {
	this->type = eOperandType::Int16;
	this->string = value;
}

std::string OpInt16::toString() const {
	return this->string;
}

eOperandType OpInt16::getType() const {
	return this->type;
}

IOperand *OpInt16::operator+(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpInt16::operator-(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpInt16::operator*(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpInt16::operator/(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpInt16::operator%(const IOperand& rhs) const {
	return nullptr;
}

std::string OpInt16::typeToString() const {
    return "int16";
}
