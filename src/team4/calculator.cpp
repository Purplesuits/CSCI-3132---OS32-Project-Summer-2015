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

void Calculator::execute()
{
    MyStack<int> stack ;
    stack.init();
    //strcpy(cal_printout,"the answer");
    char exp[100];
    UI::println( "Enter expression such as the expression (1+2)*(3-4)   :");
    
    string expression=UI::readLine();
    strcpy(exp,expression.c_str());
    char post[100] ;
    int n =0;
    if(!postfix(exp,post,n))
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

bool Calculator::isoperator(char op)
{
    return ((op=='+')||(op=='-')||(op=='*')||(op=='/'));
}


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
    return 1;
}


int Calculator::postfix(char pre[] ,char post[],int &n)
{
    memset( &cal_printout, 0, sizeof( char )*200 );
    if(CheckSyntax(pre))
    {
        char a[]="\n    --- Syntax issuse ---   ";
        printA(a);
        return 1;
    }
    int i=0,j=0,q=0;
    n=0;
    MyStack<char> stack;
    
    stack.init();
    
    stack.push(';');
    
    while(pre[i]!=';')
    {
        if((pre[i]>='0' && pre[i] <='9')||pre[i] =='.')
        {
            post[j++] = pre[i];
            n++;
        }
        else if (pre[i]=='(')
            stack.push(pre[i]);
        else if(pre[i] ==')')
        {
            while(stack.gettop()!='(')
            {
                post[j++] = stack.pop();
                n++;
            }
            stack.pop();
        }
        else if (isoperator(pre[i]))
        {
            post[j++] = ' ';
            n++;
            while(priority(pre[i]) <= priority(stack.gettop()))
            {
                
                post[j++] = stack.pop();
                n++;
            }
            
            stack.push(pre[i]);
        }
        
        i++;
    }
    while(stack.top)
    {
        post[j++] = stack.pop();
        n++;
    }
    return 0;
}

double Calculator::read_number(char str[],int *i)
{
    double x=0.0;
    int k = 0;
    while(str[*i] >='0' && str[*i]<='9')
    {
        x = x*10+(str[*i]-'0');
        (*i)++;
    }
    
    if(str[*i]=='.')
    {
        (*i)++;
        while(str[*i] >= '0'&&str[*i] <='9')
        {
            x = x * 10 + (str[*i]-'0');
            (*i)++;
            k++;
        }
    }
    while(k!=0)
    {
        x /= 10.0;
        k--;
    }
    
    return x;
}

double Calculator::postfix_value(char post[])
{
    MyStack<double> stack;
    stack.init();
    
    int i=0,j ;
    double x1,x2;
    
    while(post[i] !=';')
    {
        if(post[i] >='0' && post[i] <='9')
            stack.push(read_number(post,&i));
        else if(post[i] == ' ')
            i++;
        else if (post[i] =='+')
        {
            x2 = stack.pop();
            x1 = stack.pop();
            stack.push(x1+x2);
            i++;
        }
        else if (post[i] =='-')
        {
            x2 = stack.pop();
            x1 = stack.pop();
            stack.push(x1-x2);
            i++;
        }
        else if (post[i] =='*')
        {
            x2 = stack.pop();
            x1 = stack.pop();
            stack.push(x1*x2);
            i++;
        }
        else if (post[i] =='/')
        {
            x2 = stack.pop();
            x1 = stack.pop();
            stack.push(x1/x2);
            i++;
        }
    }
    return stack.gettop();  
}  





