//Linked list Impelmentation of Stack
#include<stdio.h>
struct node
{
	int data;
	struct node* next;
};
struct node* top = NULL;
void push(){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	if(top == NULL){
		printf("first node\n");
		scanf("%d" , &newNode->data);
		top = newNode;
		top->next = NULL;
	}else{
		printf("second node\n");
		scanf("%d", &newNode->data);
		newNode->next = top;
		top = newNode;
	}
}
void pop(){
	printf("inside pop\n");
	if(top == NULL){
		printf("No stack");
		return;
	}
	top = top->next;
}
void display(){
	if(top == NULL){
		printf("No stack");
		return;
	}
	while(top != NULL){
		
		printf("The stack is: %d", top->data);
		top = top->next;
	}
}
int main(){
	push();
	push();
	pop();
	display();
	
}
