//
// Created by cjoris on 1/13/18.
//

#ifndef UNTITLED_BIGDECIMAL_H
#define UNTITLED_BIGDECIMAL_H

#include "IOperand.h"

class BigDecimal : public IOperand {
public:
    BigDecimal(const std::string& value);
};


#endif //UNTITLED_BIGDECIMAL_H
