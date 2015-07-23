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
        this->top = 0;
    }

    template<class T> bool MyStack<T>::empty()
    {
        return this->top == 0? true : false;
    }

    template<class T> T MyStack<T>::gettop()
    {
        if(empty())
        {
            cout << "stack empty！\n";
            exit(1);
        }
        return this->data[this->top-1];
    }
    template<class T> int MyStack<T>::length()
    {

        return top;

    }
 template<class T> void MyStack<T>::push(T x)
    {
        if(this->top == MAXSIZE)
        {
            cout << "stack full！\n";
            exit(1);
        }
        this->data[this->top] =x;
        this->top ++;
    }
  
    template<class T> T MyStack<T>::pop()
    {
        if(this->empty())
        {
            cout << "stack empty! \n";
            exit(1);
        }
  
        T e =this->data[this->top-1];
        this->top--;
        return e;
    }


#endif

