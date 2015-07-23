//============================================================================
// Name        : CSCI3132-Project.cpp
// Author      : Jason Turner
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Utilities.h"
#include "FileSystem.h"

using namespace Utilities;

int main() {

	Utilities::Utilities utilityCmder;
	FileSystem& fs = FileSystem::getInstance();
	fs.fcreate ("file", "Here is a sample file named file.", { true, true, true });
	std::cout << "Sample file created: 'file'" << std::endl;

	utilityCmder.execute(); //Run the menu in order to run the other utilities

	std::cout << "Sample file contents: " << fs.fLocate("file")->getContents() << std::endl;
	return 0;
}
