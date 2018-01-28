//
// Created by apaca on 13/01/2018.
//

#include "../header/Memory.h"
#include "../header/Exceptions.h"
#include "../header/Factory.h"

Memory::Memory() = default;

Memory::~Memory() = default;

/**
 * add value at index registerNB of the register
 */
int Memory::addToRegister(const int& registerNB, IOperand& value) {
	if (registerNB < REG_MIN || registerNB > REG_MAX) {
		throw OutOfBound("can't add value in register " + std::to_string(registerNB) + ".");
	}
	this->registers[registerNB] = &value;
	return EXIT_SUCCESS;
}

/**
 * get value from index registerNB of the register
 */
IOperand *Memory::getRegisterValue(const int registerNB) {
	if (registerNB < REG_MIN || registerNB > REG_MAX) {
		throw OutOfBound("can't get value in register " + std::to_string(registerNB) + ".");
	}
	return this->registers[registerNB];
}

/**
 * push an element on top of the stack
 */
void Memory::push(eOperandType type, std::string value) {
	auto *op = Factory::createOperand(type, value);
	stack.push(op);
}

/**
 * pops the element on top of the stack
 */
void Memory::pop() {
	if (stack.empty())
		throw ActionOnEmptyStack("pop");
	stack.pop();
}

/**
 * clears the stack
 */
void Memory::clear() {
	while (!stack.empty())
		stack.pop();
}

/**
 * duplicate the element on top of the stack (and stack it on top of the stack)
 */
void Memory::dup() {
	if (stack.empty())
		throw ActionOnEmptyStack("dup");
	IOperand *val = stack.top();
	push(val->getType(), val->toString());
}

/**
 * swap the two elements on top of the stack
 */
void Memory::swap() {
	if (stack.empty() || stack.size() < 2)
		throw LogicError("swap impossible");
	IOperand *val1 = stack.top();
	stack.pop();
	IOperand *val2 = stack.top();
	stack.pop();
	push(val1->getType(), val1->toString());
	push(val2->getType(), val2->toString());
}

/**
 * stack the value stored in the register at the index given as parameter
 */
void Memory::load(eOperandType type, const int registerInd) {
	IOperand *op = getRegisterValue(registerInd);
	//if (op == NULL)
	//	throw NullValueRegister(" at index"+registerInd);
	push(op->getType(), op->toString());
	delete op;
}

/**
 * unstack the value then store it in the register at the index given as parameter
 */
void Memory::store(eOperandType type, const int registerInd) {
	if (stack.empty())
		throw ActionOnEmptyStack("store");
	addToRegister(registerInd, *stack.top());
	stack.pop();
}

std::stack<IOperand *> Memory::getStack() {
	return stack;
}
