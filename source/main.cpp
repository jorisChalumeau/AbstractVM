#include <iostream>
#include <cstring>
#include "../header/Factory.h"
#include "../header/Memory.h"
#include "../header/Exceptions.h"

using namespace std;

int main() {
	std::cout << "Start the program : " << std::endl;
	IOperand *myVal = Factory::createOperand(eOperandType::Float, "37.32");
	std::string msg = "type de myVal : ";
	std::cout << msg.append(myVal->toString()) << std::endl;
	Memory *memory;
	memory = new Memory();
    try{
        memory->addToRegister(2, *myVal);
        std::cout << memory->getRegisterValue(2)->getType() << std::endl;
        memory->addToRegister(-3, *myVal);
        std::cout << memory->getRegisterValue(-3)->getType() << std::endl;
    } catch (OutOfBound e) {
        fprintf(stderr, "%s\n", e.what()); // ca affiche pas pck ca renvoie un const char* je crois
        std::cout << e.what() << std::endl;
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
	return EXIT_SUCCESS;
}