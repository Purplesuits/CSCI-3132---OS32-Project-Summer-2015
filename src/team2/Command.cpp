#include <vector>

#include "Command.h"
#include "../ui/UI.h"
#include "../files/File.h"
#include "../files/FileSystem.h"

int CurrDir::execute() {
	FileSystem &fileSystem = FileSystem::getInstance();
	File * currDir = fileSystem.getCurrDir();
	
	//curr dir doesn't exist
	if (currDir == nullptr) {
		UI::println("Error. Current directory unknown.");
		return EXIT_FAILURE;
	}

	std::string filename =  currDir->getFileName();
	UI::println(filename);
	return EXIT_SUCCESS;
}

int HelpMe::execute() {
	FileSystem &fileSystem = FileSystem::getInstance();
	std::string filename = "command-help.txt";
	File * commands = fileSystem.fread(filename);
	if (commands != nullptr) {
		std::string contents = commands->getContents();
		UI::println(contents);
		return EXIT_SUCCESS;
	} else {
		//file not found
		UI::println("Error. File command-help.txt not found.");
		return EXIT_FAILURE;
	}
}

int ListItems::execute() {
	FileSystem &fileSystem = FileSystem::getInstance();
	std::string items = fileSystem.listitems();
	UI::println(items);
	return EXIT_SUCCESS;
}

int FCreate::execute() {
	FileSystem &fileSystem = FileSystem::getInstance();

	std::vector<bool> permissions = std::vector<bool>(3, true);
	bool worked = fileSystem.fcreate(filename, "stuff", permissions);

	//fcreate failed
	if (!worked) {
		UI::println("Error. File creation failed.");
		return EXIT_FAILURE;
	} else {
		return EXIT_SUCCESS;
	}
}

int DCreate::execute() {
	FileSystem &fileSystem = FileSystem::getInstance();

	if (fileSystem.dcreate(dirname)) {
		return EXIT_SUCCESS;
	} else {
		//dcreate failed
		UI::println("Error. Failed to create directory.");
		return EXIT_FAILURE;
	}
}

int FRead::execute() {
	FileSystem &fileSystem = FileSystem::getInstance();
	File * file = fileSystem.fread(filename);
	
	//file doesn't exist
	if (file == nullptr) {
		UI::println("Error. File not found.");
		return EXIT_FAILURE;
	}

	//user lacks read permissions
	if (!file->getPermissions().at(0)) {
		UI::println("Error. File lacks read permissions.");
		return EXIT_FAILURE;
	}
		
	std::string contents = file->getContents();
	UI::println(contents);
	return EXIT_SUCCESS;
}

int FWrite::execute() {
	FileSystem &fileSystem = FileSystem::getInstance();
	File * file = fileSystem.fLocate(filename);

	//file doesn't exist
	if (file == nullptr) {
		UI::println("Error. File not found.");
		return EXIT_FAILURE;
	}

	//file lacks write permissions
	if (!file->getPermissions().at(1)) {
		UI::println("Error. File lacks write permissions.");
		return EXIT_FAILURE;
	}

	std::string currContents = file->getContents();
	currContents += contents;
	file->setContents(currContents);
	return EXIT_SUCCESS;
}

int ChPer::execute() {
	if (permissions.length() != 3) {
		UI::println("usage: chper <filename> <permissions>: permissions should be a three bit mask for read, write, execute permissions");
	}

	//assumes user enters a bitmask
	std::vector<bool> p;
	p.push_back(permissions.at(0) == '1');
	p.push_back(permissions.at(1) == '1');
	p.push_back(permissions.at(2) == '1');

	FileSystem &fileSystem = FileSystem::getInstance();
	return fileSystem.chper(filename, p);
}
