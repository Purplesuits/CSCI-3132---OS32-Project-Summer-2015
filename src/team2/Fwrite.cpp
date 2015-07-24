/**
 *  The Fwrite class is a subclass of Command class. It overrides the function "excute" to write 
 *  some content into a file in OS32 file system. The file can only be written if the read and 
 *  write permissions of the file are both 1 and the file is already created.
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

class Fwrite:Command{
private:
    string fileName;
    string content;


public:
    /**
     *  The constructor sets the file name and the content to be written.
     */
    Fwrite(string name, string con){
        fileName = name;
        content = con;
    }
    
    /**
     *  The execute function fiestly check if the file is created. Then, it checkes the file permission. 
     *  If the read and write permissions are 1, the content is written to the file with a message to UI. 
     *  If the read and write permissions are not 1, an error message will be printed and function
     *  returns 0.
     *
     *  @return 1 if file is written succesfully, 0 otherwise
     */
    int execute(){
        //check if the file is created
        if(FileSystem::getInstance().fwrite(fileName) == nullptr)
        {
            UI::println("Fwrite failed. The file entered is not created.");
            return 0;
        }
        //check the read and write permission
        else if(FileSystem::getInstance().fwrite(fileName)->getPermissions().at(0) && FileSystem::getInstance().fwrite(fileName)->getPermissions().at(0))
        {
            FileSystem::getInstance().fwrite(fileName)->setContents(content);
            UI::println("Fwrite complete.");
            return 1;

        }
        else
        {
            UI::println("Fwrite failed. No read or write permission.");
            return 0;
        }
        

    
    }
};

