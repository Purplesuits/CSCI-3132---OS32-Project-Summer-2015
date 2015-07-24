//
// Created by Aymen Ben Rkhis on 7/18/15.
//

#include "Motd.h"
#include "UI.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;
using namespace Utilities;

Motd::Motd(){
    string initFile = "Message 1\n"
            "Message 2\n"
            "Message 3\n"
            "Message 4\n"
            "Message 5\n"
            "Message 6\n"
            "Message 7\n"
            "Message 8\n"
            "Message 9\n"
            "Message 10\n"
            "Message 11\n"
            "Message 12\n"
            "Message 13\n"
            "Message 14\n"
            "Message 15\n"
            "Message 16\n"
            "Message 17\n"
            "Message 18\n"
            "Message 19\n"
            "Message 20";
    FileSystem& fs = FileSystem::getInstance();
    if (fs.fLocate("Motd.txt")== nullptr)
        fs.fcreate("Motd.txt",initFile,{true,true,true});
}

void Motd::execute() {
    generateMOTD();
}

void Motd::generateMOTD(){


    //Get the file containing the messages
    FileSystem& fs = FileSystem::getInstance();
    File* motd;
    if((motd=fs.fLocate("motd.tmp"))!= nullptr){
        UI::println("Mesage of the day: "+motd->getContents());
        return;
    }
    motd = fs.fLocate("Motd.txt");
    //Retrieve its contents line by line
    string messages = motd->getContents();
    istringstream stream(messages);
    //generate a random number to use as index for the meesage
    srand (time(NULL));
    int mIndex = rand() % 20, i=0;
    //Generate Random message
    string line;
    while (i != mIndex && getline(stream, line)){
        i++;
    }
    fs.fcreate("motd.tmp", line, {true, true, true});
    UI::println("Mesage of the day: "+line);
}