//
// Created by cjoris on 1/13/18.
//

#include "../header/OpInt32.h"

OpInt32::OpInt32(const std::string &value) {
	this->type = eOperandType::Int32;
}

std::string OpInt32::toString() const {
	return "OpInt32";
}

eOperandType OpInt32::getType() const {
	return this->type;
}

IOperand *OpInt32::operator+(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpInt32::operator-(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpInt32::operator*(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpInt32::operator/(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpInt32::operator%(const IOperand& rhs) const {
	return nullptr;
}
