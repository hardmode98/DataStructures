#include<stdio.h>
typedef struct node{
	int info;
	struct node *next;
}node;

int main(){
	struct node *start = NULL, 
				*tail = NULL;
	char option;
	do{
	struct node *ptr = (node*)malloc(sizeof(node));
	if(start == NULL){
		start = ptr;
		tail = ptr;
	}else{
		tail->next = ptr;
		printf("Enter a number: \n");
		scanf("%d", ptr->info);
		ptr->next = NULL;
		tail = ptr;
	}
	
	option = getchar();
}while(option == 'y');
	
}
