//
// Created by apaca on 26/01/2018.
//

#ifndef UNTITLED_IOINTERFACE_H
#define UNTITLED_IOINTERFACE_H

#include <fstream>
#include "Memory.h"

using namespace std;

class IOInterface {
public:
	explicit IOInterface(Memory *memory);

	void ProcessFile(ifstream& file);
	~IOInterface() = default;

private:
	Memory _memory;
};

#endif //UNTITLED_IOINTERFACE_H
