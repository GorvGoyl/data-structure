//print all binary strings of n bits - BACKTRACKING
//time - 2^n

#include<iostream>
using namespace std;
int a[50];
int k;
void binary(int n){
	if(n<1){
	for(int i=0;i<k;i++)
	cout<<a[i];
	cout<<"\n";
	}
	
	else{
		
		a[n-1]=0;    cout<<"before binary n: "<<n<<"\n";
		binary(n-1); cout<<"after binary n: "<<n<<"\n";
		a[n-1]=1;    cout<<"n-1: "<<n-1<<"\n";
		binary(n-1);
	}
	
}

int main()
{
	for(int i=0;i<50;i++)
	a[i]=0;
	k=4;
binary(4);










}

