//Doubly Linked List
#include<stdio.h>
struct node
{
	int value;
	struct node* previous;
	struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;

void createNode(){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	if(head == NULL){
		printf("Enter Value:\n");
		scanf("%d", &newNode->value);
		head = newNode;
		head->previous = NULL;
	}else{
		printf("Enter Value:\n");
		scanf("%d", &newNode->value);
		newNode->previous = tail;
		tail->next = newNode;
	}
	tail = newNode;
	tail->next = NULL;
}
void display(){
	struct node* temp;
	temp = head;
	if(temp == NULL){
		printf("No List");
	}
	while(temp != NULL){
		printf("%d ", temp->value);
		temp = temp->next;
	}
	 
}
int main(){
	createNode();
	createNode();
	createNode();
	display();
}
