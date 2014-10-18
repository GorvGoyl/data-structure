//Fibonacci Sequence - Recursion with memoization
//time - O(n) 
//space - O(n) (depth of recursion tree)
#include<iostream>
using namespace std;
int a [100];

int fibo(int n){
	if(n<=1){   //--- [1]
		return n;
	}
	if (a[n]!=-1)
	{
		return a[n];
	}
	
	a[n]=fibo(n-1)+fibo(n-2);
	return a[n];
	
}

int main()
{int n;
cout<<"enter a fibonacci number\n";
cin>>n;
for(int i=0;i<100;i++){
	a[i]=-1;
}
//a[0]=0;a[1]=1; // can be used if omitting [1]
cout<<fibo(n);




}

