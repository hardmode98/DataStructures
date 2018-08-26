#include<stdio.h>
struct node
{
	int value;
	struct node *next;
};

int main(){
	struct node *head = NULL;
	struct node *tail = NULL;
	int option = 1;
	int num;
	
	do
	{
		struct node *ptr = (struct node*) malloc(sizeof(struct node));
		if (head == NULL){
			scanf("%d", &ptr->value);
			head = ptr;
			
		}else{
			scanf("%d", ptr->value);
			tail->next = ptr;			
		}
		ptr->next = NULL;
		tail = ptr;
		printf("Enter option \n");
		scanf("%d", &option);
		
	}while(option == 1);
}
