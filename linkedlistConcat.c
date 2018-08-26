#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void print(struct node *n){
	while(n!=NULL){
		printf("%d	", n->data);
		n = n->next;
	}
}


struct node* create(struct node *ptr){
	struct node *head = NULL,*tail = NULL,
				*currentPtr;
	int option = 1, mData;
	head = ptr;
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
	return head;
}
void concat(struct node* head_1, struct node* head_2){
	struct node *temp;
	while(head_1->next != NULL){
		head_1 = head_1->next;
		temp = head_1;
	}
	temp->next = head_2;
}
int main(){
	struct node *head1 = NULL,
				*head2 = NULL;
	int option_con;
	head1 = create(head1);
	head2 = create(head2);
	printf("Enter 1 to concatinate 1st with 2nd || Enter 2 to concatinate 2nd with 1st\n");
	scanf("%d", &option_con);
	if(option_con == 1){
		concat(head1, head2);
		print(head1);
	}else if(option_con == 2){
		concat(head2 , head1);
		print(head2);
	}else{
		printf("Wrong choice");
	}
	
	
}
