//
// Created by apaca on 26/01/2018.
//

#include <regex>
#include "../header/IOInterface.h"
#include "../header/Exceptions.h"

IOInterface::IOInterface(Chipset *chipset): _chipset(*chipset) {}

IOInterface::~IOInterface() = default;

void IOInterface::ProcessFile(ifstream& file) {
	bool exit = false;
	string line;
	int lineCount = 0;
	unsigned long nextSpace;
	regex validLine(
			R"(^ *((pop|dump|clear|dup|swap|add|sub|mul|div|mod|print|exit|;.*)|((load|push|assert|store) *(((int8|int16|int32) *\( *[-]?[0-9]+ *\))|((float|double|bigdecimal) *\( *[-]?[0-9]+[.]?[0-9]* *\))))) *$)");
	while (getline(file, line) && !exit) {
		++lineCount;
		if (!regex_match(line, validLine)) {
			throw IOError("Invalid line : " + to_string(lineCount));
		}
		line = trim(line);
		try {
			if (line.substr(0, 3) == "pop") {
				_chipset.executeAction(POP);
			} else if (line.substr(0, 5) == "clear") {
				_chipset.executeAction(CLEAR);
			} else if (line.substr(0, 3) == "dup") {
				_chipset.executeAction(DUP);
			} else if (line.substr(0, 4) == "swap") {
				_chipset.executeAction(SWAP);
			} else if (line.substr(0, 3) == "add") {
				_chipset.executeAction(ADD);
			} else if (line.substr(0, 3) == "sub") {
				_chipset.executeAction(SUB);
			} else if (line.substr(0, 3) == "mul") {
				_chipset.executeAction(MUL);
			} else if (line.substr(0, 3) == "div") {
				_chipset.executeAction(DIV);
			} else if (line.substr(0, 3) == "mod") {
				_chipset.executeAction(MOD);
			} else if (line.substr(0, 5) == "print") {
				printf("%c\n", _chipset.print());
			} else if (line.substr(0, 4) == "dump") {
				cout << _chipset.dump();
			} else if (line.substr(0, 4) == "exit") {
				exit = true;
			} else if (line.substr(0, 1) == ";" && line.substr(1, 2) != ";") {
				// ligne complete en commentaire, rien a faire
			} else if (line.substr(0, 4) == "load") {
				line = trim(line.substr(4, line.length()));
				nextSpace = line.find_first_of(' ');
				_chipset.executeAction(LOAD, line.substr(0, nextSpace),
									   rmvParenthesis(trim(line.substr(nextSpace, line.length()))));
			} else if (line.substr(0, 5) == "store") {
				line = trim(line.substr(5, line.length()));
				nextSpace = line.find_first_of(' ');
				_chipset.executeAction(STORE, line.substr(0, nextSpace),
									   rmvParenthesis(trim(line.substr(nextSpace, line.length()))));
			} else if (line.substr(0, 4) == "push") {
				line = trim(line.substr(4, line.length()));
				nextSpace = line.find_first_of(' ');
				_chipset.executeAction(PUSH, line.substr(0, nextSpace),
									   rmvParenthesis(trim(line.substr(nextSpace, line.length()))));
			} else if (line.substr(0, 6) == "assert") {
				line = trim(line.substr(6, line.length()));
				nextSpace = line.find_first_of(' ');
				_chipset.executeAction(ASSERT, line.substr(0, nextSpace),
									   rmvParenthesis(trim(line.substr(nextSpace, line.length()))));
			}
		} catch (DefaultException& e) {
			cerr << "Line : " << lineCount << " - ";
			throw e;
		}
	}
	if (!exit) {
		throw NoExitInstruction(""); // TODO Quel message ici ?
	}
}

std::string IOInterface::rmvParenthesis(std::string str) {
	str = trim(str.substr(1, str.length())); // suppression des ' ' après '('
	const auto strInd = str.find_first_of(')' | ' '); // suppression des ' ' et ')' après la valeur
	return str.substr(0, strInd);
}

/**
 * remove leading spaces
 */
std::string IOInterface::trim(const std::string& str) {
	const auto strBegin = str.find_first_not_of(' ');
	return str.substr(strBegin, str.length());
}