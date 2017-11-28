#include<stdio.h>
#include<stdlib.h>
struct bfd{
	int i;
	int w;
};
struct bfd bfd[100];
int adj[100][100];
int main(){
	int pr[100];
	int n,i,j,n1,prc,ch,sum;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	for(i =1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				adj[i][j] = 99999;
				continue;
			}
			printf("Enter the edge weight for v%d v%d. If no egde exists press 0:  ",i,j);
			scanf("%d",&ch);
			if(ch==0){
				adj[i][j] = 99999;
			}
			else{
				adj[i][j] = ch;
			}
		}

	}
	printf("Enter the start vertex\n");
	scanf("%d",&ch);
	bfd[ch].w = 0;
	pr[ch] = -1;
	for(i=1;i<=n;i++){
		bfd[i].w = adj[ch][i];
		bfd[i].i = i;
		pr[i] = ch;
	}
	int flag = 1;
	for(j=2;j<=n;j++){
		flag = 1;
		for(int k=1;k<=n;k++){
			if(ch!=k){
				for(i=1;i<=n;i++){
					if(bfd[k].w>bfd[i].w + adj[i][k]){
					bfd[k].w = bfd[i].w + adj[i][k];
					pr[k] = i;
					flag = 0;			
					}
				}
			}	
		}
		if(flag) break;
	}
	for(i=1;i<=n;i++){
		if(bfd[i].w>90000){
			printf("%d is the parent vertex\n",i);
			continue;
		}
		
		
		printf("From %d to %d Minimum wieght = %d\n",pr[i], bfd[i].i,bfd[i].w); 
	}
}
