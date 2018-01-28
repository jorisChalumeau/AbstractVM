#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "../header/Factory.h"
#include "../header/Memory.h"
#include "../header/Exceptions.h"
#include "../header/IOInterface.h"

using namespace std;

int main(int argc, char **argv) {
	Memory *memory;
	memory = new Memory();
	auto *ioInterface = new IOInterface(memory);
	ifstream file;

	if (argc == 2) { // fichier en entrée
		file.open(argv[1]);
		if (file.is_open()) {
			ioInterface->ProcessFile(file);
			file.close();
		} else {
			throw FileDoesNotExist(argv[1]);
		}
	} else {
		string line;
		ofstream myFile;
		myFile.open("temp.avm");
		while (line != ";;") {
			getline(cin, line);
			myFile << line << "\r\n";
		}
		myFile.close();
		file.open("temp.avm");
		ioInterface->ProcessFile(file);
		file.close();
		remove("temp.avm");
	}

	std::cout << "Start the program : " << std::endl;
	std::cout << "Int8 = " << Int8 << std::endl;
	IOperand *myVal = Factory::createOperand(eOperandType::Float, "37.32");
	std::string msg = "type de myVal : ";
	std::cout << msg.append(myVal->toString()) << std::endl;
	try {
		memory->addToRegister(2, *myVal);
		std::cout << memory->getRegisterValue(2)->getType() << std::endl;
		memory->addToRegister(-3, *myVal);
		std::cout << memory->getRegisterValue(-3)->getType() << std::endl;
	} catch (OutOfBound& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}