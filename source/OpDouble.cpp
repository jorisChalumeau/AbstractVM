//
// Created by cjoris on 1/13/18.
//

#include <cmath>
#include "../header/OpDouble.h"
#include "../header/Factory.h"
#include "../header/Exceptions.h"

OpDouble::OpDouble(const std::string &value) {
	this->type = eOperandType::Double;
	this->string = value;
}

std::string OpDouble::toString() const {
	return this->string;
}

eOperandType OpDouble::getType() const {
	return this->type;
}

IOperand *OpDouble::operator+(const IOperand& rhs) const {
    long double result = std::stold(string) + std::stold(rhs.toString());
    if (result < -DBL_MAX)
        throw MathError("underflow on addition");
    if (result > DBL_MAX)
        throw MathError("overflow on addition");
    return Factory::createOperand(Double, std::to_string(result));
}

IOperand *OpDouble::operator-(const IOperand& rhs) const {
    long double result = std::stold(string) - std::stold(rhs.toString());
    if (result < -DBL_MAX)
        throw MathError("underflow on substraction");
    if (result > DBL_MAX)
        throw MathError("overflow on substraction");
    return Factory::createOperand(Double, std::to_string(result));
}

IOperand *OpDouble::operator*(const IOperand& rhs) const {
    long double result = std::stold(string) * std::stold(rhs.toString());
    if (result < -DBL_MAX)
        throw MathError("underflow on multiplication");
    if (result > DBL_MAX)
        throw MathError("overflow on multiplication");
    return Factory::createOperand(Double, std::to_string(result));
}

IOperand *OpDouble::operator/(const IOperand& rhs) const {
    if (std::stoll(rhs.withoutTrailingZeros()) == 0)
        throw ModuloOnFloat("division by 0");
    long double result = std::stold(string) / std::stold(rhs.toString());
    if (result < -DBL_MAX)
        throw MathError("underflow on division");
    if (result > DBL_MAX)
        throw MathError("overflow on division");
    return Factory::createOperand(Double, std::to_string(result));
}

IOperand *OpDouble::operator%(const IOperand& rhs) const {
    if (std::stoll(rhs.withoutTrailingZeros()) == 0)
        throw ModuloOnFloat("modulo by 0");
    long double result = fmod(std::stoll(string), std::stoll(rhs.toString()));
    if (result < -DBL_MAX)
        throw MathError("underflow on modulo");
    if (result > DBL_MAX)
        throw MathError("overflow on modulo");
    return Factory::createOperand(Double, std::to_string(result));
}

std::string OpDouble::typeToString() const {
    return "double";
}
