#include <iostream>
#include <cstdio>
using namespace std;

int main() {
 // your code goes here
 int a, arr[1000001]={0}, b;
 scanf("%d", &a);
 while(a--) {
  scanf("%d", &b);
  arr[b]++;
 }
 for(int i=0; i<1000001; i++) {
  while(arr[i]>0) {
   printf("%d\n", i);
   arr[i]--;
  }
 }
 return 0;
}
