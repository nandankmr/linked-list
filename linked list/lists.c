#include <stdio.h>
#include <malloc.h>
#include <conio.h>

//linked list definition
struct List
{
	int a;
	char c;
	struct List * next;
};

//Doubly linked list definition
struct DoublyList
{
	int a;
	struct DoublyList *next, *previous;
};

struct List *insertNode(struct List* start)
{
	struct List *p, *q;
	if (!start)
	{
		start = (struct List*)malloc(sizeof(struct List));     //memory allocation
		scanf_s("%d", &start->a);
		start->next = NULL;
	}
	else
	{
		for (p = start; p->next != NULL; p = p->next);
		q = (struct List*)malloc(sizeof(struct List));
		scanf_s("%d", &q->a);
		p->next = q;
		q->next = NULL;
	}
	return start;
}

struct List *insertValue(struct List* start, int data)
{
	struct List *p, *q;
	if (!start)
	{
		start = (struct List*)malloc(sizeof(struct List));     //memory allocation
		start->a = data;
		start->next = NULL;
	}
	else
	{
		for (p = start; p->next != NULL; p = p->next);
		q = (struct List*)malloc(sizeof(struct List));
		q->a = data;
		p->next = q;
		q->next = NULL;
	}
	return start;
}

void display(struct List* start)
{
	struct List *p;
	for (p = start; p != NULL; p = p->next)
		printf("%d ", p->a);
}

//merge two sorted linked lists
struct List* sortedMerge(struct List *start1, struct List *start2)
{
	//int temp;
	struct List *p, *q, *tempStart, *r;
	tempStart = NULL;
	for (p = start1,  q = start2; p != NULL && q != NULL;)
	{
		if (p->a < q->a)
		{
			tempStart = insertValue(tempStart, p->a);
			p = p->next;
		}
		else
		{
			tempStart = insertValue(tempStart, q->a);
			q = q->next;
		}
	}
	if (p == NULL)
		r = q;
	else
		r = p;
	for (; r != NULL; r = r->next)
		tempStart = insertValue(tempStart, r->a);
	return tempStart;
}

void quest9()
{
	int i;
	struct List *start1, *start2;
	start1 = NULL;
	start2 = NULL;

	/*start1 = insertValue(start1, 1);
	start1 = insertValue(start1, 2);
	start1 = insertValue(start1, 3);
	start1 = insertValue(start1, 4);
	start1 = insertValue(start1, 5);*/
	printf("Enter 5 sorted elements in 1st list: ");
	for (i = 0; i < 5; i++)
		start1 = insertNode(start1);
	
	printf("Enter 5 elements in 2nd list: ");
	for (i = 0; i < 5; i++)
		start2 = insertNode(start2);

	display(sortedMerge(start1, start2));
	
}

//create a new list from given list which contains every alternate element from the given list
struct List *alternateList(struct List* start)
{
	int i;
	struct List *p, *tempStart;
	tempStart = NULL;
	for (i = 0, p = start; p != NULL; p = p->next, i++)
		if (i % 2 == 0)
			tempStart = insertValue(tempStart, p->a);
	return tempStart;	
}

void quest11()
{
	int i;
	struct List *start;
	start = NULL;
	printf("Enter 10 elements: \n");
	for (i = 0; i < 10; i++)
		start = insertNode(start);

	display(alternateList(start));
}

//concatenate two doubly linked list
struct List *insertDoublyNode(struct DoublyList* start)
{
	struct DoublyList *p, *q;
	if (!start)
	{
		start = (struct List*)malloc(sizeof(struct List));     //memory allocation
		scanf_s("%d", &start->a);
		start->next = NULL;
		start->previous = NULL;
	}
	else
	{
		for (p = start; p->next != NULL; p = p->next);
		q = (struct List*)malloc(sizeof(struct List));
		scanf_s("%d", &q->a);
		p->next = q;
		q->previous = p;
		q->next = NULL;
	}
	return start;
}

void displayDoublyList(struct DoublyList *start)
{
	struct DoublyList *p;
	for (p = start; p != NULL; p = p->next)
		printf("%d ", p->a);
}

void displayDoublyListReversed(struct DoublyList *start)
{
	struct DoublyList *p;	
	if (start)
	{
		for (p = start; p->next != NULL; p = p->next);
		for (; p != NULL; p = p->previous)
			printf("%d ", p->a);
	}
}

insertDoublyValue(struct DoublyList *start, int value)
{
	struct DoublyList *p, *q;
	if (!start)
	{
		start = (struct List*)malloc(sizeof(struct List));     //memory allocation
		start->a = value;
		start->next = NULL;
		start->previous = NULL;
	}
	else
	{
		for (p = start; p->next != NULL; p = p->next);
		q = (struct List*)malloc(sizeof(struct List));
		q->a = value;
		p->next = q;
		q->previous = p;
		q->next = NULL;
	}
	return start;
}

