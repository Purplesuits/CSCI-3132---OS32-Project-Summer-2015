/*
 * HelpMe.h
 *
 *  Created on: Jul 22, 2015
 *      Author: Prime
 */

#ifndef HELPME_H_
#define HELPME_H_

#include<string>
using namespace std;
#include "FileSystem.h"
#include "Command.h"
#include "UI.h"
#include "File.h"

class HelpMe :public Command{
public:
	HelpMe();
	virtual ~HelpMe();
	int execute;
};

#endif /* HELPME_H_ */
