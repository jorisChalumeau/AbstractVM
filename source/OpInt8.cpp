//
// Created by cjoris on 1/13/18.
//

#include "../header/OpInt8.h"
#include "../header/Factory.h"
#include "../header/Exceptions.h"

OpInt8::OpInt8(const std::string &value) {
	this->type = eOperandType::Int8;
	this->string = value;
}

std::string OpInt8::toString() const {
	return this->string;
}

eOperandType OpInt8::getType() const {
	return this->type;
}

IOperand *OpInt8::operator+(const IOperand& rhs) const {
	long long result = std::stoll(string) + std::stoll(rhs.toString());
	if (result < INT8_MIN)
		throw MathError("underflow on addition");
	if (result > INT8_MAX)
		throw MathError("overflow on addition");
	return Factory::createOperand(Int8, std::to_string(result));
}

IOperand *OpInt8::operator-(const IOperand& rhs) const {
	long long result = std::stoll(string) - std::stoll(rhs.toString());
	if (result < INT8_MIN)
		throw MathError("underflow on substraction");
	if (result > INT8_MAX)
		throw MathError("overflow on substraction");
	return Factory::createOperand(Int8, std::to_string(result));
}

IOperand *OpInt8::operator*(const IOperand& rhs) const {
	long long result = std::stoll(string) * std::stoll(rhs.toString());
	if (result < INT8_MIN)
		throw MathError("underflow on multiplication");
	if (result > INT8_MAX)
		throw MathError("overflow on multiplication");
	return Factory::createOperand(Int8, std::to_string(result));
}

IOperand *OpInt8::operator/(const IOperand& rhs) const {
	if (std::stoll(rhs.toString()) == 0)
		throw ModuloOnFloat("division by 0");
	long long result = std::stoll(string) / std::stoll(rhs.toString());
	if (result < INT8_MIN)
		throw MathError("underflow on division");
	if (result > INT8_MAX)
		throw MathError("overflow on division");
	return Factory::createOperand(Int8, std::to_string(result));
}

IOperand *OpInt8::operator%(const IOperand& rhs) const {
	if (std::stoll(rhs.toString()) == 0)
		throw ModuloOnFloat("modulo by 0");
	long long result = std::stoll(string) % std::stoll(rhs.toString());
	if (result < INT8_MIN)
		throw MathError("underflow on modulo");
	if (result > INT8_MAX)
		throw MathError("overflow on modulo");
	return Factory::createOperand(Int8, std::to_string(result));
}

std::string OpInt8::typeToString() const {
    return "int8";
}
