//
// Created by cjoris on 1/13/18.
//

#include "../header/BigDecimal.h"

BigDecimal::BigDecimal(const std::string &value) {
	this->type = eOperandType::BigDecimal;
}

std::string BigDecimal::toString() const {
	return "BigDecimal";
}

eOperandType BigDecimal::getType() const {
	return this->type;
}

IOperand *BigDecimal::operator+(const IOperand& rhs) const {
	return nullptr;
}

IOperand *BigDecimal::operator-(const IOperand& rhs) const {
	return nullptr;
}

IOperand *BigDecimal::operator*(const IOperand& rhs) const {
	return nullptr;
}

IOperand *BigDecimal::operator/(const IOperand& rhs) const {
	return nullptr;
}

IOperand *BigDecimal::operator%(const IOperand& rhs) const {
	return nullptr;
}
