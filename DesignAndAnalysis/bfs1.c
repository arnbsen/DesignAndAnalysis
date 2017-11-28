#include<stdio.h>
#include<stdio.h>
int n = 0;
struct ad{
	int al[100];
	int count;

}adj[100];
void insert(int u, int v){
	int flag = 1,i;
	for(i = 0;i<adj[u].count;i++){
		if(adj[u].al[i]==v){
			flag = 0;
			break;
		}

	}
	if(flag){
		adj[u].al[i] = v;
		adj[u].count++;
	}
	flag = 1;
	for(i = 0;i<adj[v].count;i++){
		if(adj[v].al[i]==v){
			flag = 0;
			break;
		}

	}
	if(flag){
		adj[v].al[i] = u;
		adj[v].count++;
	}

}
int main(){
	int e, i, j ,k,s,u;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the number of edges\n");
	scanf("%d",&e);
	for(i=1;i<=n;i++){
		adj[i].count = 1;
		for(j=1;j<=n;j++){
			adj[i].al[j] = -1;
		}
	}
	printf("Enter the vertex pair\n");
	for(i=1;i<=e;i++){
		scanf("%d%d",&j,&k);
		insert(j,k);

	}
	for(i=1;i<=n;i++){
		printf("\nCurrent edge = %d\n",i);
		for(j=1;j<=adj[i].count;j++){
			printf("%d ",adj[i].al[j]);
		}

	}
}
