//
// Created by cjoris on 1/13/18.
//

#include <iostream>
#include "../header/OpInt32.h"
#include "../header/Exceptions.h"
#include "../header/Factory.h"

OpInt32::OpInt32(const std::string &value) {
	this->type = eOperandType::Int32;
	this->string = value;
}

std::string OpInt32::toString() const {
	return this->string;
}

eOperandType OpInt32::getType() const {
	return this->type;
}

IOperand *OpInt32::operator+(const IOperand& rhs) const {
	long long result = std::stoll(string) + std::stoll(rhs.toString());
	if (result < INT32_MIN)
		throw MathError("underflow on addition");
	if (result > INT32_MAX)
		throw MathError("overflow on addition");
	return Factory::createOperand(Int32, std::to_string(result));
}

IOperand *OpInt32::operator-(const IOperand& rhs) const {
	long long result = std::stoll(string) - std::stoll(rhs.toString());
	if (result < INT32_MIN)
		throw MathError("underflow on substraction");
	if (result > INT32_MAX)
		throw MathError("overflow on substraction");
	return Factory::createOperand(Int32, std::to_string(result));
}

IOperand *OpInt32::operator*(const IOperand& rhs) const {
	long long result = std::stoll(string) * std::stoll(rhs.toString());
	if (result < INT32_MIN)
		throw MathError("underflow on multiplication");
	if (result > INT32_MAX)
		throw MathError("overflow on multiplication");
	return Factory::createOperand(Int32, std::to_string(result));
}

IOperand *OpInt32::operator/(const IOperand& rhs) const {
	if (std::stoll(rhs.toString()) == 0)
		throw ModuloOnFloat("division by 0");
	long long result = std::stoll(string) / std::stoll(rhs.toString());
	if (result < INT32_MIN)
		throw MathError("underflow on division");
	if (result > INT32_MAX)
		throw MathError("overflow on division");
	return Factory::createOperand(Int32, std::to_string(result));
}

IOperand *OpInt32::operator%(const IOperand& rhs) const {
	if (std::stoll(rhs.toString()) == 0)
		throw ModuloOnFloat("modulo by 0");
	long long result = std::stoll(string) % std::stoll(rhs.toString());
	if (result < INT32_MIN)
		throw MathError("underflow on modulo");
	if (result > INT32_MAX)
		throw MathError("overflow on modulo");
	return Factory::createOperand(Int32, std::to_string(result));
}

std::string OpInt32::typeToString() const {
    return "int32";
}
