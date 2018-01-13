#include <iostream>
#include <cstring>
#include "../header/Factory.h"
#include "../header/IOperand.h"

int main() {
	std::cout << "Start the program : " << std::endl;
	IOperand *myVal = Factory::createOperand(eOperandType::Float, "37.32");
	std::string msg = "type de myVal : ";
	std::cout << msg.append(myVal->toString()) << std::endl;
	return 0;
}