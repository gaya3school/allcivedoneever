#include<stdio.h>

int graph[20][20], visited[20], n;

/*0 1 0 1
1 0 1 1
0 1 0 1
1 1 1 0*/

void dfs(int i){ 
	int j;
	visited[i]=1;
	printf("%d -> ",i);

	for(j=0;j<n;j++) {
  		if(visited[j]==0 && graph[i][j]==1)
    	dfs(j);
  	}
} 
void main()
{
  int i,j,s;
  printf("enter number of vertices: ");
  scanf(" %d",&n);
  
  printf("enter elements of matrix: ");
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      scanf(" %d", &graph[i][j]);
    }
  }
  
  for(i=0;i<n;i++) {
    visited[i]=0;
  }
  
  printf("enter source vertex: ");
  scanf(" %d", &s);
  dfs(s);
}