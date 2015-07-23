/*
 * HelpMe.cpp
 *
 *  Created on: Jul 22, 2015
 *      Author: Prime
 */

#include "HelpMe.h"

HelpMe::HelpMe() {
	// TODO Auto-generated constructor stub

}

HelpMe::~HelpMe() {
	// TODO Auto-generated destructor stub
}

int HelpMe::execute(){
        FileSystem fsys; //FileSystem object
		File* file;   //pointer to hold File object
		UI ui;    //UI object
		file= fsys.fread("command-list.txt");     //fread will retrn File pointer.
		string contents=file->getContents();   //getting contents using pointer
	    ui.println(contents);    //passing contents to UI
		return 0;
}
