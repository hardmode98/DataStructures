//Queue using linked list
#include<stdio.h>
struct node
{
	int value;
	struct node* next;
};
struct node* start = NULL;
struct node* end = NULL;

void enque(){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	if(start == NULL){
		scanf("%d", &newNode->value);
		start = newNode;
	}else{
		scanf("%d", &newNode->value);
		end->next = newNode;
	}
	end = newNode;
	end->next = NULL;
}
void deque(){
	if(start == NULL){
		printf("no queue\n");
		return;
	}
	start = start->next;
}
void display(){
	if(start == NULL){
		printf("no queue\n");
		return;
	}
	struct node* temp = NULL;
	temp = start;
	while(temp != NULL){
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}
int main()
{
	enque();
	enque();
	enque();
	display();
	deque();
	display();
	deque();
	deque();
	display();
}
