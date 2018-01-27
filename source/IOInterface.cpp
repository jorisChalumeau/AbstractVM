//
// Created by apaca on 26/01/2018.
//

#include <regex>
#include "../header/IOInterface.h"
#include "../header/Memory.h"

IOInterface::IOInterface(Memory *memory){
	_memory = *memory;
}

void IOInterface::ProcessFile(ifstream& file) {
	string line;
	regex N("[ -]?[0..9]+");
	regex Z("[ -]?[0..9]+[.]?[0..9]*");
	while (getline(file, line)) {
		
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