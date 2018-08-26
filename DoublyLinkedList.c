#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node* previous;
    struct node* next;
};

void printList(struct node* head)
{
	while(head != NULL){
		printf("a");
		head = head->next;
	}
}
struct node* Add(struct node* head, struct node* tail, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if(head == NULL)
    {
        new_node->data = new_data;
        head = new_node;
        tail = new_node;
        printf("HEad is null");
    }else
    {
    	new_node->data = new_data;
    	tail->next = new_node;
    	new_node->previous = tail;
    	tail = new_node;
    	tail->next = NULL;
	}
	return head; 
};
int main()
{
    struct node* head = NULL;
    struct node* tail = NULL;
    struct node* temp;
    
    head = Add(head, tail, 2);
    head = Add(head, tail, 2);
    head = Add(head, tail, 2);
    head = Add(head, tail, 1);
    printList(temp);
    
    
}
