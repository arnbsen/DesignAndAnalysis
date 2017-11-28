#include<stdio.h>
#include<stdlib.h>
struct arr{
	float profit;
	float weight;
	float pw;
};


int main(){
	struct arr temp;
	int i,n,j;
	float x[100];
	struct arr a[100];
	float u;
	float totalp = 0.0;
	printf("Enter the number of input\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter the profit and weight for %d\n",i);
		scanf("%f%f",&a[i].profit,&a[i].weight);
		a[i].pw = a[i].profit/a[i].weight;
	}
	for(i=1;i<=n;i++){
		for(j=2;j<=n;j++){
			if(a[j-1].pw < a[j].pw){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}

	}
	/*for(i=1;i<=n;i++){
		printf("%f ",a[i].pw);
	}*/
	for(i=1;i<=n;i++){
		x[i] = 0.0;

	}
	printf("Enter m\n");
	scanf("%f",&u);
	for(i=1;i<=n;i++){
		if(a[i].weight>u){
			break;
		}
		x[i] = 1.0;
		u = u - a[i].weight;
	}
	if(i<=n){
		x[i] = u/a[i].weight;

	}
	for(i=1;i<=n;i++){
		printf("%g %g\n",x[i],a[i].profit);
		totalp = totalp + x[i]*a[i].profit;		
	}
	printf("\nTotal profit = %f\n", totalp);


}
