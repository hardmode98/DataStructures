//Circular Queue Using Linked List
#include<stdio.h>

struct node{
	int value;
	struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enque(int value)
{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->value = value;
	if(front == NULL){
		front = newNode;
	}else{
		rear->next = newNode;
	}
	rear = newNode;
	rear->next = front;
	printf("Enque done\n");	
}
void deque()
{
	if(front == NULL){
		printf("No Queue\n");
		return;
	}else if(front == rear){
		front = NULL;
		rear = NULL;
	}else{
		front = front->next;
		rear->next = front;
	}
}
void display(){
	struct node* temp1 = front;
	if(temp1 == NULL){
		printf("No Queue\n");
		return;
	}
	while(temp1->next != front){
		printf("-%d-", temp1->value);
		temp1 = temp1->next;
	}
	printf("-%d-", temp1->value);
}
int main()
{
	
	enque(1);
	enque(2);
	enque(3);
	display();
	deque();
	display();
	
}