struct DoublyList *concat(struct DoublyList *start1, struct DoublyList *start2)
{
	struct DoublyList *tempStart, *p;
	tempStart = NULL;
	for (p = start1; p != NULL; p = p->next)
		tempStart = insertDoublyValue(tempStart, p->a);
	for (p = start2; p != NULL; p = p->next)
		tempStart = insertDoublyValue(tempStart, p->a);

	return tempStart;
}

void quest12()
{
	int i;
	struct DoublyList *start1, *start2;
	start1 = NULL;
	start2 = NULL;
	
	printf("Enter 5 elements in 1st list: ");
	for (i = 0; i < 5; i++)
		start1 = insertDoublyNode(start1);

	printf("Enter 5 elements in 2nd list: ");
	for (i = 0; i < 5; i++)
		start2 = insertDoublyNode(start2);

	displayDoublyListReversed(concat(start1,start2));
}

//delete first node of doubly linked list and add it to the end
struct DoublyList* addFirstToLast(struct DoublyList* start)
{
	struct DoublyList *temp, *p;
	temp = start;
	start = start->next;
	temp->next = NULL;
	start->previous = NULL;
	for (p = start; p->next != NULL; p = p->next);
	p->next = temp;
	temp->previous = p;
	return start;
}

void quest13()
{
	struct DoublyList *start;
	start = NULL;
	start = insertDoublyNode(start);
	start = insertDoublyNode(start);
	start = insertDoublyNode(start);
	start = insertDoublyNode(start);
	start = insertDoublyNode(start);

	start = addFirstToLast(start);
	displayDoublyList(start);
}

//delete first occurrence of a character in a linked list
struct List *insertCharValue(struct List* start, char c)
{
	struct List *p, *q;
	if (!start)
	{
		start = (struct List*)malloc(sizeof(struct List));     //memory allocation
		start->c = c;
		start->next = NULL;
	}
	else
	{
		for (p = start; p->next != NULL; p = p->next);
		q = (struct List*)malloc(sizeof(struct List));
		q->c = c;
		p->next = q;
		q->next = NULL;
	}
	return start;
}

void displayChar(struct List* start)
{
	struct List *p;
	for (p = start; p != NULL; p = p->next)
		printf("%c ", p->c);
}

struct List* deleteFirstOccur(struct List *start, char c)
{
	struct List *p;
	if (start)

	{
		if (start->c == c)
			start = start->next;
		else
		{
			for (p = start; p->next != NULL; p = p->next)
				if (p->next->c == c)
				{
					p->next = p->next->next;
					break;
				}
		}
	}
	return start;
}

void quest14a()
{
	struct List *start;
	start = NULL;
	start = insertCharValue(start, 'n');
	start = insertCharValue(start, 'a');
	start = insertCharValue(start, 'n');
	start = insertCharValue(start, 'd');
	start = insertCharValue(start, 'a');
	start = insertCharValue(start, 'n');

	start = deleteFirstOccur(start, 'd');

	displayChar(start);

}

//delete last occurrence of a character in a linked list
struct List* deleteLastOccur(struct List *start, char c)
{
	int i;
	struct List *p;
	for (i = 0, p = start; p != NULL; p = p->next)
		if (p->c == c)
			i++;
	
	if (start->c == c && i == 1)
		start = start->next;
	else
	{
		if (start->c == c)
			i--;
		for (p = start; p->next != NULL; p = p->next)
		{
			if (p->next->c == c)
			{
				if (i == 1)
				{
					p->next = p->next->next;
					break;
				}
				else
					i--;
			}
		}
	}
	return start;
}

void quest14b()
{
	struct List *start;
	start = NULL;
	start = insertCharValue(start, 'n');
	start = insertCharValue(start, 'a');
	start = insertCharValue(start, 'n');
	start = insertCharValue(start, 'd');
	start = insertCharValue(start, 'a');
	start = insertCharValue(start, 'n');

	start = deleteLastOccur(start, 'a');

	displayChar(start);

}

//delete all occurrences of a character in a linked list
struct List *deleteAllOccur(struct List *start, char c)
{
	struct List *p;
	if (start)
	{
		for (; start->c == c;)
			start = start->next;
		if (start)
		{
			for (p = start; p->next != NULL; )
			{
				if (p->next->c == c)
					p->next = p->next->next;
				else
					p = p->next;
			}
		}
	}
	return start;
}

void quest14c()
{
	struct List *start;
	start = NULL;
	start = insertCharValue(start, 'n');
	start = insertCharValue(start, 'a');
	start = insertCharValue(start, 'n');
	start = insertCharValue(start, 'd');
	start = insertCharValue(start, 'a');
	start = insertCharValue(start, 'n');

	start = deleteAllOccur (start, 'n');

	displayChar(start);

}

