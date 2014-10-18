//Tower of Hanoi - Backtracking
//time complexity - 2^n

#include <stdio.h>
void hanoi( char from , char to , char other , int n) {  //from ->source   to ->destination    other->Auxillary peg
        if(n>0){
        hanoi(from , other , to , n - 1);  // changing 'to' -> 'other'
        printf(" move %c -> %c\n", from , to);
        hanoi(other , to , from , n - 1);
    }
}
int main () {
    int n;
    printf("enter total disks: ");
    scanf("%d", &n);
    hanoi('A', 'C', 'B', n);
return 0;
}
