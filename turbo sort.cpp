#include<iostream>
int main(void)
{
std::ios::sync_with_stdio(false);
 int n=1000001;
 int t[1000001]={0};
 int i,k;
 std::cin>>k;
 
 while(k--)
 {
 std::cin>>i;
 t[i]++;
 }
 i=0;
 while(i<n)
 {
 	while(t[i]--) //-- for same numbers in array
      std::cout<<"\n"<<i;
    i++;
 }
}

