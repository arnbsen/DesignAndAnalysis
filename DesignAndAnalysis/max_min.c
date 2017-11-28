#include<stdio.h>
int n = 0;
int a[100];
int s[2];
void max_min(int i, int j, int *max, int *min){
	int a1[2];
	if(i==j){
		*max = *min = a[i];
	}else if(i==(j-1)){
		if(a[i]<a[j]){
			*max = a[j];
			*min = a[i];

		}else{
			*max = a[i];
			*min = a[j];

		}
	
	}else{
		int max1;
		int min1;
		int mid = (i+j)/2;
		max_min(i,mid,max,min);
		max_min(mid+1,j,&max1,&min1);
		if(*max<max1){
			*max = max1;
					
		}
		if(*min>min1){
			*min = min1;
			
		}




	}
	
}
int main(){
	
	int max,min;
	printf("Enter no. of elements\n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("Enter a[%d]",i);
		scanf("%d",&a[i]);
	}
	max_min(1, n, &max, &min);
	printf("The maximum element = %d, Minimum element =%d",max,min);

}
