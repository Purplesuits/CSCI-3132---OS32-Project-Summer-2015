#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "Scheduler.h"
#include "Command.h"
#include "OS32Memory.h"

void Scheduler::runUtility(Utilities::Utilities * util) {
	util->execute();
}

int Scheduler::systemCall(std::vector<std::string> args) {
	// invalid if args is empty
	if (args.size() < 1) {
		std::cout << "No command found" << std::endl;
		return EXIT_FAILURE;
	}

	//used to get heap memory for command
	OS32Memory &memory = OS32Memory::getInstance();

	//holds reference to the specific command to run
	Command * command = nullptr;
	std::string cmd_string = args.at(0);

	//runs the specified command
	if (cmd_string == "helpme") {
		void *  mem = memory.kalloc(sizeof(HelpMe));
		command = new (mem) HelpMe;
	} else if (cmd_string == "fcreate") {
		if (args.size() != 2) {
			std::cout << "usage: fcreate <file name>" << std::endl;
		} else {
			void *  mem = memory.kalloc(sizeof(FCreate));
			command = new (mem) FCreate(args.at(1));
		}
	} else if (cmd_string == "fread") {
		if (args.size() != 2) {
			std::cout << "usage: fread <file name>" << std::endl;
		} else {
			void *  mem = memory.kalloc(sizeof(FRead));
			command = new (mem) FRead(args.at(1));
		}
	} else if (cmd_string == "fwrite") {
		if (args.size() != 3) {
			std::cout << "usage: fwrite <file name> <contents>" << std::endl;
		} else {
			void *  mem = memory.kalloc(sizeof(FWrite));
			command = new (mem) FWrite(args.at(1), args.at(2));
		}
	} else if (cmd_string == "dcreate") {
		if (args.size() != 2) {
			std::cout << "usage: dcreate <directory name>" << std::endl;
		} else {
			void *  mem = memory.kalloc(sizeof(DCreate));
			command = new (mem) DCreate(args.at(1));
		}
	} else if (cmd_string == "currdir") {
		void *  mem = memory.kalloc(sizeof(CurrDir));
		command = new (mem) CurrDir;
	} else if (cmd_string == "listitems") {
		void *  mem = memory.kalloc(sizeof(ListItems));
		command = new (mem) ListItems;
	} else if (cmd_string == "chper") {
		if (args.size() != 3) {
			std::cout << "usage: chper <file name> <permissions>" << std::endl;
		} else {
			void *  mem = memory.kalloc(sizeof(ChPer));
			command = new (mem) ChPer(args.at(1), args.at(2));
		}
	}

	// run command if it is valid
	if (command != nullptr) {
		int ret = command->execute();
		memory.free(command);
		return ret;
	} else {
		std::cout << "Null Pointer Exception" << std::endl;
		return EXIT_FAILURE;
	}
}
