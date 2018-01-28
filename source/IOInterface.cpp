//
// Created by apaca on 26/01/2018.
//

#include <regex>
#include "../header/IOInterface.h"
#include "../header/Exceptions.h"

IOInterface::IOInterface(Memory *memory) {
	_memory = *memory;
}

void IOInterface::ProcessFile(ifstream& file) {
	bool exit = false;
	string line;
	regex validLine(
			R"(^((pop|dump|clear|dup|swap|add|sub|mul|div|mod|print|exit|;.*)|((load|push|assert|store) *\( *(((int8|int16|int32) *, *" *[-]?[0-9]+)|((float|double|bigdecimal) *, *" *[-]?[0-9]+[.]?[0-9]*))) *" *\) *)$)");
	while (getline(file, line) && !exit) {
		if (!regex_match(line, validLine)) {
			throw IOError("Invalid line");
		}
		if (line.substr(0, 3) == "pop") {
			_memory.pop();
		} else if (line.substr(0, 4) == "dump") {
			_memory.dump();
		} else if (line.substr(0, 5) == "clear") {
			_memory.clear();
		} else if (line.substr(0, 3) == "dup") {
			_memory.dup();
		} else if (line.substr(0, 4) == "swap") {
			_memory.swap();
		} else if (line.substr(0, 3) == "add") {
			_memory.add();
		} else if (line.substr(0, 3) == "sub") {
			_memory.sub();
		} else if (line.substr(0, 3) == "mul") {
			_memory.mul();
		} else if (line.substr(0, 3) == "div") {
			_memory.div();
		} else if (line.substr(0, 3) == "mod") {
			_memory.mod();
		} else if (line.substr(0, 4) == "print") {
			_memory.print();
		} else if (line.substr(0, 5) == "exit") {
			exit = true;
		}
	}
	if (!exit) {
		throw NoExitInstruction(""); // TODO Quel message ici ?
	}
	// tests commandes memory
	// ne rien faire si commentaire (commence par ";")
//	_memory.push(Int32, "33");
//	_memory.push(Int32, "42");
//	_memory.add();
//	_memory.push(Float, "44.55");
//	_memory.mul();
//	_memory.push(Double, "42.42");
//	_memory.push(Int32, "42");
//	_memory.dump();
//	_memory.pop();
//	_memory.assert(Double, "42.42");
	// quitter le programme si "exit"
}