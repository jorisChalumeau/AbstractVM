//
// Created by cjoris on 1/13/18.
//

#ifndef UNTITLED_INT8_H
#define UNTITLED_INT8_H

#include "IOperand.h"

class OpInt8 : public IOperand {
public:
	explicit OpInt8(const std::string& value);

	std::string toString() const override;

    std::string typeToString() const override;

	eOperandType getType() const override;

	IOperand *operator+(const IOperand& rhs) const override;

	IOperand *operator-(const IOperand& rhs) const override;

	IOperand *operator*(const IOperand& rhs) const override;

	IOperand *operator/(const IOperand& rhs) const override;

	IOperand *operator%(const IOperand& rhs) const override;

	~OpInt8() = default;
};


#endif //UNTITLED_INT8_H
