#include <stdio.h>

#define size 20
int graph[size][size], visited[size], n, queue[size], front = -1, rear = -1;

/*0 1 0 1
1 0 1 1
0 1 0 1
1 1 1 0*/

void bfs (int i);

void main() {
	int i, j, source;
	printf("Enter the number of vertices: ");
	scanf(" %d", &n);
	
	printf("Enter matrix elements: ");
	
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) 
			scanf(" %d", &graph[i][j]);
	}
	
	for (i=0;i<n;i++) {
		visited[i] = 0;
	}
	
	printf("Enter source vertex: ");
	scanf(" %d", &source);
	
	front = 0, rear=0;
	queue[rear] = source;
	visited[source] = 1;
	bfs(source);
}

void bfs(int i) {
	if (front<=rear)
    	printf("%d ", i);

    for (int j = 0; j < n; j++) {
        if (graph[i][j] == 1 && visited[j] == 0) {
            queue[++rear] = j; 
            visited[j] = 1; 
        }
    }
    if (front <= rear) {
        bfs(queue[++front]);
    }
}