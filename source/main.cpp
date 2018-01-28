#include <iostream>
#include <fstream>
#include "../header/Memory.h"
#include "../header/Exceptions.h"
#include "../header/IOInterface.h"

using namespace std;

int main(int argc, char **argv) {
	auto *mem = new Memory();
	auto *cpu = new Cpu(mem);
	auto *chipset = new Chipset(cpu);
	auto *ioInterface = new IOInterface(chipset);
	ifstream file;

	if (argc == 2) { // fichier en entrée
		file.open(argv[1]);
		if (file.is_open()) {
			try {
				ioInterface->ProcessFile(file);
			} catch (DefaultException& e) {
				cerr << e.what() << endl;
				file.close();
				return 84;
			}
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
			if (line != ";;")
				myFile << line << endl;
		}
		myFile.close();
		file.open("temp.avm");
		try {
			ioInterface->ProcessFile(file);
		} catch (DefaultException& e) {
			cerr << e.what() << endl;
			file.close();
			remove("temp.avm");
			return 84;
		}
		file.close();
		remove("temp.avm");
	}
	return EXIT_SUCCESS;
}