//
// Created by cjoris on 1/13/18.
//

#include "../header/OpInt16.h"

OpInt16::OpInt16(const std::string &value) {
	this->type = eOperandType::Int16;
}

std::string OpInt16::toString() const {
	return "OpInt16";
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
