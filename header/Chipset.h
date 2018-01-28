//
// Created by cjoris on 1/28/18.
//

#ifndef UNTITLED_CHIPSET_H
#define UNTITLED_CHIPSET_H

#include "Cpu.h"

class Chipset {
public:
    explicit Chipset(Cpu *cpu);
    char print();
    std::string dump();
    void executeAction(eCommandType action);
    void executeAction(eCommandType action, std::string type, std::string value);
    ~Chipset();

private:
    Cpu _cpu;
};


#endif //UNTITLED_CHIPSET_H
