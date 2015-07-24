/*
 * Converter.h
 *
 *  Created on: 8 Jul 2015
 *      Author: jturner
 */

#ifndef CONVERTER_H_
#define CONVERTER_H_

#include "Utilities.h"

#include <string>
#include <iostream>
#include <limits>



enum{
	FtoC = 1,
	CtoF,
	MetersToFeet,
	FeetToMeters,
	LbsToKgs,
	KgsToLbs
};

namespace Utilities {

	class Converter : public Utilities{
		public:
			Converter();
			virtual ~Converter();

			void execute();


		private:

			void displayMenu();

	};

} /* namespace Utilities */

#endif /* CONVERTER_H_ */
