#pragma once
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

//Binary search tree definition
struct node
{
	int a;
	struct node *left, *right;
};

//insert in BST
struct node *insertTreeNode(struct node *root, int data)
{
	struct node *p, *q;
	if (!root)
	{
		root = (struct node *)malloc(sizeof(struct node));
		root->a = data;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		q = (struct node *)malloc(sizeof(struct node));
		q->a = data;
		q->left = NULL;
		q->right = NULL;
		for (p = root; (p->a > data&&p->left != NULL) || (p->a < data&&p->right != NULL);)
		{
			if (p->a > data)
				p = p->left;
			else
				p = p->right;
		}
		if (p->a > data)
			p->left = q;
		else
			p->right = q;
	}
	return root;
}

void displayTree(struct node *root)
{
	if (root)
	{
		displayTree(root->left);
		printf("%d ", root->a);
		displayTree(root->right);
	}
}

int isFound(struct node *root, int a)
{
	if (root)
	{
		if (a < root->a)
			return isFound(root->left, a);
		else if (a > root->a)
			return isFound(root->right, a);
		else
			return 1;
	}
	return 0;
}