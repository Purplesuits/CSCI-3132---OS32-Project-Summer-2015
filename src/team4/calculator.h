calculator.cppLast login: Thu Jul 23 14:43:04 on ttys001
lingxiangs-MacBook-Pro:~ lingxiang$ cd Desktop/project/
lingxiangs-MacBook-Pro:project lingxiang$ g++ -c calculator.cpp 
lingxiangs-MacBook-Pro:project lingxiang$ g++ -o calculator calculator.o
Undefined symbols for architecture x86_64:
  "Utilities::Utilities::Utilities()", referenced from:
      Utilities::Calculator::Calculator() in calculator.o
  "Utilities::Utilities::~Utilities()", referenced from:
      Utilities::Calculator::~Calculator() in calculator.o
  "typeinfo for Utilities::Utilities", referenced from:
      typeinfo for Utilities::Calculator in calculator.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.cpp






























lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.h
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ g++ -o calculator calculator.o
Undefined symbols for architecture x86_64:
  "Utilities::Utilities::Utilities()", referenced from:
      Utilities::Calculator::Calculator() in calculator.o
  "Utilities::Utilities::~Utilities()", referenced from:
      Utilities::Calculator::~Calculator() in calculator.o
  "typeinfo for Utilities::Utilities", referenced from:
      typeinfo for Utilities::Calculator in calculator.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.h
lingxiangs-MacBook-Pro:project lingxiang$ g++ -o calculator calculator.o
Undefined symbols for architecture x86_64:
  "Utilities::Utilities::Utilities()", referenced from:
      Utilities::Calculator::Calculator() in calculator.o
  "Utilities::Utilities::~Utilities()", referenced from:
      Utilities::Calculator::~Calculator() in calculator.o
  "typeinfo for Utilities::Utilities", referenced from:
      typeinfo for Utilities::Calculator in calculator.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
lingxiangs-MacBook-Pro:project lingxiang$ g++ -o calculatr calculator.o
Undefined symbols for architecture x86_64:
  "Utilities::Utilities::Utilities()", referenced from:
      Utilities::Calculator::Calculator() in calculator.o
  "Utilities::Utilities::~Utilities()", referenced from:
      Utilities::Calculator::~Calculator() in calculator.o
  "typeinfo for Utilities::Utilities", referenced from:
      typeinfo for Utilities::Calculator in calculator.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
lingxiangs-MacBook-Pro:project lingxiang$ ls
CMakeLists.txt			FileSystem.h			Motd.h				Utilities.h			encryption.cpp
CSCI3132-UtilitiesMain.cpp	Fread.cpp			Motd.txt			Utilities.o			encryption.h
Command.h			Fwrite.cpp			OS32Memory.cpp			a.out				inputCheck.h
Converter.cpp			HelpMe.cpp			OS32Memory.h			calculator.cpp			main.cpp
Converter.h			HelpMe.h			Palindrome.cpp			calculator.h			test_FS.cpp
DCreate.cpp			ListItems.cpp			Palindrome.h			calculator.o			test_memory.cpp
FCreate.cpp			Login.cpp			Scheduler.h			chper.cpp			test_ui.h
File.cpp			Menu.cpp			UI.cpp				copy1
File.h				Menu.h				UI.h				copy2
FileSystem.cpp			Motd.cpp			Utilities.cpp			copy3
lingxiangs-MacBook-Pro:project lingxiang$ ./calculator
-bash: ./calculator: No such file or directory
lingxiangs-MacBook-Pro:project lingxiang$ g++ -c calculator.o
clang: warning: calculator.o: 'linker' input unused
lingxiangs-MacBook-Pro:project lingxiang$ g++ -c calculator.c
clang: warning: treating 'c' input as 'c++' when in C++ mode, this behavior is deprecated
clang: error: no such file or directory: 'calculator.c'
clang: error: no input files
lingxiangs-MacBook-Pro:project lingxiang$ g++ -c calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ g++ -o  calculator calculator.cpp
Undefined symbols for architecture x86_64:
  "Utilities::Utilities::Utilities()", referenced from:
      Utilities::Calculator::Calculator() in calculator-0f19ae.o
  "Utilities::Utilities::~Utilities()", referenced from:
      Utilities::Calculator::~Calculator() in calculator-0f19ae.o
  "typeinfo for Utilities::Utilities", referenced from:
      typeinfo for Utilities::Calculator in calculator-0f19ae.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.h
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ g++ calculator.
clang: error: no such file or directory: 'calculator.'
clang: error: no input files
lingxiangs-MacBook-Pro:project lingxiang$ g++ calculator.cpp
Undefined symbols for architecture x86_64:
  "Utilities::Utilities::Utilities()", referenced from:
      Utilities::Calculator::Calculator() in calculator-5e1eb2.o
  "Utilities::Utilities::~Utilities()", referenced from:
      Utilities::Calculator::~Calculator() in calculator-5e1eb2.o
  "typeinfo for Utilities::Utilities", referenced from:
      typeinfo for Utilities::Calculator in calculator-5e1eb2.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ g++ -c calculator.cpp
