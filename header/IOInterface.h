//
// Created by apaca on 26/01/2018.
//

#ifndef UNTITLED_IOINTERFACE_H
#define UNTITLED_IOINTERFACE_H

#include <fstream>
#include "Chipset.h"

using namespace std;

class IOInterface {
public:
	explicit IOInterface(Chipset *chipset);

	void ProcessFile(ifstream& file);
	~IOInterface();

private:
	Chipset _chipset;

	std::string trim(const string &str);
    string rmvParenthesis(string str);
};

#endif //UNTITLED_IOINTERFACE_H
