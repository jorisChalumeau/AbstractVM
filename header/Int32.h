//
// Created by cjoris on 1/13/18.
//

#ifndef UNTITLED_INT32_H
#define UNTITLED_INT32_H

#include "IOperand.h"

class Int32 : public IOperand {
public:
    Int32(const std::string& value);

	std::string toString() const override;

	eOperandType getType() const override;

	IOperand *operator+(const IOperand& rhs) const override;

	IOperand *operator-(const IOperand& rhs) const override;

	IOperand *operator*(const IOperand& rhs) const override;

	IOperand *operator/(const IOperand& rhs) const override;

	IOperand *operator%(const IOperand& rhs) const override;
};


#endif //UNTITLED_INT32_H
