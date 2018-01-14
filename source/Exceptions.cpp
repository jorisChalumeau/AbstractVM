//
// Created by cjoris on 1/14/18.
//

#include "../header/Exceptions.h"

DefaultException::DefaultException(std::string const& msg) : _msg(msg) {
    _msg = msg;
    _type = "";
}

DefaultException::~DefaultException() throw() {}

const char	*DefaultException::what() const throw() {
    return (_type + _msg).data();
}

OutOfBound::OutOfBound(std::string const &msg) : DefaultException(msg) {
    _type = "Index out of bound exception : ";
}

IOError::IOError(std::string const& msg) : DefaultException(msg) {
    _type = "Input/Output exception : ";
}

ParseError::ParseError(std::string const& msg) : DefaultException(msg) {
    _type = "Parsing exception : ";
}

MathError::MathError(std::string const& msg) : DefaultException(msg) {
    _type = "Math exception : ";
}

LogicError::LogicError(std::string const& msg) : DefaultException(msg) {
    _type = "Logic exception : ";
}

AssertError::AssertError(std::string const& msg) : DefaultException(msg) {
    _type = "Assertion exception : ";
}

ModuloOnFloat::ModuloOnFloat(std::string const &msg) : DefaultException(msg) {
    _type = "Modulo on non-integer error : "; // divisions par 0, etc
}

ActionOnEmptyStack::ActionOnEmptyStack(std::string const &msg) : DefaultException(msg) {
    _type = "Action on empty stack exception : ";
}

FileDoesNotExist::FileDoesNotExist(std::string const &msg) : DefaultException(msg) {
    _type = "File not found exception : ";
}