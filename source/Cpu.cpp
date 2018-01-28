//
// Created by cjoris on 1/28/18.
//

#include "../header/Chipset.h"
#include "../header/Exceptions.h"
#include "../header/Factory.h"

Cpu::Cpu(Memory *memory) : _memory(*memory) {}

Cpu::~Cpu() = default;

/**
 * displays each value on the stack (from top to bottom)
 */
std::string Cpu::dump() {
    std::string msg;
    std::stack<IOperand *> cloneStack(_memory.getStack());
    while (!cloneStack.empty()) {
        msg.append(cloneStack.top()->toString()+"\n");
        cloneStack.pop();
    }
    return msg;
}

/**
 * prints the value on top of the stack as an ASCII character (only if it's and int8)
 */
char Cpu::print() {
    if (_memory.getStack().empty())
        throw ActionOnEmptyStack("print");
    IOperand *op = _memory.getStack().top();
    assert(Int8, op->toString());
    if (op->toString().substr(0,1) == "-")
        throw AssertError("can't display a negative int8 as an ASCII character (0-127)");
    return (char)std::stoi(op->toString());
}

/**
 * memory actions
 */
void Cpu::memoryAction(eCommandType action) {
    switch(action){
        case POP:
            _memory.pop();
            break;
        case DUP:
            _memory.dup();
        case SWAP:
            _memory.swap();
        default: // CLEAR
            _memory.clear();
    }
}

/**
 * asserts parameter is identical to the value on top of the stack, else throw assert error
 */
void Cpu::assert(eOperandType type, std::string value) {
    if (_memory.getStack().empty())
        throw ActionOnEmptyStack("assert");
    IOperand *t_op = Factory::createOperand(type, value);
    IOperand *op = _memory.getStack().top();
    if (op->getType() != type || op->toString() != value)
        throw AssertError(value + " of type " + t_op->typeToString() + " is different from "
                          + op->toString() + " of type" + op->typeToString() + " (from the stack)");
}

/**
 * push value into stack
 */
void Cpu::push(eOperandType type, const std::string value) {
    _memory.push(type, value);
}

/**
 * copy value from register[index] into stack
 */
void Cpu::load(eOperandType type, const std::string index) {
    _memory.load(type, std::stoi(index));
}

/**
 * move value from stack into register[index]
 */
void Cpu::store(eOperandType type, const std::string index) {
    _memory.store(type, std::stoi(index));
}

/**
 * pop the 2 values on top of the stack, add them and then stack the result
 */
void Cpu::add() {
    if (_memory.getStack().empty() || _memory.getStack().size() < 2)
        throw LogicError("addition impossible");
    IOperand *op1 = _memory.getStack().top();
    _memory.pop();
    IOperand *op2 = _memory.getStack().top();
    _memory.pop();
    if (op1->getType() > op2->getType())
        op2 = Factory::createOperand(op1->getType(), op2->toString());
    if (op1->getType() < op2->getType())
        op1 = Factory::createOperand(op2->getType(), op1->toString());
    op1 = (*op1 + *op2); // throw underflow / overflow exceptions
    _memory.push(op1->getType(), op1->toString());
}

/**
 * pop the 2 values on top of the stack, sub them and then stack the result
 */
void Cpu::sub() {
    if (_memory.getStack().empty() || _memory.getStack().size() < 2)
        throw LogicError("substraction impossible");
    IOperand *op1 = _memory.getStack().top();
    _memory.pop();
    IOperand *op2 = _memory.getStack().top();
    _memory.pop();
    if (op1->getType() > op2->getType())
        op2 = Factory::createOperand(op1->getType(), op2->toString());
    if (op1->getType() < op2->getType())
        op1 = Factory::createOperand(op2->getType(), op1->toString());
    op1 = (*op1 - *op2); // throw underflow / overflow exceptions
    _memory.push(op1->getType(), op1->toString());
}

/**
 * pop the 2 values on top of the stack, mul them and then stack the result
 */
void Cpu::mul() {
    if (_memory.getStack().empty() || _memory.getStack().size() < 2)
        throw LogicError("multiplication impossible");
    IOperand *op1 = _memory.getStack().top();
    _memory.pop();
    IOperand *op2 = _memory.getStack().top();
    _memory.pop();
    if (op1->getType() > op2->getType())
        op2 = Factory::createOperand(op1->getType(), op2->toString());
    if (op1->getType() < op2->getType())
        op1 = Factory::createOperand(op2->getType(), op1->toString());
    op1 = (*op1 * *op2); // throw underflow / overflow exceptions
    _memory.push(op1->getType(), op1->toString());
}

/**
 * pop the 2 values on top of the stack, div them and then stack the result
 */
void Cpu::div() {
    if (_memory.getStack().empty() || _memory.getStack().size() < 2)
        throw LogicError("division impossible");
    IOperand *op1 = _memory.getStack().top();
    _memory.pop();
    IOperand *op2 = _memory.getStack().top();
    _memory.pop();
    if (op1->getType() > op2->getType())
        op2 = Factory::createOperand(op1->getType(), op2->toString());
    if (op1->getType() < op2->getType())
        op1 = Factory::createOperand(op2->getType(), op1->toString());
    op1 = (*op1 / *op2); // throw underflow / overflow exceptions
    _memory.push(op1->getType(), op1->toString());
}

/**
 * pop the 2 values on top of the stack, mod them and then stack the result
 */
void Cpu::mod() {
    if (_memory.getStack().empty() || _memory.getStack().size() < 2)
        throw LogicError("mod impossible");
    IOperand *op1 = _memory.getStack().top();
    _memory.pop();
    IOperand *op2 = _memory.getStack().top();
    _memory.pop();
    if (op1->getType() > op2->getType())
        op2 = Factory::createOperand(op1->getType(), op2->toString());
    if (op1->getType() < op2->getType())
        op1 = Factory::createOperand(op2->getType(), op1->toString());
    op1 = (*op1 % *op2); // throw underflow / overflow exceptions
    _memory.push(op1->getType(), op1->toString());
}
