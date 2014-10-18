#include<iostream>   							//worst array - [5, 4, 3, 5, 8, 5]

int partition(int* a, int left, int right)    //int* a = int a[] //passing array as argument
{   int low=left;
	int pivot=a[low],pindex=low;           //pivot choosen as first element of array
	left+=1;						       //scanning starts from very next pivot element
	                               
while(left<=right)          			   //loop runs untill scanning crosses each other
{
	//below loops runs untill they found a large element on LHS and small element on RHS
	while(a[left]<pivot&&left<=right) left++; //keep moving index to right till element < pivot

	while(a[right]>=pivot&&right>low) right--;  //move index to left till element>=pivot
	                       				      // if right is @ 0 then no "right--"
	                             
	if(left>right)            	     //if left++ and right-- crosses then swap pivot<-->a[j] and break
		{                             //it means all small elements on LHS of pivot,vice-versa for RHS
   		 int tmp=a[low];
  	 	 a[low]=a[right];
 	 	 a[right]=tmp;
 	 	 break;
		}
	
	int tmp=a[left];       	  //swapping left++ and right-- so that smaller on left side and larger on right side
	a[left]=a[right];
	a[right]=tmp;
}

right=pindex;  				//indicating the index of pivot
return pindex;
}

void quicksort(int* a, int left, int right)   		//int* a -->passing whole array as argument
{
	if(left<right)    							 //base condition //loop exits when single element remains
	{
		int pindex=partition(a, left, right);   	//returning the pivot index
		quicksort(a, left, pindex-1);  			  //sorting the leftside array of pivot index
        quicksort(a, pindex+1, right);   		//sorting the rightside array of pivot index

	}

}


int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin>>n;
	int a[n],i=0;
while(i<n)
{
	std::cin>>a[i]; i++;
}
int left=0;
int right=n-1;
quicksort(a,left,right);   //passing array,first and last index

i=0;
while(i<n)
{
std::cout<<a[i]<<"\n";
i++;
}

}


