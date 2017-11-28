#include<stdio.h>
#include<stdlib.h>
struct prim{
	int flag;
	int w;
	int parent;
};
int min(int a, int b){
	return a<b?a:b;
}
int minch(int a, int b){
	return a<b?0:1;
}
struct prim pr[100];
int adj[100][100];
int prn[100];
int main(){
	int n,i,j,k,ch,fl,mn;

	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	for(i =1;i<=n;i++){
		for(j=1;j<=i;j++){
			if(i==j){
				adj[i][j] = 99999;
				continue;
			}
			printf("Enter the edge weight for v%d v%d. If no egde exists press -1:  ",i,j);
			scanf("%d",&ch);
			if(ch==-1){
				adj[i][j] = 99999;
				adj[j][i] = adj[i][j];

			}else{
				adj[i][j] = ch;
				adj[j][i] = adj[i][j];
			}

		}

	}
	//for(i=1;i<=n;i++) {for(j=1;j<=n;j++){ printf("%d ",adj[i][j]);} printf("\n");}
	for(i=1;i<=n;i++){
		pr[i].flag = 0;
		pr[i].w = 99999;
		pr[i].parent = 0;

	}
	printf("Enter the start vertex : ");
	scanf("%d",&ch);
	pr[ch].flag = 1;
	pr[ch].w = 1;
	pr[ch].parent = -1;
	prn[1] = ch;
	k = 2;
	while(k<=n){
		for(i=1;i<=n;i++){
			
			//updating the values
			for(j=1;j<=n;j++){
				if(pr[j].flag==1){
				continue;
				}
				if(minch(pr[j].w,adj[ch][j])==1){
				pr[j].w = min(pr[j].w,adj[ch][j]);
				pr[j].parent = ch;
				}
			}
			//Finding the minimum weight
			mn = 99999;
			for(j=1;j<=n;j++){
				if(pr[j].flag==1){
					continue;
				}
				else{
					if(pr[j].w<mn){	
						mn = pr[j].w;
						ch = j;	
					}	
				}
				
			}
			pr[ch].flag = 1;
			prn[k++] = ch;
			//printf("%d",ch);		
			
				
		}
		
	}
	int sum = 0; 
	for(i=1;i<=n;i++){
		if(pr[i].parent==-1){
			printf("%d is parent vertex\n",i);
			continue;
		}
		sum = sum + pr[i].w;
		printf("%d to %d -- %d\n",i,pr[i].parent,pr[i].w); 
	}
	printf("The minimum weight = %d\n",sum);


}
