#include<stdio.h>
#include<stdlib.h>
int count = 0;
int place(int* x, int k, int i){
	for(int j = 1;j<=k-1;j++){
		if((x[j]==i)||abs(x[j]-i)==abs(j-k)){
			return 0;

		}
	}
	return 1;

}
void n_queen(int* x ,int k, int n){
	for(int i = 1;i<=n;i++){
		if(place(x,k,i)){
			x[k] = i;
		
			if(k==n){
				printf("Soln: ");
				for(int i = 1;i<=n;i++){
					printf("%d ",x[i]);
												
				}
				printf("\n");
				count++;
			}else{
			n_queen(x,k+1,n);
			}

		}
	}
}
int main(){
	int x[101],n;
	printf("Enter the number of Queens\n");
	scanf("%d",&n);
	n_queen(x,1,n);
	printf("Total Solutions: %d",count);	
}
