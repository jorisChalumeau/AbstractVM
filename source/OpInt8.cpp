//
// Created by cjoris on 1/13/18.
//

#include "../header/OpInt8.h"

OpInt8::OpInt8(const std::string &value) {
	this->type = eOperandType::Int8;
}

std::string OpInt8::toString() const {
	return "OpInt8";
}

eOperandType OpInt8::getType() const {
	return this->type;
}

IOperand *OpInt8::operator+(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpInt8::operator-(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpInt8::operator*(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpInt8::operator/(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpInt8::operator%(const IOperand& rhs) const {
	return nullptr;
}
