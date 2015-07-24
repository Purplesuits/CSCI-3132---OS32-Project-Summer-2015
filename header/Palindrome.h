//
// Created by Aymen Ben Rkhis on 7/17/15.
//

#ifndef PALINDROME_H
#define PALINDROME_H

#include "Utilities.h"
#include "string"


namespace Utilities{

    class Palindrome : public Utilities{

    public:
        Palindrome(){};
        ~Palindrome(){};
        void execute();
    private:
        void palindrome();
    };

}

#endif //UTILITIES_PALINDROME_H
