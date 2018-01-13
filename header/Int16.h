//
// Created by cjoris on 1/13/18.
//

#ifndef UNTITLED_INT16_H
#define UNTITLED_INT16_H

#include "IOperand.h"

class Int16 : public IOperand {
public:
    Int16(const std::string& value);

	std::string toString() const override;

	eOperandType getType() const override;

	IOperand *operator+(const IOperand& rhs) const override;

	IOperand *operator-(const IOperand& rhs) const override;

	IOperand *operator*(const IOperand& rhs) const override;

	IOperand *operator/(const IOperand& rhs) const override;

	IOperand *operator%(const IOperand& rhs) const override;
};


#endif //UNTITLED_INT16_H
