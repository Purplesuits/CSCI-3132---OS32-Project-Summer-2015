/*
 * Converter.cpp
 *
 *  Created on: 8 Jul 2015
 *      Author: Jason Turner
 * 
 * 	The converter utility allows the user to convert between 
 */

#include "Converter.h"
#include "UI.h"

#include <sstream>

using namespace std;

namespace Utilities {

	/**
	 * 	Class extends Utilities
	 * */
	Converter::Converter() : Utilities(){

	}

	Converter::~Converter() {
	}

	void Converter::execute(){
		displayMenu();
	}

	/**
	 *  Function displays all the conversion operations to the user.
	 *
	 *   The user can then select which conversion to perform and enter the number of units they wish to convert.
	 *
	 *   Once the conversion has taken place the result will be displayed on the screen. 
	 * 
	 * 
	 */
	void Converter::displayMenu(){

		UI::println("::Converter Menu::");
		UI::println("\t1. Convert from Fahrenheit to Celsius");
		UI::println("\t2. Convert from Celsius to Fahrenheit");
		UI::println("\t3. Convert from feet to meters");
		UI::println("\t4. Convert from meters to feet");
		UI::println("\t5. Convert from lbs to kgs");
		UI::println("\t6. Convert from kgs to lbs");

		int selection = -1;

		UI::print("Enter Selection: ");
	
		//string userInputStr = "";
		selection = UI::read<int>();

		if(checkIfNumber()){
			UI::print("\nEnter Unit: ");

			double userInput = 0.0;
			double result = 0.0;
			//userInputStr = "";

			userInput = UI::read<double>();			

			if(checkIfNumber()){

				cout << endl;

				switch(selection){
				case FtoC:
					result = getFtoC(userInput);
					UI::print("F to C: ");
					break;
				case CtoF:
					result = getCtoF(userInput);
					UI::print("C to F: ");
					break;
				case MetersToFeet:
					result = getMetersToFeet(userInput);
					UI::print("M to Ft: ");
					break;
				case FeetToMeters:
					result = getFeetToMeters(userInput);
					UI::print("Ft to M: ");
					break;
				case LbsToKgs:
					result = getLbsToKgs(userInput);
					UI::print("Lbs to Kgs: ");
					break;
				case KgsToLbs:
					result = getKgsToLbs(userInput);
					UI::print("Kgs to Lbs: ");
					break;
				default:
					UI::println("Error - Please enter a valid conversion selection");
					break;
				}
					
				stringstream ss;
				
				ss << result;

				UI::println(ss.str());

			}
			else{
				UI::println("Error - Please enter a valid number");
				selection = -1;
			}
		}
		else{
		    UI::println("Error - Please enter a valid conversion selection");
		    selection = -1;

		}
	
	}
	
	/**
	 * Function converts the user input from F to C
	 * 
	 *@param userInput double,   the user input to be converted
	 * 
	 *@return the converted user input
	 * 
	 */
	double Converter::getFtoC(double userInput){
	    return (((userInput - 32) * 5) / 9);
	}
	
	
	/*
	 * Function converts the user input from C to F
	 * 
	 * @param userInput double,   the user input to be converted
	 * 
	 * @return the converted user input
	 * 
	 */
	double Converter::getCtoF(double userInput){
	    return (((userInput * 9) / 5) + 32);
	}
	
	
	
	/*
	 * Function converts the user input from Meters to Feet
	 * 
	 * @param userInput double,   the user input to be converted
	 * 
	 * @return the converted user input
	 * 
	 */
	double Converter::getMetersToFeet(double userInput){
	    return userInput * 3.28;
	}
	
	
	/*
	 * Function converts the user input from Feet to Meters
	 * 
	 * @param userInput double,   the user input to be converted
	 * 
	 * @return the converted user input
	 * 
	 */
	double Converter::getFeetToMeters(double userInput){
	    return userInput / 3.28;
	}
	
	
	
	/*
	 * Function converts the user input from Lbs to Kgs
	 * 
	 * @param userInput double,   the user input to be converted
	 * 
	 * @return the converted user input
	 * 
	 */
	double Converter::getLbsToKgs(double userInput){
	    return userInput / 2.2;
	}
	
	
	
	/*
	 * Function converts the user input from Kgs to Lbs
	 * 
	 * @param userInput double,   the user input to be converted
	 * 
	 * @return the converted user input
	 * 
	 */
	double Converter::getKgsToLbs(double userInput){
	    return userInput * 2.2;
	}	



} /* namespace Utilities */
