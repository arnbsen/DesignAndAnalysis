#include<stdio.h>
#include<stdlib.h>
int x[101],adj[101][101],n = 0,count = 0;
void next_value(int k){
	int j= 0;
	do{	
		x[k] = (x[k]+1)%(n+1);
		if(x[k]==0) return;
		if(k==1) return;
		if(adj[x[k-1]][x[k]]!=0){
			for(j=1;j<=k-1;j++){
				if(x[k]==x[j]) break;
			}
			if(j==k){
				if((k<n)||((k==n)&&(adj[x[n]][x[1]]!=0)))return;
			}
		}
		


	}while(1);
}
void hamiltonian(int k){
 do{
	next_value(k);
	if(x[k]==0) {
		return;
	}
	if(k==n){
		for(int i=1; i<=n;i++){
			printf("%d ", x[i]);

		}
		printf("\n");
		count++;
	}else{
		hamiltonian(k+1);
	}
}while(1);
}
int main(){
	int e;
	printf("Enter the number of edges:   ");
	scanf("%d",&e);	
	printf("Enter the number of vertices:   ");
	scanf("%d",&n);	
	int r,c;
	for(int i=1;i<=n;i++) { x[i] = 0; for(int j=1;j<=n;j++){ adj[i][j] = 0;}}
	for(int i = 1;i<=e;i++){
		scanf("%d%d",&r,&c);
		adj[r][c] = 1;
		adj[c][r] = 1;
	}
	//for(int i=1;i<=n;i++) { for(int j=1;j<=n;j++){ printf("%d ",adj[i][j]);} printf("\n");}
	hamiltonian(1);
	printf("The total no of Solutions: %d\n",count);
}
