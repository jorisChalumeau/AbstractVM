//
// Created by cjoris on 1/13/18.
//

#ifndef UNTITLED_BIGDECIMAL_H
#define UNTITLED_BIGDECIMAL_H

#include "IOperand.h"

class OpBigDecimal : public IOperand {
public:
	OpBigDecimal(const std::string& value);

	std::string toString() const override;

	std::string typeToString() const override;

	eOperandType getType() const override;

	IOperand *operator+(const IOperand& rhs) const override;

	IOperand *operator-(const IOperand& rhs) const override;

	IOperand *operator*(const IOperand& rhs) const override;

	IOperand *operator/(const IOperand& rhs) const override;

	IOperand *operator%(const IOperand& rhs) const override;

	~OpBigDecimal() = default;
};


#endif //UNTITLED_BIGDECIMAL_H
