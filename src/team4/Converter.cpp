/*
 * Converter.cpp
 *
 *  Created on: 8 Jul 2015
 *      Author: jturner
 */

#include "Converter.h"
#include "UI.h"

#include <sstream>

using namespace std;

namespace Utilities {

	Converter::Converter() : Utilities(){

	}

	Converter::~Converter() {
	}

	void Converter::execute(){
		displayMenu();
	}

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
					result = (((userInput * 9) / 5) + 32);
					UI::print("F to C: ");
					break;
				case CtoF:
					result = (((userInput - 32) * 5) / 9);
					UI::print("C to F: ");
					break;
				case MetersToFeet:
					result = userInput * 3.28;
					UI::print("M to Ft: ");
					break;
				case FeetToMeters:
					result = userInput / 3.28;
					UI::print("Ft to M: ");
					break;
				case LbsToKgs:
					result = userInput / 2.2;
					UI::print("Lbs to Kgs: ");
					break;
				case KgsToLbs:
					result = userInput * 2.2;
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



} /* namespace Utilities */
