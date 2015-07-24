#include <iostream>
#include<vector>
#include<string.h>
using namespace std;
void printC(char a);


char *calculator(char[]);



void printA(char a[]);
bool CheckSyntax(char pre[]);
static bool isoperator(char op);                           
int priority(char op);                             
int postfix(char pre[] , char post[],int &n);      
double read_number(char str[],int *i);             
double postfix_value(char post[]);
//void CharMemAllocate(char *array,int length);
bool checkCharacters(char pre[]);   
void printError(char array[],int l);
bool checkOP(char pre[]);
bool checkDot(char pre[]);
bool checkBracket(char pre[]);
bool checkSeicolon(char pre[]);
char cal_printout[200]; 
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

char *calculator(char exp[])
{
    MyStack<int> stack ;
    stack.init();
    char post[100];
   
    int n =0;
    if(postfix(exp,post,n)!=1)
    { 
	//char a[];
        char a[]= "answer:  ";
	printA(a);
    	cout<<postfix_value(post)<<endl;
	
    }
    
   return cal_printout;
}
int main()
{ 
    char exp[100];
    cout << "enter expression end with ;：";
    cin >> exp;
    char *out=calculator(exp);
    cout<<out<<endl;
    return 0;

}
/*int main()  
{  
    MyStack<int> stack ;  
    stack.init();  
     strcpy(cal_printout,"the answer");
    //char pre[] ="22/(5*2+1)#";
  //  char *exp1;
    
    char exp[100];  
    cout << "enter expression end with ;：";  
    cin >> exp;
	cout << "the expression "<<exp<<endl;  
    //CharMemAllocate(exp1,(unsigned)strlen(exp));
   // cout<<"the length"<<(unsigned)strlen(exp)<<endl;
    char post[100] ;  
    //cout <<"expression："<< pre << endl;  
  
    int n =0;           
    postfix(exp,post,n);  
   //cout <<"expression：";  
    //for( int i =0 ;i < n ;i++)  
    //    cout << post[i] ;  
  
    cout << "answer:  ";  
    cout << postfix_value(post) << endl;  
  
    //system("pause");  
} */ 
  
static bool isoperator(char op)  
{  
    return ((op=='+')||(op=='-')||(op=='*')||(op=='/'));
}  
  
  
int priority(char op)  
{  
    switch(op)  
    {  
    case ';':  
        return -1;  
    case '(':  
        return 0;  
    case '+':  
    case '-':  
        return 1;  
    case '*':  
    case '/':  
        return 2;  
    default :  
        return -1;  
    }  
}  
  
  
int postfix(char pre[] ,char post[],int &n)  
{ 
   if( CheckSyntax(pre))
	{
		char a[]=" has syntax issuse";
		printA(a);
//		cout<<cal_printout<<endl;
		return 1;
	}
   int i=0,j=0,q=0;
   n=0;
    MyStack<char> stack;
     
    stack.init();        
  
    stack.push(';');    
  
  while(pre[i]!=';')  
//for(q=0;q<(unsigned)strlen(pre);q++)
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
	//while(stack.length()!=0)  
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
  
double read_number(char str[],int *i)  
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
  
double postfix_value(char post[])  
{  
    MyStack<double> stack;     
    stack.init();  
  
    int i=0,j ;  
    double x1,x2;  
  
   while(post[i] !=';')
//for(i=0;i<=(unsigned)strlen(post);i++)  
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

bool CheckSyntax(char pre[])
{
 if(checkCharacters(pre)||checkOP(pre)||checkDot(pre)|| checkBracket(pre)||checkSeicolon(pre))
{
	return 1;

} 	
else
{

	return 0;
}


 
} 
/*void CharMemAllocate(char *array,int length)
{
	array=(char*)malloc(length*sizeof(char));
	if(array==NULL)
	{
		cout<<"cannot allocate the memory";
	}


}
*/
bool checkCharacters(char pre[])
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
operation cannot be the first or the last one
and the opertion cant not connect with another operation
*/
bool checkOP(char pre[])
{
	int i;
	if(isoperator(pre[0])||isoperator(pre[(unsigned)strlen(pre)-1]))
	{	
		
		return 1;
	}
        for(i=0;i<(unsigned)strlen(pre);i++)
        {
                if(isoperator(pre[i]))
                {
                        if(isoperator(pre[i+1]))
                        return 1;
                }

        }
        return 0;	
}
bool checkDot(char pre[])
{
	int i;
	if(pre[0]=='.'||pre[(unsigned)strlen(pre)-1]=='.')
        {

                return 1;
        }
        for(i=0;i<(unsigned)strlen(pre);i++)
        {
                if(pre[i]=='.')
                {
                        if(pre[i+1]==!'.'||pre[i-1]=='.')
                        return 1;
                }

        }
        return 0;
}
bool checkBracket(char pre[])
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
			return 1;
	}
	if(sum!=0)
	return 1;
	return 0;
}
bool checkSeicolon(char pre[])
{
	int i;
	if(pre[(unsigned)strlen(pre)-1]!=';')
		{
			printError(pre,(unsigned)strlen(pre)-1);
			char a[]="end with semicolon";
			printA(a);
			return 1;
		}
	for(i=0;i<(strlen(pre)-1);i++)
		{
			if(pre[i]==';')
			{
			printError(pre,i);
			return 1;	
			}
		}
		return 0;

}
void printError(char array[],int l)
{
	int i;
	char bracketA[]=" {";
	char bracketB[]="} ";
	for( i =0 ;i <(unsigned)strlen(array);i++)
       {
	 if(i==l)
	 	//cout <<" [";
	 	//cout << array[i];
		printA(bracketA);
		printC(array[i]);
	//	strcat(cal_printout," {");
	//	strcat(cal_printout,array[i]);
	if(i==l)	
		printA(bracketB);
		//strcat(cal_printout," }");
        }
	
  
}
void printA(char a[])
{
	strcat(cal_printout,a);
}
void printC(char a)
{
	cal_printout[(unsigned)strlen(cal_printout)]=a;
	cal_printout[(unsigned)strlen(cal_printout)]='\0';
}
