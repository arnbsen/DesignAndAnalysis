#include<stdio.h>
#include<stdlib.h>
struct arr{
	int job;
	float profit;
	int deadline;
	int flag;
	int index;
};


int main(){
	struct arr temp;
	int i,n,j,k;
	float x[100];
	struct arr a[100];
	float u;
	float totalp = 0.0;
	int job_set[100];
	int slot[100];
	printf("Enter the number of input\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter the profit and deadline for %d\n",i);
		scanf("%f%d",&a[i].profit,&a[i].deadline);
		a[i].index = i;
		a[i].flag = 0;
	}
	int max = -99999;
	for(i=1;i<=n;i++){
		for(j=2;j<=n;j++){
			if(a[j-1].profit < a[j].profit){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}

	}
	for(i=1;i<=n;i++){
		if(max < a[i].deadline){ max = a[i].deadline;}
		 	
	}
	for(i=1;i<=max+1;i++){
		slot[i] = 0;
	}
	
	for(i=1;i<=n;i++){
		k = a[i].deadline;
		
		while(k>0){
			if(slot[k]==0){
				slot[k] = 1;
				job_set[k] = a[i].index;
				a[i].flag = 1;
				break;
			}
		k--;
		}

	}

	for(i=1;i<=n;i++){
		for(j=2;j<=n;j++){
			if(a[j-1].index > a[j].index){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}

	}
	printf("The selected jobs are\n");
	for(i=1;i<=n;i++){
		printf("%d ",a[i].flag);
	}		
	printf("\n");
	for(i=1;i<=n;i++){
		if(a[i].flag == 1){
		printf("T%d ",a[i].index);
		totalp = totalp + a[i].profit;
		}
	}
	printf("\nThe slots occupied are\n");
	for(i=1;i<=max;i++){
		printf("%d ",slot[i]);
	}
	printf("The the profit = %f\n",totalp);


}
