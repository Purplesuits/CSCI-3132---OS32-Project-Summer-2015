/*
 this is the calculator class 
 
 calculator can do basic addtion mutilplcation division and subtraction
 
 */



#include"calculator.h"
#include <iostream>
#include<vector>
#include<string.h>
#include "UI.h"
using namespace std;
using namespace Utilities;


/*this is example main class*/
/*int main()
{
    
    Calculator *cal=new Calculator();
    cal->execute();
    return 0;
}*/
/*this is the excute function the only public function
 outside funtion want to use calculator, just need to called this function
 */
void Calculator::execute()
{
    MyStack<int> stack ;
    stack.init();
    //strcpy(cal_printout,"the answer");
    char TheExpression[100];
    UI::println( "Enter expression such as the expression (1+2)*(3-4)   :");
    
    string expression=UI::readLine();
    strcpy(TheExpression,expression.c_str());
    char post[100] ;
    int n =0;
    if(!postfix(TheExpression,post,n))
    {
        char a[]= "answer: ";
        printA(a);
        //cout<<cal_printout;
        string tmp=to_string(postfix_value(post));
        char b[30];
        strcpy(b,tmp.c_str());
        
        printA(b);
        char c[]= "\n";
        printA(c);
        
        UI::println( cal_printout);
        
    }
    else
        UI::println( cal_printout);

    
}




/*
 operation cannot be the first or the last one
 and the opertion cant not connect with another operation
 */
bool Calculator::CheckSyntax(char pre[])
{
    if(checkCharacters(pre))
    {
        return 1;
    }
    else if(checkOP(pre))
    {
        return 1;
    }
    else if(checkBracket(pre))
    {
        return 1;
    }
    else if(checkDot(pre))
    {
        return 1;
    }
    else if(checkSeicolon(pre))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
    
}


/*check the characters of the input string*/
bool Calculator::checkCharacters(char pre[])
{
    int i;
    for(i=0;i<(unsigned)strlen(pre);i++)
    {
        if(!((pre[i]>='0' && pre[i] <='9')||pre[i]=='('||pre[i]==')'||pre[i] =='.'||pre[i]==';'||isoperator(pre[i])))
        {
            printError(pre,i);
            return 1;
            
        }
    }
    
    return 0;
}

/*
 this function is for check the operators
 */
bool Calculator::checkOP(char pre[])
{
    int i;
    /*
     operator cannot show in the first one or the last one;
     */
    if(isoperator(pre[0])||isoperator(pre[(unsigned)strlen(pre)-1]))
    {
        char a[]="operator cannot be first or the end";
        printError(a);
        return 1;
    }
    /*check for a set of operator
     such as "+++"
     */
    for(i=0;i<(unsigned)strlen(pre);i++)
    {
        if(isoperator(pre[i]))
        {
            if(isoperator(pre[i+1]))
            {
                printError(pre,i);
                char a[]="can not have continuous operators";
                printError(a);
                return 1;
            }
        }
        
    }
    return 0;
}

//check the dot of the input string, decimals number such as 3.14 has dot
//we can allow there many contigous dot in it
bool Calculator::checkDot(char pre[])
{
    int i;
    if(pre[0]=='.'||pre[(unsigned)strlen(pre)-1]=='.')
    {
        printError(pre,0);
        char a[]="dotr cannot be first or the last one";
        printError(a);
        return 1;
    }
    for(i=0;i<(unsigned)strlen(pre);i++)
    {
        if(pre[i]=='.')
        {
            if(pre[i+1]==!'.'||pre[i-1]=='.')
            {
                printError(pre,i);
                char a[]="operator has issues";
                printError(a);
                return 1;
            }
        }
        
    }
    return 0;
}
//check the bracket of the function
bool Calculator::checkBracket(char pre[])
{
    char b[100];
    
    int i,n=0,sum=0;
    for(i=0;i<(unsigned)strlen(pre);i++)
    {
        if(pre[i]=='('||pre[i]==')')
        {
            b[n]=pre[i];
            n++;
        }
    }
    
    for(i=0;i<(unsigned)strlen(b);i++)
    {
        if(b[i]=='(')
            sum++;
        if(b[i]==')')
            sum--;
        if(sum<0)
        {
            char a[]="you have bracket issues";
            printError(a);
            return 1;
            
        }
    }
    if(sum!=0)
    {
        char a[]="you have bracket issues";
        printError(a);
        return 1;
    }
    if(((unsigned)strlen(pre))==(unsigned)strlen(b))
    {
        char a[]="you need number in the expression as well";
        printError(a);
        return 1;
    }
    return 0;
}



