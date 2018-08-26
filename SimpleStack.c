//Stack Using array
#include<stdio.h>
int stack[10];
int top = -1;
void push(int value){
	if(top > 10)
	{
		printf("Out of Memory\n");
		return;
	}
	top++;
	stack[top] = value;
}
void pop(){
	if(top == -1)
	{
		printf("No Element to pop\n");
		return;
	}
	top--;
}
void printStack(){
	int i;
	for(i = top; i>=0; i--){
		printf("%d\n", stack[i]);
	}
}
void peep(){
	printf("The top is: %d\n", stack[top]);
}
int main(){
	push(1);
	push(1);
	push(1);
	push(1);
	pop();
	pop();
	printStack();
	peep();
}
