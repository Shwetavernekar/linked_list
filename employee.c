#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node* createnode(struct node *head);
void display(struct node *head);
void bubble_sort(struct node *head);


struct node
{
	char name[10];
	int age;	
	float salary;
	struct node *link;
};

struct node *head = NULL;

int main()
{

	int choice,i;
	
	while(1)
	{
	
		printf("\nEnter the value\n1-> to enter the employee details\n2->to display the results\n3->to sort\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: printf("\nEnter 10 employee details\n");
				int i = 3;				
				while(i > 0)
   				{
					head = createnode(head);
				   	i--;
   				}
   				break;

			case 2: display(head);
          			  break;

			case 3: bubble_sort(head);
				break;
		}
	}
}



void display(struct node* head)
{
	if(head==NULL)
	{
		printf("\nThe node is yet to be displayed \n");
	}

	else
	{
		while(head != NULL)
		{
			printf("The name of the employee is %s\n",head->name);	
			printf("The salary of the employee is %f\n",head->salary);
			printf("The age of the employee is %d\n",head->age);

			head = head->link;

		}
	} 
}



struct node* createnode(struct node* head)
{
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof (struct node));

	printf("Enter the employee name \n");
	scanf("%s",newnode->name);
	printf("Enter the salary of the employee \n");
	scanf("%f",&newnode->salary);
	printf("Enter the age of the employee\n");	
	scanf("%d",&newnode->age);

	if(newnode == NULL)	
	{
		printf("\n Enter the newnode \n");
		newnode->link = NULL;
	}

	else
	{
		newnode->link = head;

	}
	return newnode;
}



void bubble_sort(struct node *head)
{
    char t[25];
    struct node *temp = head;
    struct node *temp1 = temp->link;

	
		while(temp->link != NULL)
		{
	        if(strcmp(temp->name , temp1->name) > 0)
			{
	            strcpy(t,temp1->name);
        	    strcpy(temp1->name,temp->name);
        	    strcpy(temp->name,t);
        	}
     //   	printf("%s ", temp->name);
    	}
    printf("the sorted names is %s\n", temp->name);	
	
}
