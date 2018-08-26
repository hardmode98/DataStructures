#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};


void print(struct node *n){
	while(n!=NULL){
		printf("%d	", n->data);
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
        tail->data = NUM;
        tail->next = NULL;
        printf("Enter 1 to continue : ");
        scanf("%d", &option);

    }while(option == 1);
    return currentHead;
};


void insertByData(struct node* currentHead, int mData)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node* previous;
    newNode->data = mData;
    if(currentHead == NULL)return;
    if(currentHead->data < newNode->data)
    {
        while(currentHead->data < newNode->data)
        {
            previous = currentHead;
            currentHead = currentHead->next;
            if(currentHead->next == NULL)
            {
                currentHead->next = newNode;
                newNode->next = NULL;
                return;
            }
        }
        newNode->next = previous->next;
        previous->next = newNode;
    }else if(currentHead->data > newNode->data)
    {
        while(currentHead->data > newNode->data)
        {
            previous = currentHead;
            currentHead = currentHead->next;
            if(currentHead->next == NULL)
            {
                currentHead->next = newNode;
                newNode->next = NULL;
                return;
            }
        }
        newNode->next = previous->next;
        previous->next = newNode;
    }else
    {
        newNode->next = currentHead->next;
        currentHead->next = newNode;
    }

};


int main()
{
    struct node *head = NULL;
    head = createList(head);
    insertByData(head, 3);
    print(head);
}
