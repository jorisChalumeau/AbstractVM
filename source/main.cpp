#include <iostream>
#include <cstring>
#include "../header/Factory.h"
#include "../header/Memory.h"

using namespace std;

int main() {
	std::cout << "Start the program : " << std::endl;
	IOperand *myVal = Factory::createOperand(eOperandType::Float, "37.32");
	std::string msg = "type de myVal : ";
	std::cout << msg.append(myVal->toString()) << std::endl;
	Memory *memory;
	memory = new Memory();
	memory->addToRegister(2, *myVal);
	cout << memory->getRegisterValue(2)->getType() << endl;
	return 0;
}