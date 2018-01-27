//
// Created by cjoris on 1/13/18.
//

#ifndef UNTITLED_INT16_H
#define UNTITLED_INT16_H

#include "IOperand.h"

class OpInt16 : public IOperand {
public:
	explicit OpInt16(const std::string& value);

	std::string toString() const override;

	eOperandType getType() const override;

	IOperand *operator+(const IOperand& rhs) const override;

	IOperand *operator-(const IOperand& rhs) const override;

	IOperand *operator*(const IOperand& rhs) const override;

	IOperand *operator/(const IOperand& rhs) const override;

	IOperand *operator%(const IOperand& rhs) const override;

	~OpInt16() = default;
};


#endif //UNTITLED_INT16_H
