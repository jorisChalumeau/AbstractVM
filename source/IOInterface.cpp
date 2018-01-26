//
// Created by apaca on 26/01/2018.
//

#include <regex>
#include "../header/IOInterface.h"

IOInterface::IOInterface() = default;

void IOInterface::ProcessFile(ifstream& file) {
	string line;
	regex N("[ -]?[0..9]+");
	regex Z("[ -]?[0..9]+[.]?[0..9]*");
	while (getline(file, line)) {
		
	}
}