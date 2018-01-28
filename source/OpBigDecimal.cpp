//
// Created by cjoris on 1/13/18.
//

#include "../header/OpBigDecimal.h"

OpBigDecimal::OpBigDecimal(const std::string &value) {
	this->type = eOperandType::BigDecimal;
	this->string = value;
}

std::string OpBigDecimal::toString() const {
	return this->string;
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

std::string OpBigDecimal::typeToString() const {
    return "bigdecimal";
}
