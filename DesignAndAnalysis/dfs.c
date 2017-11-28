#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int adj[100][100];
int colour[100];
int time = 0,finishtime = 0;
int p[100];
int d[100];
int n = 0;
void dfs_visit(int u){
	colour[u] = 2;
	time = time + 1;
	d[u] = time;
	printf("%d ", u);
	for(int i=1;i<=n;i++){
		if(adj[u][i]&&colour[i]==1){
			p[i] = u;
			dfs_visit(i);
		}

	}
	colour[u] = 3;
	time = time + 1;
	finishtime = time;	
}
void dfs(){
	for(int i=1;i<=n;i++){
		colour[i] = 1;
		p[i] = -1;
	}
	time = 0;
	for(int u = 1;u<=n;u++){
		if(colour[u]==1){
			dfs_visit(u);
		}

	}
}
int main(){
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			adj[i][j] = 0;
		}
	}
	int e;
	printf("Enter the number of edges\n");
	scanf("%d",&e);
	printf("Enter vertex pair if exists\n");
	int v1,v2;	
	for(int i=1;i<=e;i++){
		scanf("%d%d",&v1,&v2);
		adj[v1][v2] = 1;
		adj[v2][v1] = 1;
	}
	printf("The traversal order\n");
	dfs();
	printf("\n");
}
