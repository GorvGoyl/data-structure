#include<iostream>          //space - O(n)
#include<string.h>          //Time - O(n)
#include<stack>
using namespace std;

void reverse(char *ch,int n)
{     int i;
	  stack<char> stk;
	for(i=0;i<n;i++)
	stk.push(ch[i]);
	for(i=0;i<n;i++)
	{
	   ch[i]=stk.top();
	   stk.pop();
	}

}
int main(void)
{
	char ch[51];
	cout<<"enter the string to reverse: ";
	gets(ch);

 reverse(ch,strlen(ch));
	 int i=0;
	 cout<<"\nreversed string is: ";
	 while(ch[i]!='\0')
	 {
	 	cout<<ch[i];   i++;
	 }
}

