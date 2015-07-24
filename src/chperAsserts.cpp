/**
 * @author Nick Barron
   @description This file tests the chper.cpp command utility
   by performing asserts after it runs to verify that the file
   permissions were changed
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "chper.cpp"
#include <assert.h>

using namespace std;

void doExecuteAndAssert(chper *chperCmd, string targetPermission) {

	if (chperCmd->execute() > 1)
	{
		cout << "Error occurred" << endl;
	}
	else
	{
		cout << "Success." << endl << endl;

		cout << "Permission after chper executed: " << endl;
		system("ls -l;");
		cout << endl;

		// Verify the permissions were changed correctly by putting
		// the permissions in the terminal into a file and checking
		// that it has the right ones.
		system("ls -l | grep textFileA.txt$ | cat > output.txt");

		string output;

		// Read the file we created above with grep and cat
		ifstream infile;
		infile.open("output.txt");
		if (infile.good())
		{
			getline(infile, output);
			cout << output << endl;
		}
		
		cout << "Changed permission: " << output << endl;

		// Verify that the permission was changed:
		assert(output.find(targetPermission) != string::npos);
		cout << "Assert succeeded." << endl << endl;
	}
}

// Call asserts for the chper function
int main(void) {

    // Need to have textFileA.txt in same directory, or
    // give it a relative path, e.g. '../../textFileA.txt' etc
	string filename = "textFileA.txt";

	chper * chperCmd = new chper(filename, "777");	
	doExecuteAndAssert(chperCmd, "-rwxrwxrwx");
	
	chperCmd = new chper(filename, "755");
	doExecuteAndAssert(chperCmd, "-rwxr-xr-x");

	chperCmd = new chper(filename, "u-r,u-w,u-x");
	doExecuteAndAssert(chperCmd, "----r-xr-x");

	return 0;
}



