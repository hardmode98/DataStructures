#include<stdio.h>
struct node
{
	int value;
	struct node* next;
};
void display(struct node *tempNode){
	if(tempNode == NULL){
		return;
	}
	while(tempNode != NULL){
		printf("The number is : %d \n", tempNode->value);
		tempNode = tempNode->next;
	}
}

int main(){
	struct node *head = NULL;
	struct node *tail = NULL;
	int option = 1;
	do
	{
		struct node *ptr = (struct node*) malloc(sizeof(struct node));
		if(tail == NULL){
			scanf("%d", &ptr->value);
			tail = ptr;
			tail->next = NULL;
		}else{
			ptr->next = head;
			scanf("%d", &ptr->value);
		}
		head = ptr;
		printf("Enter the option \n");
		scanf("%d", &option);
	}while(option == 1);
	display(head);
}
