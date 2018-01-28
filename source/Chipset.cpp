//
// Created by cjoris on 1/28/18.
//

#include "../header/Chipset.h"

Chipset::Chipset(Cpu *cpu) : _cpu(*cpu) {}

Chipset::~Chipset() = default;

char Chipset::print() {
    return _cpu.print();
}

std::string Chipset::dump() {
    return _cpu.dump();
}

void Chipset::executeAction(eCommandType action) {
    switch (action){
        case ADD:
            _cpu.add();
            break;
        case SUB:
            _cpu.sub();
            break;
        case MUL:
            _cpu.mul();
            break;
        case DIV:
            _cpu.div();
            break;
        case MOD:
            _cpu.mod();
            break;
        default: // POP, DUP, SWAP, CLEAR
            _cpu.memoryAction(action);
    }
}

void Chipset::executeAction(eCommandType action, const std::string type, const std::string value) {
    eOperandType t;
    if (type == "int8")
        t = Int8;
    else if (type == "int16")
        t = Int16;
    else if (type == "int32")
        t = Int32;
    else if (type == "float")
        t = Float;
    else if (type == "double")
        t = Double;
    else
        t = BigDecimal;

    switch (action){
        case PUSH:
            _cpu.push(t, value);
            break;
        case LOAD:
            _cpu.load(t, value);
            break;
        case STORE:
            _cpu.store(t, value);
            break;
        default: // ASSERT
            _cpu.assert(t, value);
    }
}
