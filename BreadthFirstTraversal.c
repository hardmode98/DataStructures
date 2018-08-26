//Breadth First Traversal in Directed Graphs;
#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n = 7;
int adj[MAX][MAX];
int state[MAX];

int queue[MAX];
int front = -1;
int rear = -1;

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
void enque(int vertex)
{
	if (rear == MAX-1){
		printf("Queue Full\n");
	}else{
		if(front == -1){
			front = 0;	
		}
		rear++;
		queue[rear] = vertex;
	}
}

int queueEmpty()
{
	if(front == -1 || front > rear){
		return 1;
	}else{
		return 0;
	}
}

int deque()
{
	int deleteItem;
	if(front == -1 || front > rear){
		printf("No Queue\n");
		return;
	}
	deleteItem = queue[front];
	front++;
	return deleteItem;
}
void breadthFirstTraversal()
{
	int v;
	for(v = 0; v<n; v++){
		state[v] = initial;
	}
	bfs();
}

void bfs()
{
	int i;
	int vertex = 0;
	enque(vertex);
	state[vertex] = waiting;
	while(!queueEmpty()){
		vertex = deque();
		printf("%d ", vertex);
		state[vertex] = visited;
		for(i = 0; i < n; i++){
			if(adj[vertex][i] == 1 && state[i] == initial){
				enque(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
}
int main()
{
	createGraph(n);
	breadthFirstTraversal();
}
