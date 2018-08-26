//Circular Queue Array Implementation
#include<stdio.h>
int front = -1;
int rear = -1;
int MAX_SIZE = 10;
int queue[10];
void enque(int value)
{
	if((front == 0 && rear == MAX_SIZE - 1) || (rear == ((front - 1)% (MAX_SIZE - 1)))){
		printf("Queue is full\n");
		return;
	}else if(front == -1){
		front ++;
		rear ++;
		queue[rear] = value;
	}else if(rear == (MAX_SIZE - 1) && front != 0){
		rear = 0;
		queue[rear] = value;
	}else{
		rear++;
		queue[rear] = value;
	}	
}
void deque(){
	if(front == -1){
		printf("No Queue!\n");
		return;
	}else if(front == rear){
		front = -1;
		rear = -1;
	}else if(front == MAX_SIZE - 1){
		front = 0;
	}else{
		front++;
	}
}
void display(){
	if(front == -1){
		printf("No Queue\n");
		return;
	}
	if(rear >= front){
		int i;
		for(i = front; i<= rear; i++){
			printf("%d- ", queue[i]);
		}
	}else if(rear < front){
		int i;
		for(i = front; i <= MAX_SIZE - 1; i++){
			printf("%d-", queue[i]);
		}
		for(i = 0; i<= rear; i++){
			printf("%d-", queue[i]);
		}
	}
}

int main()
{	
	enque(5);
	enque(6);
	enque(7);
	display();
	deque();
	deque();
	display();
	
}

