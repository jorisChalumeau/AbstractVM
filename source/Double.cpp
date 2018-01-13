//
// Created by cjoris on 1/13/18.
//

#include "../header/Double.h"

Double::Double(const std::string &value) {
	this->type = eOperandType::Double;
}

std::string Double::toString() const {
	return "Double";
}

eOperandType Double::getType() const {
	return this->type;
}

IOperand *Double::operator+(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Double::operator-(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Double::operator*(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Double::operator/(const IOperand& rhs) const {
	return nullptr;
}

IOperand *Double::operator%(const IOperand& rhs) const {
	return nullptr;
}
