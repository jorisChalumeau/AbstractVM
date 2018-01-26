//
// Created by apaca on 26/01/2018.
//

#ifndef UNTITLED_IOINTERFACE_H
#define UNTITLED_IOINTERFACE_H

#import <fstream>

using namespace std;

class IOInterface {
public:
	IOInterface();

	void ProcessFile(ifstream& file);
};

#endif //UNTITLED_IOINTERFACE_H
