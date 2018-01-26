#include <iostream>
#include <fstream>
#include <cstring>
#include "../header/Factory.h"
#include "../header/Memory.h"
#include "../header/Exceptions.h"
#include "../header/IOInterface.h"

using namespace std;

int main(int argc, char **argv) {
	auto *ioInterface = new IOInterface();
	if (argc == 1) { // fichier en entrée
		ifstream file;
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
			cin >> line;
			myFile << line; // Peut-être +"\n";
		}
		myFile.close();
		ifstream file;
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
	Memory *memory;
	memory = new Memory();
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