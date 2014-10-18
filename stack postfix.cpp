#include<iostream>
#include<stack>
using namespace std;
int main(void)
{

int t1,t2;
stack<int> s;
int res;
string ch;
cout<<"Enter a postfix expression to evaluate result\n";
cin>>ch; //store in a string
for(int i=0;i<ch.length();i++)  //just change this line for Prefix evaluation -> (int i=ch.length();i>=0;i--)
{
	if((ch[i]!='*') && (ch[i]!='/') && (ch[i]!='-') && ( ch[i]!='+'))
	{
		s.push(ch[i]-48); // important step:storing correct 'int' value instead of char value and escaping operators
	}
else  //if operator found
{
	t1=s.top(); //1st operand
	s.pop();
	t2=s.top();  //2nd operand
	s.pop();
	if(ch[i]=='*')
	{
	res=t2*t1;  // 2nd operand (operator) 1st operand
 	s.push((res));
	}
	else if(ch[i]=='/')
{
 res=t2/t1;
 s.push((res));
	}	else if(ch[i]=='-')
{
 res=t2-t1;
 s.push((res));
	}
	else if(ch[i]=='+')
	{
	 res=t2+t1;
	 s.push((res));
	}
	
	
}


}
cout<<s.top();

}

