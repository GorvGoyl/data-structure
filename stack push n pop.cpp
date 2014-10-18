// Stack - Object oriented implementation using arrays
#include <iostream>
using namespace std;
#define MAX_SIZE 101


class Stack
{
private:
  int A[MAX_SIZE];  // array to store the stack
	int top;   // variable to mark the top index of stack.
public:
	// constructor
	Stack()
	{
		top = -1; // for empty array, set top = -1
	}

	// Push operation to insert an element on top of stack.
	void Push(int x)
	{
	  if(top == MAX_SIZE -1) { // overflow case.
			printf("Error: stack overflow\n");
			return;
		}
		A[++top] = x;
	}

	// Pop operation to remove an element from top of stack.
	void Pop()
	{
		if(top == -1) { // If stack is empty, pop should throw error.
			printf("Error: No element to pop\n");
			return;
		}
		top--;
	}

	// Top operation to return element at top of stack.
	int Top()
	{
		return A[top];
	}

	// This function will return 1 (true) if stack is empty, 0 (false) otherwise
	int IsEmpty()
	{
		if(top == -1) return 1;
		return 0;
	}

	// ONLY FOR TESTING - NOT A VALID OPERATION WITH STACK
	// This function is just to test the implementation of stack.
	// This will print all the elements in the stack at any stage.
	void Print() {
		int i;
		printf("Stack: ");
		for(i = 0;i<=top;i++)
			printf("%d ",A[i]);
		printf("\n");
	}
};

int main()
{
    // Code to test the implementation.
    // calling Print() after each push or pop to see the state of stack.
	Stack S;
	S.Push(2);S.Print();
	S.Push(5);S.Print();
	S.Push(10);S.Print();
	S.Pop();S.Print();
	S.Push(12);S.Print();
}

