//
// Created by cjoris on 1/13/18.
//

#include "../header/OpBigDecimal.h"
#include "../header/Exceptions.h"
#include "../header/Factory.h"

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
	if (withoutTrailingZeros().length() > 200 || rhs.withoutTrailingZeros().length() > 200)
		throw MathError("underflow or overflow on addition");
	return Factory::createOperand(BigDecimal, string);
}

IOperand *OpBigDecimal::operator-(const IOperand& rhs) const {
	if (withoutTrailingZeros().length() > 200 || rhs.withoutTrailingZeros().length() > 200)
		throw MathError("underflow or overflow on addition");
	return Factory::createOperand(BigDecimal, string);
}

IOperand *OpBigDecimal::operator*(const IOperand& rhs) const {
	if (withoutTrailingZeros().length() > 200 || rhs.withoutTrailingZeros().length() > 200)
		throw MathError("underflow or overflow on addition");
	return Factory::createOperand(BigDecimal, string);
}

IOperand *OpBigDecimal::operator/(const IOperand& rhs) const {
	if (std::stoll(rhs.withoutTrailingZeros()) == 0)
		throw ModuloOnFloat("division by 0");
	if (withoutTrailingZeros().length() > 200 || rhs.withoutTrailingZeros().length() > 200)
		throw MathError("underflow or overflow on addition");
	return Factory::createOperand(BigDecimal, string);
}

IOperand *OpBigDecimal::operator%(const IOperand& rhs) const {
	if (std::stoll(rhs.withoutTrailingZeros()) == 0)
		throw ModuloOnFloat("modulo by 0");
	if (withoutTrailingZeros().length() > 200 || rhs.withoutTrailingZeros().length() > 200)
		throw MathError("underflow or overflow on addition");
	return Factory::createOperand(BigDecimal, string);
}

std::string OpBigDecimal::typeToString() const {
    return "bigdecimal";
}