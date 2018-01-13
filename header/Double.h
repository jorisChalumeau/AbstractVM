//
// Created by cjoris on 1/13/18.
//

#ifndef UNTITLED_DOUBLE_H
#define UNTITLED_DOUBLE_H

#include "IOperand.h"

class Double : public IOperand {
public:
    Double(const std::string& value);

	std::string toString() const override;

	eOperandType getType() const override;

	IOperand *operator+(const IOperand& rhs) const override;

	IOperand *operator-(const IOperand& rhs) const override;

	IOperand *operator*(const IOperand& rhs) const override;

	IOperand *operator/(const IOperand& rhs) const override;

	IOperand *operator%(const IOperand& rhs) const override;
};


#endif //UNTITLED_DOUBLE_H
