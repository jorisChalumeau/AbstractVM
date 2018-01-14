//
// Created by cjoris on 1/14/18.
//

#ifndef UNTITLED_EXCEPTION_H
#define UNTITLED_EXCEPTION_H

#include <exception>
#include <string>

class DefaultException : public std::exception{
protected:
    std::string _msg;
    std::string _type;

public:
    DefaultException(std::string const& msg);
    ~DefaultException() throw();

    const char *what() const throw();
};

class OutOfBound : public DefaultException {
public:
    OutOfBound(std::string const& msg);
};

class IOError : public DefaultException {
public:
    IOError(std::string const& msg);
};

class ParseError : public DefaultException {
public:
    ParseError(std::string const& msg);
};

class MathError : public DefaultException {
public:
    MathError(std::string const& msg);
};

class LogicError : public DefaultException {
public:
    LogicError(std::string const& msg);
};

class AssertError : public DefaultException {
public:
    AssertError(std::string const& msg);
};

class ModuloOnFloat: public DefaultException {
public:
    ModuloOnFloat(std::string const& msg);
};

class ActionOnEmptyStack : public DefaultException {
    ActionOnEmptyStack(std::string const& msg);
};

class FileDoesNotExist: public DefaultException {
public:
    FileDoesNotExist(std::string const& msg);
};

#endif //UNTITLED_EXCEPTION_H
