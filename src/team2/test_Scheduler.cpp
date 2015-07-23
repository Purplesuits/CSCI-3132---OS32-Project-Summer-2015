#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Scheduler.h"
#include "Command.h"
#include "../files/FileSystem.h"
#include "../files/OS32Memory.h"

FileSystem &fileSystem = FileSystem::getInstance();
Scheduler &scheduler = Scheduler::getInstance();

bool testHelpMe();
bool testListItems();
bool testFCreate();
bool testDCreate();
bool testFWrite();
bool testFRead();
bool testChPer();
bool testCurrDir();

/*
 *	This file tests the scheduler and associated ustilities.
 */
int main() {
	// initializes some heap memory for testing
	OS32Memory &memory = OS32Memory::getInstance();
	memory.initialize(256, 256);

	bool pass = testListItems();
	pass = pass && testHelpMe();
	pass = pass && testFCreate();
	pass = pass && testDCreate();
	pass = pass && testFWrite();
	pass = pass && testFRead();
	pass = pass && testChPer();
	pass = pass && testCurrDir();

	//returns 0 if all tests pass
	// returns 1 otherwise
	if (pass) {
		return 0;
	} else {
		return 1;
	}
}
/*
 *	This method tests the helpme command
 */
bool testHelpMe() {
	std::string expected = "This is a test.";

	fileSystem.fcreate("command-help.txt", expected, std::vector<bool>(3, true));

	std::string out;

	std::vector<std::string> args;
	args.push_back("helpme");

	std::stringstream buffer;
	std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

	scheduler.systemCall(args);

	std::string actual = buffer.str();
	
	return expected + "\n" == actual;
}

/*
 *	This method tests the listitems command
 */
bool testListItems() {
	std::stringstream buffer;
	std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

	std::vector<std::string> args;
	args.push_back("listitems");
	scheduler.systemCall(args);

	std::string before = buffer.str();

	bool pass = before == "\n";

	if (pass) {
		std::string filename = "listItemsFile";
		fileSystem.fcreate(filename, "", std::vector<bool>(3, true));
		scheduler.systemCall(args);
		
		std::string after = buffer.str();
		
		pass = after == "\n" + filename + " \n";
	}

	return pass;
}

/*
 *	This method tests the fcreate commmand
 */
bool testFCreate() {
	std::string before = fileSystem.listitems();

	std::vector<std::string> args;
	args.push_back("fcreate");
	args.push_back("file");
	scheduler.systemCall(args);

	std::string after = fileSystem.listitems();

	return after == (before + "file ");
}

/*
 *	This method tests the dcreate command
 */
bool testDCreate() {
	std::string before = fileSystem.listitems();

	std::vector<std::string> args;
	args.push_back("dcreate");
	args.push_back("dir");
	scheduler.systemCall(args);

	std::string after = fileSystem.listitems();

	return after == (before + "dir ");
}

/*
 *	This method tests the fwrite command
 */
bool testFWrite() {
	std::string filename = "writeFile";
	std::string contents = "This is some stuff\n in a file.\n";

	fileSystem.fcreate(filename, "", std::vector<bool>(3, true));

	std::vector<std::string> args;
	args.push_back("fwrite");
	args.push_back(filename);
	args.push_back(contents);
	scheduler.systemCall(args);

	File * file = fileSystem.fLocate(filename);
	if (file == nullptr) {
		return false;
	}

	std::string actualContents = file->getContents();

	return contents == actualContents;
}

/*
 *	This method tests tht fread command
 */
bool testFRead() {
	std::stringstream buffer;
	std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

	std::string filename = "readFile";
	std::string contents = "This is some stuff\n in a file.\n";

	fileSystem.fcreate(filename, contents, std::vector<bool>(3, true));

	std::vector<std::string> args;
	args.push_back("fread");
	args.push_back(filename);
	scheduler.systemCall(args);

	std::string after = buffer.str();

	return after == contents + "\n";
}

/*
 *	This method tests the chper command
 */
bool testChPer() {
	std::string filename = "permissionsFile";
	std::vector<bool> initialPermissions = std::vector<bool>(3, true);

	fileSystem.fcreate(filename, "", initialPermissions);

	bool pass = fileSystem.fLocate(filename)->getPermissions() == initialPermissions;

	if (pass) {
		std::vector<bool> afterPermissions;
		afterPermissions.push_back(false);
		afterPermissions.push_back(true);
		afterPermissions.push_back(false);

		std::vector<std::string> args;
		args.push_back("chper");
		args.push_back(filename);
		args.push_back("010");
		scheduler.systemCall(args);

		pass = pass & fileSystem.fLocate(filename)->getPermissions() == afterPermissions;
	}

	if (pass) {
		std::vector<bool> afterPermissions;
		afterPermissions.push_back(true);
		afterPermissions.push_back(false);
		afterPermissions.push_back(true);

		std::vector<std::string> args;
		args.push_back("chper");
		args.push_back(filename);
		args.push_back("101");
		scheduler.systemCall(args);

		pass = pass & fileSystem.fLocate(filename)->getPermissions() == afterPermissions;
	}

	return pass;
}

/*
 *	This method tests the currdir command
 */
bool testCurrDir() {
	std::stringstream buffer;
	std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

	std::string expected = "root\n";

	std::vector<std::string> args;
	args.push_back("currdir");
	
	scheduler.systemCall(args);

	std::string actual = buffer.str();

	return expected == actual;
}
