//Depth First Search in Graphs
#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n = 7;
int adj[MAX][MAX];
int state[MAX];


int stack[MAX];
int top = -1;

void push(int v){
	if(top == -1){
		top = 0;
		stack[top] = v;
	}else if(top == MAX-1){
		printf("Stack Full\n");
		return;
	}else{
		top++;
		stack[top] = v;
	}
}

int pop(){
	if(top == -1){
		printf("No Stack\n");
		return;
	}
	int deleteItem = stack[top];
	top--;
	return deleteItem;
}

int stackEmpty()
{
	if(top == -1){
		return 1;
	}else{
		return 0;
	}
}
void createGraph(int n)
{
	int count,
		maxEdge = n*(n-1),
		origin,
		dest;
	for(count = 1; count <= maxEdge; count++){
		printf("Enter edge %d (-1, -1 to quit):", count);
		scanf("%d %d", &origin, &dest);
		if((origin == -1) && (dest == -1)){
			break;
		}
		if((origin >= n || dest >= n || origin < 0 || dest < 0)){
			printf("Invalid edge\n");
			return;
		}else{
			adj[origin][dest] = 1;
		}
	}
}
void depthFirstTraversal(){
	int v;
	for(v = 0; v < n; v++){
		state[v] = initial;
	}
	dfs();
}
void dfs(){
	int i;
	int vertex = 0;
	push(vertex);
	state[vertex] = waiting;
	while(!stackEmpty()){
		vertex = pop();
		printf("%d ", vertex);
		state[vertex] = visited;
		for(i = 0; i < n; i++){
			if(adj[vertex][i] == 1 && state[i] == initial){
				push(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
	
}

int main(){
	createGraph(n);
	depthFirstTraversal();
}




