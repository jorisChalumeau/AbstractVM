//
// Created by cjoris on 1/13/18.
//

#ifndef UNTITLED_FLOAT_H
#define UNTITLED_FLOAT_H

#include "IOperand.h"

class Float : public IOperand {
public:
    Float(const std::string& value);

	std::string toString() const override;

	eOperandType getType() const override;

	IOperand *operator+(const IOperand& rhs) const override;

	IOperand *operator-(const IOperand& rhs) const override;

	IOperand *operator*(const IOperand& rhs) const override;

	IOperand *operator/(const IOperand& rhs) const override;

	IOperand *operator%(const IOperand& rhs) const override;
};


#endif //UNTITLED_FLOAT_H
