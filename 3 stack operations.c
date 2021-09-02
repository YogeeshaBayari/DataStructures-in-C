/*3. Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit.
Support the program with appropriate functions for each of the above operations */
#include <stdio.h>
#define MAX 3
int stack[MAX];
int top = -1;
//a. Push an Element on to Stack
void push()
{
	int item;
	// Stack Overflow situations
	if (top == (MAX - 1))
		printf("\n Stack Overflow");
	else
	{
		printf("\n Enter the element to be pushed :");
		scanf("%d", &item);
		// pushing element to the top of stack
		stack[++top] = item;
	}
}

//b. Pop an Element from Stack
void pop()
{
	// Stack Underflow situations
	if (top == -1)
		printf("\n Stack Underflow");
	else
		printf(" \nPoped element is %d ", stack[top--]);	// poping element from the top of stack
}

//e. Display the status of Stack
void display()
{
	int i;
	if (top == -1)
		printf("\n Sorry Empty Stack");
	else
	{
		printf("\nThe elements of the stack are\n");
		for (i = top; i >= 0; i--)
			printf("stack[%d] = %d\n", i, stack[i]);
	}
}

//c. Demonstrate how Stack can be used to check Palindrome
void palindrome()
{
	int i, count = 0; 
	for (i = 0; i <= (top / 2); i++)
	{
		if (stack[i] == stack[top - i])
			count++;
	}

	if ((top / 2 + 1) == count)
		printf("\n Stack contents are Palindrome");
	else
		printf("\nStack contents are not palindrome");
}

void main()
{
	int choice;
	while (1)
	{
		printf(" \n  STACK OPERATIONS\n");
		printf("1.Push\n 2.Pop\n 3.Display\n 4.Palindrome\n 5.Exit\n");
		printf("Enter your choice\n");
		scanf( " %d", &choice);
		switch (choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				palindrome();
				break;
			case 5:
				return;
			default:
				printf("Invalid choice\n");
		}
	}
}