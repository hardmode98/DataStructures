#include<stdio.h>
#include<stdlib.h>
struct node
{
    int mData;
    struct node *next;
};

void print(struct node *n)
{
	while(n!=NULL)
    {
		printf("%d	", n->mData);
		n = n->next;
	}
};

struct node* createList(struct node* currentHead)
{
    int option = 1;
    int NUM;
    struct node *tail = NULL;
    do
    {
        struct node *newNode = (struct node*) malloc(sizeof(struct node));
        if(currentHead == NULL)
        {
            currentHead = newNode;
            printf("Enter the first number\n");
            scanf("%d", &NUM);
        }else
        {
            tail->next = newNode;
            printf("Enter the number\n");
            scanf("%d", &NUM);
        }
        tail = newNode;
        tail->mData = NUM;
        tail->next = NULL;
        printf("Enter 1 to continue : ");
        scanf("%d", &option);

    }while(option == 1);
    return currentHead;
};

struct node* insertByData(struct node *head, int data)
{
	printf("Inside Insert Function\n");
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	
	struct node* previous;
	struct node* tempHead = head;
	newNode->mData = data;
	while(tempHead != NULL)
	{
		printf("Inside while loop \n");
		if(tempHead->mData >= newNode->mData)
		{
			printf("Inside if statement\n");
			newNode->next = previous->next;
			previous->next = newNode;
			return head;	
		}
		previous = tempHead;
		tempHead = tempHead->next;
	}
}
int main()
{
	struct node *head = NULL;
    head = createList(head);
    head = insertByData(head, 3);
    print(head);
}
