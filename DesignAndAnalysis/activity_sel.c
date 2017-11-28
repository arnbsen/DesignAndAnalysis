#include<stdio.h>
#include<stdlib.h>
struct arr{
	float start;
	float finish;
	float dur;
	int index;
	int flag;
};


int main(){
	struct arr temp;
	int i,n,j,k;
	struct arr a[100];
	
	printf("Enter the number of input\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter the start and finish for %d\n",i);
		scanf("%f%f",&a[i].start,&a[i].finish);
		a[i].dur = a[i].finish - a[i].start;
		a[i].index = i;
	}
	for(i=1;i<=n;i++){
		for(j=2;j<=n;j++){
			if(a[j-1].finish > a[j].finish){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}

	}
	
	a[1].flag = 1;
	k = 1;
	for(i=2;i<=n;i++){
		if(a[i].start>=a[k].finish){
			a[i].flag = 1;
			k = i;

		}
		else{
			a[i].flag = 0;
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
	for(i=1;i<=n;i++){
		printf("%d ",a[i].flag);
			
	}
	
	printf("\nThe following activities are chosen\n");
	for(i=1;i<=n;i++){
		if(a[i].flag == 1){
		printf("A%d ",a[i].index);
		}
	}
	printf("\n");
	
}
