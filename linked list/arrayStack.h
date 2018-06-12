#pragma once
#include <stdio.h>
#include <conio.h>
#define MAX 10
int stack[MAX];
int top = -1;

//opertions on a stack of array
int push(int value)
{
	if (top < MAX - 1)
	{
		top++;
		stack[top] = value;
		return top;
	}
	else
		return -1;
}

int pop()
{
	int temp;
	if (top != -1)
	{
		temp = stack[top];
		top--;
		return temp;
	}
	else
		return -1;
}

int peek()
{
	if (top != -1)
		return stack[top];
	else
		return -1;
}

void arrayMenu()
{
	int value, switchValue, i;
	do
	{
		system("cls");
		printf("\n1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Show\n");
		printf("0. Exit\n");
		printf("Enter Your choice: ");
		scanf_s("%d", &switchValue);

		switch (switchValue)
		{
		case 1:
			printf("\tEnter the value: ");
			scanf_s("%d", &value);
			push(value);
			break;
		case 2:
			printf("Poped value: %d\n", pop());
			system("pause");
			break;
		case 3:
			printf("Peek value: %d\n", peek());
			system("pause");
			break;
		case 4:
			printf("Stack is: ");
			for (i = top; i >= 0; i--)
				printf("%d ", stack[i]);
			system("pause");
		}
	} while (switchValue);
}

void reverseStack()
{
	int arr[10];
	int i;
	printf("Enter 10 elements in the array:\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &arr[i]);
		push(arr[i]);
	}
	printf("Reverse: ");
	for (i = 0; i < 10; i++)
	{
		arr[i] = pop();
		printf("%d ", arr[i]);
	}
}