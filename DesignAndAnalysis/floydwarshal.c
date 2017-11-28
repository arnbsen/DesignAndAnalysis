#include<stdio.h>
int min(int a, int b){
	return a<b?a:b;
}
int minch(int a, int b){
	return a<b?0:1;
}
int adj[100][100];
int d[100][100];
int t[100][100];
int p[100][100];
int t1[100][100];
int p1[100][100];
void copy(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			p1[i][j] = p[i][j];
			t1[i][j] = t1[i][j];
		}

	}


}
int main(){
	int pr[100];
	int n,i,j,k,n1,prc,ch,sum;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	for(i =1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("Enter d[%d][%d]",i,j);
				scanf("%d",&d[i][j]);
		}

	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			
			if(i==j||d[i][j]==99999){
				t[i][j] = 0;
				p[i][j] = 0;
			}else{
				t[i][j]= 1;
				p[i][j] = i;
			}
		}

	}
	
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
					p[i][j] = p[k][j];

				}
                t[i][j] = t[i][j]|(t[i][k]&t[k][j]);
			}

		}
		
	}
	printf("The transitive closure matrix\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",t[i][j]);

		}
		printf("\n");
	}
	printf("The parent matrix\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",p[i][j]);

		}
		printf("\n");
	}
	printf("The distance matrix\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(d[i][j]!=99999){
			printf("%d ",d[i][j]);
			}
			else{
			printf("inf ");
			}
		}
		printf("\n");
	}
	
}
