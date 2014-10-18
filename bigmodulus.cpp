//http://forthright48.blogspot.in/2012/04/big-mod-algorithm-value-of-p-m.html
//Problem: Given a value ( x ^ y ), what is the remainder if it is divided by m, i.e. , what is the value of ( x ^ y ) % m? For example, what is the value of ( 17892 ^ 90812 ) % 9123?

#include<iostream>
using namespace std;

// Big-Mod Algorithm (recursive)...less efficient
/*
int big_mod(int x,int y, int m)
{	
	if(y==0)// If power is 0 ( a ^ 0 ), return 1

	return 1;
	if(y%2!=0) // If power is odd, x ^ 7 = x * x ^ 6
	{
		return ( (x%m)*(big_mod(x,y-1,m)) )%m;
	}
	else{
		int c=big_mod(x,y/2,m);
		return (c*c)%m;
	}
	
}
*/
// Big-Mod Algorithm (iterative)
long long big_mod ( long long a, long long p, long long m )
{
    long long res = 1;
    long long x = a;
    
    while ( p!=0 ){  //while(p)
        //if p is odd i.e.. if(p & 1)
        if ( p%2!=0 ) 
		res = ( res * x ) % m;
	
        x = ( x * x ) % m;
        
		p = p/2; // i.e.. p=p>>1;
    }

    return res;
}


int main(void)
{
long long x,y,m;

cout<<"enter a number\n";
cin>>x;
cout<<"enter its power\n";
cin>>y;
cout<<"enter the mod\n";
cin>>m;
cout<<"its modulus is: "<<big_mod(x,y,m);


}

