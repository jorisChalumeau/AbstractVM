//
// Created by apaca on 12/01/2018.
//

#ifndef IOPERAND_H
#define IOPERAND_H

#include <string>
#include <climits>
#include <cfloat>

enum eOperandType {Int8, Int16, Int32, Float, Double, BigDecimal}; // precision order

class IOperand {
public :
	virtual std::string toString() const = 0; // string that represents the instance
	virtual std::string typeToString() const = 0;
	virtual eOperandType getType() const = 0; // returns the type of instance
	virtual IOperand *operator+(const IOperand& rhs) const = 0; // sum
	virtual IOperand *operator-(const IOperand& rhs) const = 0; // difference
	virtual IOperand *operator*(const IOperand& rhs) const = 0; // product
	virtual IOperand *operator/(const IOperand& rhs) const = 0; // quotient
	virtual IOperand *operator%(const IOperand& rhs) const = 0; // modulo

	virtual ~IOperand() = default;

    std::string withoutTrailingZeros() const {
        std::string str(string);
        auto ind = str.length() - 1;
        if (str.find('.')) {
            for (ind; ind >= 0; ind--) {
                if (str[ind] == '0' || str[ind] == '.')
                    str.erase(str.end() - 1);
                else
                    break;
            }
        }
        return str;
    }

protected:
	eOperandType type;
	std::string string;
};


#endif //IOPERAND_H