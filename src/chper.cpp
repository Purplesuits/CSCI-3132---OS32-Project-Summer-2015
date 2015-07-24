/**
 * @author Nick Barron
 */

#include <iostream>
#include <string>
#include "command.h"
#include <stdlib.h>

using namespace std;

/**
 * Changes the permission of a given filename
 *
 */
class chper : public Command {
private:
	char *filename;
	char *permission;
	char permissionString[255];
public:
	/**
	 * @param filename - name of file to change permissions
	 * @param permission - the permission to change the file to
	 */
	chper(string filename, string permission)
	 {
	 	this->filename = new char[filename.length() + 1];
	 	strcpy(this->filename, filename.c_str());

	 	this->permission = new char[permission.length() + 1];
	 	strcpy(this->permission, permission.c_str());
	 }
	 ~chper() {
	 	this->filename = NULL;
	 	this->permission = NULL;
	 	memset(this->permissionString, 0, 255);
	 }
	/**
	 * @returns int - 0 if success, 1 if error
	 * @description Executes the changing of the file permissions
	 */
	int execute() {

		// Check that the filename isn't empty
		if ((unsigned)strlen(this->filename) == 0)
		{
			cout << "Cannot execute chper; filename is empty." << endl;
			return 1;
		}
		// Check that the permission isn't empty
		else if ((unsigned)strlen(this->permission) == 0)
		{
			cout << "Cannot execute chper; permission is empty." << endl;;
			return 1;
		}
		// Execute the permission change
		else
		{
			cout << "Executing chper with filename: " << this->filename << " and permission: " << this->permission << "..." << endl;

			strcat(this->permissionString, "chmod ");
			strcat(this->permissionString, this->permission);
			strcat(this->permissionString, " ");
			strcat(this->permissionString, this->filename);
			system(this->permissionString);

			// Reset this object so it can be used multiple times in a row
			// without issues.
			this->~chper();
		}

		return 0;
	}
};