calculator.cpp:79:5: error: 'Utilities' is not a class, namespace, or scoped enumeration
    Utilities::Calculator *cal=new Utilities::Calculator();
    ^
calculator.cpp:79:5: error: reference to 'Utilities' is ambiguous
    Utilities::Calculator *cal=new Utilities::Calculator();
    ^
./calculator.h:9:11: note: candidate found by name lookup is 'Utilities'
namespace Utilities {
          ^
./Utilities.h:29:8: note: candidate found by name lookup is 'Utilities::Utilities'
        class Utilities {
              ^
calculator.cpp:79:36: error: 'Utilities' is not a class, namespace, or scoped enumeration
    Utilities::Calculator *cal=new Utilities::Calculator();
                                   ^
calculator.cpp:79:36: error: reference to 'Utilities' is ambiguous
    Utilities::Calculator *cal=new Utilities::Calculator();
                                   ^
./calculator.h:9:11: note: candidate found by name lookup is 'Utilities'
namespace Utilities {
          ^
./Utilities.h:29:8: note: candidate found by name lookup is 'Utilities::Utilities'
        class Utilities {
              ^
calculator.cpp:86:6: error: 'Utilities' is not a class, namespace, or scoped enumeration
bool Utilities::Calculator::isoperator(char op)  
     ^
calculator.cpp:86:6: error: reference to 'Utilities' is ambiguous
bool Utilities::Calculator::isoperator(char op)  
     ^
./calculator.h:9:11: note: candidate found by name lookup is 'Utilities'
namespace Utilities {
          ^
./Utilities.h:29:8: note: candidate found by name lookup is 'Utilities::Utilities'
        class Utilities {
              ^
calculator.cpp:92:5: error: 'Utilities' is not a class, namespace, or scoped enumeration
int Utilities::Calculator::priority(char op)  
    ^
calculator.cpp:92:5: error: reference to 'Utilities' is ambiguous
int Utilities::Calculator::priority(char op)  
    ^
./calculator.h:9:11: note: candidate found by name lookup is 'Utilities'
namespace Utilities {
          ^
./Utilities.h:29:8: note: candidate found by name lookup is 'Utilities::Utilities'
        class Utilities {
              ^
calculator.cpp:112:5: error: 'Utilities' is not a class, namespace, or scoped enumeration
int Utilities::Calculator::postfix(char pre[] ,char post[],int &n)  
    ^
calculator.cpp:112:5: error: reference to 'Utilities' is ambiguous
int Utilities::Calculator::postfix(char pre[] ,char post[],int &n)  
    ^
./calculator.h:9:11: note: candidate found by name lookup is 'Utilities'
namespace Utilities {
          ^
./Utilities.h:29:8: note: candidate found by name lookup is 'Utilities::Utilities'
        class Utilities {
              ^
calculator.cpp:170:8: error: 'Utilities' is not a class, namespace, or scoped enumeration
double Utilities::Calculator::read_number(char str[],int *i)  
       ^
calculator.cpp:170:8: error: reference to 'Utilities' is ambiguous
double Utilities::Calculator::read_number(char str[],int *i)  
       ^
./calculator.h:9:11: note: candidate found by name lookup is 'Utilities'
namespace Utilities {
          ^
./Utilities.h:29:8: note: candidate found by name lookup is 'Utilities::Utilities'
        class Utilities {
              ^
calculator.cpp:199:8: error: 'Utilities' is not a class, namespace, or scoped enumeration
double Utilities::Calculator::postfix_value(char post[])  
       ^
calculator.cpp:199:8: error: reference to 'Utilities' is ambiguous
double Utilities::Calculator::postfix_value(char post[])  
       ^
./calculator.h:9:11: note: candidate found by name lookup is 'Utilities'
namespace Utilities {
          ^
./Utilities.h:29:8: note: candidate found by name lookup is 'Utilities::Utilities'
        class Utilities {
              ^
calculator.cpp:245:6: error: 'Utilities' is not a class, namespace, or scoped enumeration
bool Utilities::Calculator::CheckSyntax(char pre[])
     ^
calculator.cpp:245:6: error: reference to 'Utilities' is ambiguous
bool Utilities::Calculator::CheckSyntax(char pre[])
     ^
./calculator.h:9:11: note: candidate found by name lookup is 'Utilities'
namespace Utilities {
          ^
./Utilities.h:29:8: note: candidate found by name lookup is 'Utilities::Utilities'
        class Utilities {
              ^
calculator.cpp:262:6: error: 'Utilities' is not a class, namespace, or scoped enumeration
bool Utilities::Calculator::checkCharacters(char pre[])
     ^
calculator.cpp:262:6: error: reference to 'Utilities' is ambiguous
bool Utilities::Calculator::checkCharacters(char pre[])
     ^
./calculator.h:9:11: note: candidate found by name lookup is 'Utilities'
namespace Utilities {
          ^
./Utilities.h:29:8: note: candidate found by name lookup is 'Utilities::Utilities'
        class Utilities {
              ^
calculator.cpp:283:6: error: 'Utilities' is not a class, namespace, or scoped enumeration
bool Utilities::Calculator::checkOP(char pre[])
     ^
fatal error: too many errors emitted, stopping now [-ferror-limit=]
20 errors generated.
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ g++ -c calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ g++ -c calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ g++ -o calculator calculator.cpp
Undefined symbols for architecture x86_64:
  "Utilities::Utilities::Utilities()", referenced from:
      Utilities::Calculator::Calculator() in calculator-a9ff27.o
  "Utilities::Utilities::~Utilities()", referenced from:
      Utilities::Calculator::~Calculator() in calculator-a9ff27.o
  "typeinfo for Utilities::Utilities", referenced from:
      typeinfo for Utilities::Calculator in calculator-a9ff27.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
lingxiangs-MacBook-Pro:project lingxiang$ g++ -o calculator calculator.o
Undefined symbols for architecture x86_64:
  "Utilities::Utilities::Utilities()", referenced from:
      Utilities::Calculator::Calculator() in calculator.o
  "Utilities::Utilities::~Utilities()", referenced from:
      Utilities::Calculator::~Calculator() in calculator.o
  "typeinfo for Utilities::Utilities", referenced from:
      typeinfo for Utilities::Calculator in calculator.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.h
lingxiangs-MacBook-Pro:project lingxiang$ g++ -c calculator.cpp
calculator.cpp:78:5: error: 'Utilities' is not a class, namespace, or scoped enumeration
    Utilities::Calculator *cal=new Utilities::Calculator();
    ^
calculator.cpp:78:5: error: reference to 'Utilities' is ambiguous
    Utilities::Calculator *cal=new Utilities::Calculator();
    ^
./calculator.h:9:11: note: candidate found by name lookup is 'Utilities'
namespace Utilities {
          ^
./Utilities.h:29:8: note: candidate found by name lookup is 'Utilities::Utilities'
        class Utilities {
              ^
calculator.cpp:78:36: error: 'Utilities' is not a class, namespace, or scoped enumeration
    Utilities::Calculator *cal=new Utilities::Calculator();
                                   ^
calculator.cpp:78:36: error: reference to 'Utilities' is ambiguous
    Utilities::Calculator *cal=new Utilities::Calculator();
                                   ^
./calculator.h:9:11: note: candidate found by name lookup is 'Utilities'
namespace Utilities {
          ^
./Utilities.h:29:8: note: candidate found by name lookup is 'Utilities::Utilities'
        class Utilities {
              ^
4 errors generated.
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ g++ -c calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ g++ -o ccalculator.cpp
calculator.cpp  calculator.h    calculator.o    chper.cpp       copy1/          copy2/          copy3/          
lingxiangs-MacBook-Pro:project lingxiang$ g++ -o calculator calculator.o
Undefined symbols for architecture x86_64:
  "Utilities::Utilities::Utilities()", referenced from:
      Utilities::Calculator::Calculator() in calculator.o
  "Utilities::Utilities::~Utilities()", referenced from:
      Utilities::Calculator::~Calculator() in calculator.o
  "typeinfo for Utilities::Utilities", referenced from:
      typeinfo for Utilities::Calculator in calculator.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.h
lingxiangs-MacBook-Pro:project lingxiang$ g++ -c calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ g++ -o calculator calculator.o
lingxiangs-MacBook-Pro:project lingxiang$ ./calculator 
enter expression end with ;：1+2;
answer:  3
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.cpp 
lingxiangs-MacBook-Pro:project lingxiang$ g++ -c calculator.cpp
calculator.cpp:274:92: error: use of undeclared identifier 'isoperator'; did you mean 'operator'?
                if(!((pre[i]>='0' && pre[i] <='9')||pre[i]=='('||pre[i]==')'||pre[i] =='.'||pre[i]==';'||isoperator(pre[i])))
                                                                                                         ^
calculator.cpp:293:5: error: use of undeclared identifier 'isoperator'; did you mean 'operator'?
        if(isoperator(pre[0])||isoperator(pre[(unsigned)strlen(pre)-1]))
           ^
calculator.cpp:293:25: error: use of undeclared identifier 'isoperator'; did you mean 'operator'?
        if(isoperator(pre[0])||isoperator(pre[(unsigned)strlen(pre)-1]))
                               ^
calculator.cpp:300:20: error: use of undeclared identifier 'isoperator'; did you mean 'operator'?
                if(isoperator(pre[i]))
                   ^
calculator.cpp:302:28: error: use of undeclared identifier 'isoperator'; did you mean 'operator'?
                        if(isoperator(pre[i+1]))
                           ^
calculator.cpp:397:9: error: use of undeclared identifier 'cal_printout'
        strcat(cal_printout,a);
               ^
calculator.cpp:401:2: error: use of undeclared identifier 'cal_printout'
        cal_printout[(unsigned)strlen(cal_printout)]=a;
        ^
calculator.cpp:401:32: error: use of undeclared identifier 'cal_printout'
        cal_printout[(unsigned)strlen(cal_printout)]=a;
                                      ^
calculator.cpp:402:2: error: use of undeclared identifier 'cal_printout'
        cal_printout[(unsigned)strlen(cal_printout)]='\0';
        ^
calculator.cpp:402:32: error: use of undeclared identifier 'cal_printout'
        cal_printout[(unsigned)strlen(cal_printout)]='\0';
                                      ^
10 errors generated.
lingxiangs-MacBook-Pro:project lingxiang$ g++ -c calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ g++ -o calculator calculator.o
lingxiangs-MacBook-Pro:project lingxiang$ g++ -c calculator.cpp
lingxiangs-MacBook-Pro:project lingxiang$ ls
CMakeLists.txt			FileSystem.h			Motd.h				Utilities.cpp			copy3
CSCI3132-UtilitiesMain.cpp	Fread.cpp			Motd.txt			Utilities.h			encryption.cpp
Command.h			Fwrite.cpp			MyPlayground.playground		Utilities.o			encryption.h
Converter.cpp			HelpMe.cpp			OS32Memory.cpp			calculator			main.cpp
Converter.h			HelpMe.h			OS32Memory.h			calculator.cpp			test_FS.cpp
DCreate.cpp			ListItems.cpp			Palindrome.cpp			calculator.h			test_memory.cpp
FCreate.cpp			Login.cpp			Palindrome.h			calculator.o			test_ui.h
File.cpp			Menu.cpp			Scheduler.h			chper.cpp			untitled folder
File.h				Menu.h				UI.cpp				copy1
FileSystem.cpp			Motd.cpp			UI.h				copy2
lingxiangs-MacBook-Pro:project lingxiang$ vi calculator.h

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include "Utilities.h"
#include <string>
#include <iostream>
using namespace std;
namespace Utilities {

        class Calculator
        {
        public:
                //static char cal_printout[200];
                Calculator(){}
                ~Calculator() {}
                void execute();
        private:
                char cal_printout[200];
                bool isoperator(char op);
                int priority(char op);
                int postfix(char pre[] , char post[],int &n);
                double read_number(char str[],int *i);
                double postfix_value(char post[]);
                bool checkCharacters(char pre[]);
                void printError(char array[],int l);
                bool checkOP(char pre[]);
                bool checkDot(char pre[]);
                bool checkBracket(char pre[]);
                bool checkSeicolon(char pre[]);
                void printA(char a[]);
                bool CheckSyntax(char pre[]);
                void printC(char a);
        };

}
  template <class ElemType> class MyStack
    {
    public:
        const static  int MAXSIZE =100;
        ElemType data[MAXSIZE];
        int top;

    public:
        void init();
        int length();
        bool empty();
        ElemType gettop();
        void push(ElemType x);
        ElemType pop();
    };
    template<class T> void MyStack<T>::init()
    {
"calculator.h" 103L, 2351C
