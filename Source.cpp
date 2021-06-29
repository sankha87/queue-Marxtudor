#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
	int info;
	struct Node *link;
}*front = NULL, *rear = NULL;

void insert(int num);
int del();
void display();

int main()
{
	int choice, num, d;
	while (1)
	{
		printf("\n1 Insert\n");
		printf("2 Delete\n");
		printf("3 Display\n");
		printf("4 Exit\n");
		printf("Enter your choice\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter an element to insert ");
			scanf("%d", &num);
			insert(num);
			break;
		case 2:
			d = del();
			printf("%d deleted from Queue", d);
			break;
		case 3:
			display();
			break;
		case 4:
			exit(1);

		default:
			printf("Wrong Input\n");

		}
	}
	_getch();
}

void insert(int num)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	if (temp == NULL)
	{
		printf("Overflow\n");
		return;
	}
	temp->info = num;
	temp->link = NULL;
	if (front == NULL)
	{
		front = temp;
	}
	else
	{
		rear->link = temp;
	}

	rear = temp;
}

int del()
{
	int num;
	struct Node *temp;
	if (front == NULL)
	{
		printf("Underflow\n");
		return INT_MIN;
	}
	temp = front;
	num = temp->info;
	front = front->link;
	free(temp);
	return num;
}

void display()
{
	struct Node *p;
	if (front == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	p = front;
	printf("\nQueue Elements:\n");
	while (p != NULL)
	{
		printf("%d ", p->info);
		p = p->link;
	}
}