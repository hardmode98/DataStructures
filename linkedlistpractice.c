#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
void print(struct node *n){
	while(n!=NULL){
		printf("%d\n", n->data);
		n = n->next;
	}
}
void pushInFront(struct node **head_ref, int mdata){
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = mdata;
	newNode->next = *head_ref;
	*head_ref = newNode;
}
void insertAfter(struct node *ptr, int mdata){
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = mdata;
	temp->next = ptr->next;
	ptr->next = temp;
}
void appendAtEnd(struct node **head_ref, int mData){
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = mData;
	newNode->next = NULL;
	struct node *last = *head_ref;
	while(last->next != NULL){
		last = last->next;
		if(last->next == NULL){
			last->next = newNode;
			return;
		}
	}
}
int main(){
	struct node *head = NULL,*tail = NULL,
				*currentPtr;
	int option = 1, mData;
	do{
		currentPtr = (struct node*) malloc(sizeof(struct node));
		if(head == NULL){
			head = currentPtr;
			printf("enter the data\n");
			scanf("%d", &mData);
		}else{
			tail->next = currentPtr;
			printf("Enter the data\n");
			scanf("%d", &mData);
		}
		tail = currentPtr;
		currentPtr->next = NULL;
		currentPtr->data = mData;
		printf("Press 1 to continue\n");
		scanf("%d", &option);
	}while(option == 1);
	print(head);
	pushInFront(&head, 48);
	insertAfter(head, 96);
	appendAtEnd(&head,7);
	print(head);
}
