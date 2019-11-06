#include <stdio.h>
#include <stdlib.h>

void add(struct node **q, int num);
void display(struct node *q);
void merge(struct node **p, struct node **q);


struct node
{
	int data;
	struct node *link;
};



void main()
{
	struct node *first, *second;
	first = second = NULL;		
	
	add(&first, 7);
	add(&first, 5);
	add(&first, 3);
	add(&first, 1);
	add(&first, 20);
	printf("First linked list: ");
	display(first);

	add(&second, 6);
	add(&second, 25);
	add(&second, 32);
	add(&second, 11);	
	add(&second, 9);	
	printf("Second linked list: ");
	display(second);

	merge(&first, &second);


	printf("Merged linked list: ");
	display(first);
}




void add(struct node **q, int num)
{
	struct node *r, *temp = *q;
	r = malloc(sizeof(struct node));
	r->data = num;

	if(*q == NULL)
	{
		*q = r;
		(*q)->link = temp;
	}
	else
	{
		while(temp->link != NULL)
		{
			temp = temp->link;
		}
	}
	r->link = NULL;
	temp->link = r;
}



void display(struct node *q)
{
	while(q != NULL)
	{
		printf("%d ", q->data);
		q = q->link;
	}
}








void merge(struct node **p, struct node **q)
{
	struct node *temp = NULL;
	
	if(*p == NULL)
	{
		*p = *q;
	}
	else
	{
		if(*q == NULL)
		{
			temp = *p;
			while(temp->link != NULL)
			{
				temp = temp -> link;
			}
			temp->link = *q;
		}
	}
}			
	

