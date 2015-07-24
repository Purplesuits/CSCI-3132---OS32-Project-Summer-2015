/*
 * Utilities.cpp
 *
 *  Created on: 7 Jul 2015
 *      Author: Jason Turner
 *
 *
 *  The Utilities class design has changed from what was initially discussed after review of the project specifications
 *
 *	The Utilities class should be instantiated first with a reference to the UI and Process management and execute() run
 *	to display the menu.
 *
 *	The user may then select which Utility to run, which will be then be returned as a Utilities* of selected Utility type. (eg converter, calculator etc..)
 *
 *	This Utilities* will then be passed to the kernel for scheduling and execution, then returning to the Utilites menu once utility as run.
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
	 * Function instantiates the other Utilities using the OS32Memory component and returns the new object for the scheduler
	 *
	 * eg:
	 *
	 * 		Utility* util = new(OS32Memory::getInstance().alloc(sizeof(Converter))) Converter();
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
		UI::print("\nEnter Utility to run (1-6, 0 to Quit): ");

		string userInput = "";
	
                runUtil =  UI::read<int>();

		if(checkIfNumber()){

			flushInputStream();
			switch(runUtil){
				case CONVERTER_UTILITY:
				  
					util = new(OS32Memory::getInstance().alloc(sizeof(Converter))) Converter();	
					break;
				case ENCRYPTION_UTILITY:
				  
					util = new(OS32Memory::getInstance().alloc(sizeof(Encryption))) Encryption(); 
					break;
				case MOTD_UTILITY:
				  
					util = new(OS32Memory::getInstance().alloc(sizeof(Motd))) Motd();
					break;
				case PALINDROME_UTILITY:
				  
					util = new(OS32Memory::getInstance().alloc(sizeof(Palindrome))) Palindrome(); 
					break;
				case CALCULATOR_UTILITY:
				  
					util = new(OS32Memory::getInstance().alloc(sizeof(Calculator))) Calculator(); 
					break;
				case DATE_TIME_UTILITY:
				  
					UI::println("I'm the date and time!");
					break;
				case EXIT:
					util = NULL;
					cout << "Exiting Utilites!" << endl;
					break;
				default:
					UI::println("Error - Please enter a valid menu selection\n");
					runUtil = -1;
					break;
			}

		}
		else{
			UI::println("Error - Please enter a  valid menu seclection\n");
			runUtil = -1;
		}
		
		return util;
	}

	/**
	 *
	 * Virtual function execute() that will be overridden by other objects and will return which ever instantiated object to UI or Kernel (which ever needs it)
	 * 
	 * When run from the base class operates as the main menu so other utilities can then be instantiated and passed along to the scheduler for execution.
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
		
		UI::println("");

 	}

 	
 	/**
	 * Function checks if the input entered is a number of not.  
	 * 
	 * If not flush the input stream and return false;
	 * 
	 * Else return true, its a number.
	 * 
	 */
 	bool Utilities::checkIfNumber(){
		if(!cin){

		    flushInputStream();
		    
		    return false;
		}
		  
		return true;
	}


	/**
	 * A simple bug fix for the input stream when using the UI as well as clearing cin when
	 * invalid input is entered.
	 * 
	 * The bug occurs when the UI::readLine is called after a UI::read<> as the input will hang.
	 * 
	 * This clears the input of any existing characters and allows for the input to act normally
	 * 
	 */
	void Utilities::flushInputStream(){

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	

	}


} /* namespace Utilities */
