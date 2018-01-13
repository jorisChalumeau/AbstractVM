//
// Created by cjoris on 1/13/18.
//

#include "../header/OpBigDecimal.h"

OpBigDecimal::OpBigDecimal(const std::string &value) {
	this->type = eOperandType::BigDecimal;
}

std::string OpBigDecimal::toString() const {
	return "OpBigDecimal";
}

eOperandType OpBigDecimal::getType() const {
	return this->type;
}

IOperand *OpBigDecimal::operator+(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpBigDecimal::operator-(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpBigDecimal::operator*(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpBigDecimal::operator/(const IOperand& rhs) const {
	return nullptr;
}

IOperand *OpBigDecimal::operator%(const IOperand& rhs) const {
	return nullptr;
}
