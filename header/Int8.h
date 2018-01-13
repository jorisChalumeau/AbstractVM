//
// Created by cjoris on 1/13/18.
//

#ifndef UNTITLED_INT8_H
#define UNTITLED_INT8_H

#include "IOperand.h"

class Int8 : public IOperand {
public:
    Int8(const std::string& value);

	std::string toString() const override;

	eOperandType getType() const override;

	IOperand *operator+(const IOperand& rhs) const override;

	IOperand *operator-(const IOperand& rhs) const override;

	IOperand *operator*(const IOperand& rhs) const override;

	IOperand *operator/(const IOperand& rhs) const override;

	IOperand *operator%(const IOperand& rhs) const override;
};


#endif //UNTITLED_INT8_H
