//
// Created by apaca on 12/01/2018.
//

#ifndef IOPERAND_H
#define IOPERAND_H

#include <string>

enum eOperandType {Int8, Int16, Int32, Float, Double, BigDecimal}; // precision order

class IOperand {
public :
	virtual std::string toString() const = 0; // string that represents the instance
	virtual eOperandType getType() const = 0; // returns the type of instance
	virtual IOperand *operator+(const IOperand& rhs) const = 0; // sum
	virtual IOperand *operator-(const IOperand& rhs) const = 0; // difference
	virtual IOperand *operator*(const IOperand& rhs) const = 0; // product
	virtual IOperand *operator/(const IOperand& rhs) const = 0; // quotient
	virtual IOperand *operator%(const IOperand& rhs) const = 0; // modulo

	virtual ~IOperand() = default;

protected:
	eOperandType type;
};


#endif //IOPERAND_H