//
// Created by cjoris on 2/1/18.
//

#include <dirent.h>
#include <iostream>
#include <fstream>
#include "../header/TestFiles.h"
#include "../header/Exceptions.h"

void TestFiles::testAllFiles() {
    DIR *dir;
    ifstream file;
    struct dirent *ent;
    dir = opendir("tests");
    IOInterface *ioInterface;
    while ((ent = readdir(dir)) != NULL){
        if(string(ent->d_name).substr(0,1) == "t") {
            std::cout << string("Press 'go'+[ENTER] to display next file (or 'exit' to leave) : ") + ent->d_name << std::endl;
            string line;
            while (line != "go") {
                getline(cin, line);
                if(line == "exit")
                    exit(0);
            }
            file.open(string("tests/") + string(ent->d_name));
            if (file.is_open()) {
                try {
                    ioInterface = new IOInterface(new Chipset(new Cpu(new Memory)));
                    ioInterface->ProcessFile(file);
                } catch (DefaultException &e) {
                    cerr << e.what() << endl;
                }
                file.close();
            } else {
                throw FileDoesNotExist(ent->d_name);
            }
        }
    }
}
