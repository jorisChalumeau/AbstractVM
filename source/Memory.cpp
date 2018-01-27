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
int Memory::addToRegister(const int registerNB, IOperand &value) {
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
	std::cout << ""+type << value << std::endl;
	IOperand *op = Factory::createOperand(type, value);
	stack.push(*op);
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
	IOperand *val = &stack.top();
	push(val->getType(), val->toString());
}

/**
 * swap the two elements on top of the stack
 */
void Memory::swap() {
	if (stack.empty() || stack.size() < 2)
		throw LogicError(" swap impossible");
	IOperand *val1 = &stack.top();
	stack.pop();
	IOperand *val2 = &stack.top();
	stack.pop();
	push(val1->getType(), val1->toString());
	push(val2->getType(), val2->toString());
}

/**
 * displays each value on the stack (from top to bottom)
 */
void Memory::dump() {
	std::stack<IOperand> cloneStack(stack);
	while (!cloneStack.empty()) {
		std::cout << cloneStack.top().toString() << std::endl;
		cloneStack.pop();
	}
}

/**
 * asserts parameter is identical to the value on top of the stack, else throw assert error
 */
void Memory::assert(const eOperandType type, const std::string value) {
	if (stack.empty())
		throw ActionOnEmptyStack("assert");
	IOperand *op = &stack.top();
	if (op->getType() != type || op->toString() != value)
		throw AssertError(value+" is different from "+op->toString()+"(from the stack)");
}

/**
 * pop the 2 values on top of the stack, add them and then stack the result
 */
void Memory::add() {
	if (stack.empty() || stack.size() < 2)
		throw LogicError(" addition impossible");
	IOperand *op1 = &stack.top();
	stack.pop();
	IOperand *op2 = &stack.top();
	stack.pop();
	if (op1->getType() > op2->getType())
		op2 = Factory::createOperand(op1->getType(), op2->toString());
	if (op1->getType() < op2->getType())
		op1 = Factory::createOperand(op2->getType(), op1->toString());
	op1 = (*op1 + *op2); // throw underflow / overflow exceptions
	push(op1->getType(), op1->toString());
}

/**
 * pop the 2 values on top of the stack, sub them and then stack the result
 */
void Memory::sub() {
	if (stack.empty() || stack.size() < 2)
		throw LogicError(" substraction impossible");
	IOperand *op1 = &stack.top();
	stack.pop();
	IOperand *op2 = &stack.top();
	stack.pop();
	if (op1->getType() > op2->getType())
		op2 = Factory::createOperand(op1->getType(), op2->toString());
	if (op1->getType() < op2->getType())
		op1 = Factory::createOperand(op2->getType(), op1->toString());
	op1 = (*op1 - *op2); // throw underflow / overflow exceptions
	push(op1->getType(), op1->toString());
}

/**
 * pop the 2 values on top of the stack, mul them and then stack the result
 */
void Memory::mul() {
	if (stack.empty() || stack.size() < 2)
		throw LogicError(" multiplication impossible");
	IOperand *op1 = &stack.top();
	stack.pop();
	IOperand *op2 = &stack.top();
	stack.pop();
	if (op1->getType() > op2->getType())
		op2 = Factory::createOperand(op1->getType(), op2->toString());
	if (op1->getType() < op2->getType())
		op1 = Factory::createOperand(op2->getType(), op1->toString());
	op1 = (*op1 * *op2); // throw underflow / overflow exceptions
	push(op1->getType(), op1->toString());
}

/**
 * pop the 2 values on top of the stack, div them and then stack the result
 */
void Memory::div() {
	if (stack.empty() || stack.size() < 2)
		throw LogicError(" division impossible");
	IOperand *op1 = &stack.top();
	stack.pop();
	IOperand *op2 = &stack.top();
	stack.pop();
	if (op1->getType() > op2->getType())
		op2 = Factory::createOperand(op1->getType(), op2->toString());
	if (op1->getType() < op2->getType())
		op1 = Factory::createOperand(op2->getType(), op1->toString());
	op1 = (*op1 / *op2); // throw underflow / overflow exceptions
	push(op1->getType(), op1->toString());
}

/**
 * pop the 2 values on top of the stack, mod them and then stack the result
 */
void Memory::mod() {
	if (stack.empty() || stack.size() < 2)
		throw LogicError(" modulo impossible");
	IOperand *op1 = &stack.top();
	stack.pop();
	IOperand *op2 = &stack.top();
	stack.pop();
	if (op1->getType() > op2->getType())
		op2 = Factory::createOperand(op1->getType(), op2->toString());
	if (op1->getType() < op2->getType())
		op1 = Factory::createOperand(op2->getType(), op1->toString());
	op1 = (*op1 % *op2); // throw underflow / overflow exceptions
	push(op1->getType(), op1->toString());
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
	addToRegister(registerInd, stack.top());
	stack.pop();
}

/**
 * prints the value on top of the stack as an ASCII character (only if it's and int8)
 */
void Memory::print() {
	if (stack.empty())
		throw ActionOnEmptyStack("print");
	IOperand *op = &stack.top();
	if (op->getType() == Int8 && std::stoi(op->toString()) >= 0)
		printf("%c", std::stoi(op->toString()));
}