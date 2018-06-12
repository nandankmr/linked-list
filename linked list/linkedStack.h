#pragma once
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct stack
{
	int a;
	struct stack *next;
};

struct stack *top = NULL;

int push(int value)
{
	struct stack *temp;
	temp = (struct stack *)malloc(sizeof(struct stack));
	temp->a = value;
	temp->next = top;
	top = temp;
	return value;
}

int pop()
{
	int temp;
	if (top)
	{
		temp = top->a;
		top = top->next;
		return temp;
	}
	return NULL;
}

int peek()
{
	if (top)
		return top->a;
	return NULL;
}

void displayStack()
{
	struct stack *p;
	for (p = top; p; p = p->next)
		printf("%d ", p->a);
	printf("\n");
}

void linkedMenu()
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
			displayStack();
			system("pause");
		}
	} while (switchValue);
}

//reverse of array using stack;


