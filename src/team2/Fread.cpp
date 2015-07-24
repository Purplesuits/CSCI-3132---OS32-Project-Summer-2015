/**
 *  The Fread class is a subclass of Command class. It overrides the function "excute" 
 *  to read a file in OS32 file system and display the file to the UI. The file can only
 *  be read if the read permission of the file is 1 and the file is already created.
 *
 *  Author: Hankun Zhang (B00614362)
 */

#include <iostream>
#include <fstream>
#include <string>
#include "File.h"
#include "FileSystem.h"
#include "UI.h"
using namespace std;

class Fread:Command{
private:
    string line;
    string fileName;
    
public:
    /**
     *  The constructor sets the file name.
     */
    Fread(string name){
        fileName = name;
    }
    
    /**
     *  The execute function fiestly check if the file is created. Then, it checkes the file permission. 
     *  If the read permission is 1, the file is read and the content of the file is displayed to the UI. 
     *  If the read permission is not 1, an error message is printed and function returns 0.
     *
     *  @return 1 if file is read succesfully, 0 otherwise
     */
    int execute(){
        //check if the file is created
        if(FileSystem::getInstance().fwrite(fileName) == NULL)
        {
            UI::println("Fwrite failed. The file entered is not created.");
            return 0;
        }
        //check the read permission
        else if(FileSystem::getInstance().fwrite(fileName)->getPermissions().at(0))
        {
            UI::println(FileSystem::getInstance().fread(fileName)->getContents());
            UI::println("Fread complete.");
            return 1;
        }
        else
        {
            UI::println("Fread failed. No read permission.");
            return 0;
        }
    }
    
};

