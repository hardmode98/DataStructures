//Queue implementation using array
#include<stdio.h>
int queue[10];
int start = -1;
int end = -1;

void enqueue(int data){
	if(start == -1 && end == -1){
		start++;
		end++;
		queue[end] = data;
		return;
	}
	end++;
	queue[end] = data;
}
void dequeue(){
	if(start == -1){
		printf("No queue\n");
		return;
	}
	start++;
}
void display(){
	if(start == -1){
		printf("No queue\n");
		return;
	}
	int i;
	for(i = start; i <= end; i++){
		printf("%d\n", queue[i]);
	}
}
int main()
{
	enqueue(5);
	enqueue(6);
	enqueue(8);
	display();
	dequeue();
	display();
}
