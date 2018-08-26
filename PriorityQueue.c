//Priority Queue using Array
#include<stdio.h>
#define MAX 5

typedef struct pQueue
{
	int value;
	int priority;
}pQueue;

int front = -1;
int rear = -1;
pQueue queue[MAX];

void enque(int v, int p)
{
	if(front == -1){
		front = 0;
		rear = 0;
		queue[rear].value = v;
		queue[rear].priority = p;
	}else if(rear == MAX-1){
		printf("No space\n");
		return;
	}else{
		rear++;
		queue[rear].priority = p;
		queue[rear].value = v;
		int flag = 1;
		while(flag == 1){
			int flag2 = 0;
			int i = front;
			while(i < rear){
				if(queue[i].priority > queue[i+1].priority ){
					flag2 = 1;
					int tempV = queue[i].value;
					int tempP = queue[i].priority;
					queue[i].value = queue[i+1].value;
					queue[i].priority = queue[i+1].priority;
					queue[i+1].value = tempV;
					queue[i+1].priority = tempP;
				}
				i++;
			}
			if(flag2 != 1){
				flag = 0;
			}
		}
	}
}
void deque(){
	if(front == -1 && rear == -1){
		printf("No Queue\n");
		return;
	}else if(front == rear){
		front = -1;
		rear = -1;		
	}else{
		front++;
	}
}
void display(){
	int i;
	for(i = front; i <= rear; i++){
		printf("%d ", queue[i].value);
	}
}
int main()
{
	enque(10,1);
	enque(14,2);
	enque(20,3);
	display();
	deque();
	display();
	
}
