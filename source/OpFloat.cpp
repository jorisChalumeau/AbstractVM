//
// Created by cjoris on 1/13/18.
//

#include <cmath>
#include "../header/OpFloat.h"
#include "../header/Exceptions.h"
#include "../header/Factory.h"

OpFloat::OpFloat(const std::string &value) {
	this->type = eOperandType::Float;
	this->string = value;
}

std::string OpFloat::toString() const {
	return this->string;
}

eOperandType OpFloat::getType() const {
	return this->type;
}

IOperand *OpFloat::operator+(const IOperand& rhs) const {
    long double result = std::stold(string) + std::stold(rhs.toString());
    if (result < -FLT_MAX)
        throw MathError("underflow on addition");
    if (result > FLT_MAX)
        throw MathError("overflow on addition");
    return Factory::createOperand(Float, std::to_string(result));
}

IOperand *OpFloat::operator-(const IOperand& rhs) const {
    long double result = std::stold(string) - std::stold(rhs.toString());
    if (result < -FLT_MAX)
        throw MathError("underflow on substraction");
    if (result > FLT_MAX)
        throw MathError("overflow on substraction");
    return Factory::createOperand(Float, std::to_string(result));
}

IOperand *OpFloat::operator*(const IOperand& rhs) const {
    long double result = std::stold(string) * std::stold(rhs.toString());
    if (result < -FLT_MAX)
        throw MathError("underflow on multiplication");
    if (result > FLT_MAX)
        throw MathError("overflow on multiplication");
    return Factory::createOperand(Float, std::to_string(result));
}

IOperand *OpFloat::operator/(const IOperand& rhs) const {
    if (std::stoll(rhs.withoutTrailingZeros()) == 0)
        throw ModuloOnFloat("division by 0");
    long double result = std::stold(string) / std::stold(rhs.toString());
    if (result < -FLT_MAX)
        throw MathError("underflow on division");
    if (result > FLT_MAX)
        throw MathError("overflow on division");
    return Factory::createOperand(Float, std::to_string(result));
}

IOperand *OpFloat::operator%(const IOperand& rhs) const {
    if (std::stoll(rhs.withoutTrailingZeros()) == 0)
        throw ModuloOnFloat("modulo by 0");
    long double result = fmod(std::stoll(string), std::stoll(rhs.toString()));
    if (result < -FLT_MAX)
        throw MathError("underflow on modulo");
    if (result > FLT_MAX)
        throw MathError("overflow on modulo");
    return Factory::createOperand(Float, std::to_string(result));
}

std::string OpFloat::typeToString() const {
    return "float";
}
