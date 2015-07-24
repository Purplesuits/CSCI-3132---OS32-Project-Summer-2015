/*
 * Utilities.cpp
 *
 *  Created on: 7 Jul 2015
 *      Author: jturner
 *
 *
 *  The Utilities class design has changed from what was initially discussed after review of the project specifications
 *
 *	The Utilities class should be instantiated first with a reference to the UI and Process management and execute() run
 *	to display the menu.
 *
 *	Note: No memory needs to be used with the base Utility execute() task as it will be using the referenced
 *	UI to display a menu and take user input for selection and no process is scheduled.
 *
 *	The user may then select which Utility to run, which will be then be returned as a Utilities* of selected Utility type. (eg converter, calculator etc..)
 *
 *	This Utilities* will then be passed to the kernel for scheduling and execution, then returning to the UI.
 */

#include "Utilities.h"
#include "Converter.h"
#include "encryption.h"
#include "calculator.h"
#include "Palindrome.h"
#include "Motd.h"
#include "UI.h"
#include "Scheduler.h"
#include "OS32Memory.h"

using namespace std;

namespace Utilities {

	Utilities::Utilities() {


	}

	Utilities::~Utilities() {
	}


	/**
	 * Menu for utilities to be run as specified in the project documentation.
	 *
	 * Function will eventually instantiate Utility objects of different types and return them to what needs it.
	 *
	 * eg:
	 *
	 * 		Utility* util = new Converter();
	 *
	 */
	Utilities* Utilities::displayMenu(){

		int runUtil = -1;

		Utilities* util = NULL;

		UI::println( "\n\n::Utilities Menu::");
		UI::println("1. Converter Utility");
		UI::println("2. Encryption Utility");
		UI::println("3. Message of the day Utility");
		UI::println("4. Palindrome Utility");
		UI::println("5. Calculator Utility");
		UI::println("6. Display system date/time");
		UI::println("0. Quit");
		UI::println("\nEnter Utility to run (1-6, 0 to Quit): ");

		string userInput = "";

		UI::readLine();
                userInput =  UI::readLine();
		if(checkIfInt(userInput, runUtil)){

			switch(runUtil){
				case CONVERTER_UTILITY:
					//util = new Converter();
					util = new(OS32Memory::getInstance().alloc(sizeof(Converter))) Converter();	
					break;
				case ENCRYPTION_UTILITY:
					//util = new Encryption();
					util = new(OS32Memory::getInstance().alloc(sizeof(Encryption))) Encryption(); 
					break;
				case MOTD_UTILITY:
					//util = new Motd();
					util = new(OS32Memory::getInstance().alloc(sizeof(Motd))) Motd();
					break;
				case PALINDROME_UTILITY:
					//util = new Palindrome();
					util = new(OS32Memory::getInstance().alloc(sizeof(Palindrome))) Palindrome(); 
					break;
				case CALCULATOR_UTILITY:
					//util = new Calculator();
					util = new(OS32Memory::getInstance().alloc(sizeof(Calculator))) Calculator(); 
					break;
				case DATE_TIME_UTILITY:

					break;

				case EXIT:
					util = NULL;
					cout << "Exiting Utilites!" << endl;
					break;
				default:
					UI::println("Error - Please enter a valid menu selection");
					runUtil = -1;
					break;
			}
			//UI::readLine();

		}
		else{
			UI::println("Error - Please enter a  valid menu seclection");
		}
		
		return util;
	}

	/**
	 *
	 * Virtual function execute that will be overridden by other objects and will return which ever instantiated object to UI or Kernel (which ever needs it)
	 *
	 */
	 void Utilities::execute(){
		Utilities* util = NULL;
		do{
			util = displayMenu();
			if(util != NULL){
				Scheduler &scheduler = Scheduler::getInstance();
				scheduler.runUtility(util);
			
				OS32Memory::getInstance().free(util);	
			}
		} while (util != NULL);

 	}


	bool Utilities::checkIfInt(string userInput, int &runUtil){
		try {
			runUtil = stoi(userInput, nullptr, 10);

			return true;
		}
  		catch (const std::invalid_argument& ia) {
			std::cerr << "Invalid argument: " << ia.what() << '\n';
			return false;
		}
	}

} /* namespace Utilities */