//check the semicolon
bool Calculator::checkSeicolon(char pre[])
{
    int i;
    int length=(strlen(pre)-1);
    if(pre[(unsigned)strlen(pre)-1]!=';')
    {
        char a[]=";";
        strcat(pre,a);
    }
    for(i=0;i<length;i++)
    {
        if(pre[i]==';')
        {
            printError(pre,i);
            return 1;
        }
    }
    return 0;
    
}



//this function will add bracket beside the error point
void Calculator::printError(char array[],int l)
{
    int i;
    char bracketA[]=" {";
    char bracketB[]="} ";
    for( i =0 ;i <(unsigned)strlen(array);i++)
    {
        if(i==l)
            printA(bracketA);
        printC(array[i]);
        if(i==l)
            printA(bracketB);
    }
    
    
}

//

void Calculator::printError(char array[])
{
    printA(array);
}
/*
 add a char array into the cal_print
 
 */
void Calculator::printA(char a[])
{
    strcat(cal_printout,a);
}



/*
 
 
 add a single cahr into char array
 
 
 */
void Calculator::printC(char a)
{
    cal_printout[(unsigned)strlen(cal_printout)]=a;
    cal_printout[(unsigned)strlen(cal_printout)+1]='\0';
}


//check it is operator or not
bool Calculator::isoperator(char op)
{
    return ((op=='+')||(op=='-')||(op=='*')||(op=='/'));
}


//set the priotiy for the operator since additoin and multiplication has differetn
//priotity
int Calculator::priority(char op)
{
    
    if(op==';')
    {
        return -1;
    }
    else if(op=='(')
    {
        return 0;
    }
    else if(op=='+'||op=='-')
    {
        return 1;
    }
    else if(op=='/'||'*')
    {
        return 2;
    }
    return -1;
}

//convert the expression into postexpression
int Calculator::postfix(char Preex[] ,char Postexp[],int &n)
{
    memset( &cal_printout, 0, sizeof( char )*200 );
    if(CheckSyntax(Preex))
    {
        char a[]="\n    --- Syntax issuse ---   ";
        printA(a);
        return 1;
    }
    int i=0,j=0;
    n=0;
    MyStack<char> mystack;
    
    mystack.init();
    
    mystack.push(';');
    
    while(Preex[i]!=';')
    {
        if((Preex[i]>='0' && Preex[i] <='9')||Preex[i] =='.')
        {
            Postexp[j++] = Preex[i];
            n++;
        }
        else if (Preex[i]=='(')
            mystack.push(Preex[i]);
        else if(Preex[i] ==')')
        {
            while(mystack.gettop()!='(')
            {
                Postexp[j++] = mystack.pop();
                n++;
            }
            mystack.pop();
        }
        else if (isoperator(Preex[i]))
        {
            Postexp[j++] = ' ';
            n++;
            while(priority(Preex[i]) <= priority(mystack.gettop()))
            {
                
                Postexp[j++] = mystack.pop();
                n++;
            }
            
            mystack.push(Preex[i]);
        }
        
        i++;
    }
    while(mystack.top)
    {
        Postexp[j++] = mystack.pop();
        n++;
    }
    return 0;
}
//read the double
double Calculator::read_number(char str[],int *i)
{
    double theNUM=0.0;
    int k = 0;
    while(str[*i] >='0' && str[*i]<='9')
    {
        theNUM = theNUM*10+(str[*i]-'0');
        (*i)++;
    }
    
    if(str[*i]=='.')
    {
        (*i)++;
        while(str[*i] >= '0'&&str[*i] <='9')
        {
            theNUM = theNUM * 10 + (str[*i]-'0');
            (*i)++;
            k++;
        }
    }
    while(k!=0)
    {
        theNUM /= 10.0;
        k--;
    }
    
    return theNUM;
}
//get the value
double Calculator::postfix_value(char postexp[])
{
    
    int i=0;
    double num1,num2;
    
    MyStack<double> cal_stack;
    cal_stack.init();
    
    
    
    while(postexp[i] !=';')
    {
        if(postexp[i] >='0' && postexp[i] <='9')
            cal_stack.push(read_number(postexp,&i));
        else if(postexp[i] == ' ')
            i++;
        else if (postexp[i] =='-')
        {
            num2 = cal_stack.pop();
            num1 = cal_stack.pop();
            cal_stack.push(num1-num2);
            i++;
        }
        else if (postexp[i] =='+')
        {
            num2 = cal_stack.pop();
            num1 = cal_stack.pop();
            cal_stack.push(num1+num2);
            i++;
        }
        
        else if (postexp[i] =='/')
        {
            num2 = cal_stack.pop();
            num1 = cal_stack.pop();
            cal_stack.push(num1/num2);
            i++;
        }
        else if (postexp[i] =='*')
        {
            num2 = cal_stack.pop();
            num1 = cal_stack.pop();
            cal_stack.push(num1*num2);
            i++;
        }
        
    }
    return cal_stack.gettop();
}  





