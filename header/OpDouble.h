//
// Created by cjoris on 1/13/18.
//

#ifndef UNTITLED_DOUBLE_H
#define UNTITLED_DOUBLE_H

#include "IOperand.h"

class OpDouble : public IOperand {
public:
	OpDouble(const std::string& value);

	std::string toString() const override;

	std::string typeToString() const override;

	eOperandType getType() const override;

	IOperand *operator+(const IOperand& rhs) const override;

	IOperand *operator-(const IOperand& rhs) const override;

	IOperand *operator*(const IOperand& rhs) const override;

	IOperand *operator/(const IOperand& rhs) const override;

	IOperand *operator%(const IOperand& rhs) const override;

	~OpDouble() = default;
};


#endif //UNTITLED_DOUBLE_H
