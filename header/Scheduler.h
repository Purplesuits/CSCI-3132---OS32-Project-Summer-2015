#include <string>
#include <vector>

#include "Utilities.h"

/*
 *	This class represents the process scheduler of the OS32 system
 */
class Scheduler {
private:
	// Hides the contructor to maintain Singleton pattern
	Scheduler() {}
	Scheduler(Scheduler const&) = delete;
	void operator=(Scheduler const&) = delete;
public:
	/*
	 *	This method returns a reference to the Singleton instance of this class
	 */
	static Scheduler & getInstance()
	{
		static Scheduler instance;
		return instance;
	}

	/*
	 *	This method performs a system call with the given vector of command name and optionally arguments
	 *  It will return the return code of the Command it executes, or EXIT_FAILURE if no valid command is found.
	 */
	int systemCall(std::vector<std::string> argv);

	/*
	 * Runs the specified utility
	 */
	void runUtility(Utilities::Utilities * utility);
};
