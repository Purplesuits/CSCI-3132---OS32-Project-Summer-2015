#include <string>

/*
 *	This class provides a common interface for system utilities used by the OS32 system.
 */
class Command {
public:
	/*
	 * This method executes the utility and should contain all execution logic
	 * Should return EXIT_FAILURE or EXIT_SUCCESS
	 */
	virtual int execute() = 0;
};

/*
 *  This class repreesents the 'helpme' command, which prints the list of available commands
 */
class HelpMe : public Command {
public:
	int execute();
};

/*
 *	This class represents the 'fcreate' command, which allows the user to create a file
 */
class FCreate : public Command {
	std::string filename;
public:
	// This command will create a file with the name 'filename'
	FCreate(std::string filename) : filename(filename) {}
	int execute();
};

/*
 *	This class represents the 'fread' command which prints the contents of a file
 */
class FRead : public Command {
private:
	std::string filename;
public:
	// This command will print the contents of the file 'filename'
	FRead(std::string filename) : filename(filename) {}
	int execute();
};

/*
 *	This class represents the 'fwrite' command which allows the user write to a file
 */
class FWrite : public Command {
private:
	std::string filename;
	std::string contents;
public:
	// This command will append 'contents' to the file 'filename'
	FWrite(std::string filename, std::string contents) : filename(filename), contents(contents) {}
	int execute();
};

/*
 *	This class represents the 'dcreate' command which allows the user to create a directory
 */
class DCreate : public Command {
	std::string dirname;
public:
	// This command will create a directory with the name 'dirname'
	DCreate(std::string dirname) : dirname(dirname) {}
	int execute();
};

/*
 *	This class represents the 'currdir' command which prints the name of the current directory
 */
class CurrDir : public Command {
public:
	CurrDir() {}
	int execute();
};

/*
 *	This class represents the 'listitems' command which prints the list of files and directories
 *	in the current directory
 */
class ListItems : public Command {
public:
	ListItems() {}
	int execute();
};

/*
 *	This class represents the 'chper' command which allows the user to change the permissions of a file
 */
class ChPer : public Command {
	std::string filename;
	std::string permissions;
public:
	// This command will change the permissions of the file 'filename' to the bitmask 'permissions'
	ChPer(std::string filename, std::string permissions) : filename(filename), permissions(permissions) {}
	int execute();
};