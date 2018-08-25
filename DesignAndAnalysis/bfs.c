#include<stdio.h>
#include<stdlib.h>
int f = -1, r = -1,n = 0;
int queue[100],adj[100][100];
void enqueue(int item){
	if(r>n){
		printf("Queue limit exceeded");
		f = -1;
		r = -1;
	}else{
		if(f==-1){
			f = 0;
			r = 0;
			queue[r] = item;

		}else{
			queue[++r] = item;
		}
	}
}
int dequeue(){
	if(f==n||f>r){
		//printf("No items left to be dequeued");
		return -1;

	}else{
		int temp =  queue[f];
		f = f + 1;
		return temp;	


	}

}

int main(){
	int e, i, j ,k,s,u;
	int col[100],d[100],pi[100];
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the number of edges\n");
	scanf("%d",&e);
	for(i=1;i<=n;i++){ for(j=1;j<=n;j++){ adj[i][j] = 0;}}
	printf("Enter the vertex pair\n");	
	for(i=1;i<=e;i++){
		scanf("%d%d",&j,&k);
		adj[j][k] = 1;
		adj[k][j] = 1;

	}
	for(i=1;i<=n;i++){
		col[i] = 1;
		d[i] = 99999;
		pi[i] = 0;
	

	}
	printf("Enter the start vertex\n");
	scanf("%d",&s);
	col[s] = 2;
	d[s] = 0;
	enqueue(s);
	k = 0;
	printf("The order of traversal:   ");
	while(k<=n){
		u = dequeue();
		if(u==-1){
			break;
		}
		printf("%d ",u);
		for(i=1;i<=n;i++){
			if(col[i]==1&&adj[u][i]==1){
				col[i] = 2;
				d[i] = d[u] + 6;
				pi[i] = u;
				enqueue(i);
			}

		}
		col[u] = 3;
		k = k + 1;

	}
    for(int i=1;i<=n;i++){
        printf("%d ",d[i]);
    }
	printf("\n");
}
