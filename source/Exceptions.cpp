//
// Created by cjoris on 1/14/18.
//

#include "../header/Exceptions.h"

DefaultException::DefaultException(std::string const& msg) : _msg(msg) {
    _msg = msg;
}

DefaultException::~DefaultException() throw() {}

const char	*DefaultException::what() const throw() {
    return _msg.data();
}

OutOfBound::OutOfBound(std::string const &msg) : DefaultException("Index out of bound exception : " + msg) {}

IOError::IOError(std::string const& msg) : DefaultException("Input/Output exception : " + msg) {}

ParseError::ParseError(std::string const& msg) : DefaultException("Parsing exception : " + msg) {}

MathError::MathError(const std::string &msg) : DefaultException("Math error : " + msg) {}

LogicError::LogicError(const std::string &msg) : DefaultException("Logic error : " + msg) {}

AssertError::AssertError(std::string const& msg) : DefaultException("Assertion exception : " + msg) {}

ModuloOnFloat::ModuloOnFloat(std::string const &msg) : DefaultException("divide/modulor by 0 exception : " + msg) {}

ActionOnEmptyStack::ActionOnEmptyStack(std::string const &msg) : DefaultException("Action on empty stack exception : " + msg) {}

FileDoesNotExist::FileDoesNotExist(std::string const &msg) : DefaultException("File not found exception : " + msg) {}