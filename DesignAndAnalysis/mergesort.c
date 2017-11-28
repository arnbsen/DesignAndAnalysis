#include<stdio.h>
#include<stdio.h>
void merge(int *a,int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1+2],R[n2+2];
	for(int i=1;i<=n1;i++){
		L[i] = a[p+i-1];
	}
	for(int i=1;i<=n2;i++){
		R[i] = a[q+i];
	}
	L[n1+1] = 99999;
	R[n2+1] = 99999;
	int i=1,j = 1;
	for(int k=p;k<=r;k++){
		if(L[i]<=R[j]){
			a[k] = L[i];
			i = i + 1;
		}
		else{
			a[k] = R[j];
			j = j + 1;

		}
	}
}
void merge_sort(int* a, int p, int r){
	if(p<r){	
	int q = (p + r)/2;
	merge_sort(a,p,q);
	merge_sort(a,q+1,r);
	merge(a,p,q,r);
	}
}
int main(){
	int arr[20];
	int n;
	printf("Enter the number of array elements\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(int i = 1; i<=n;i++){
		printf("Enter the values for a[%d]: ",i);
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,1,n);
	for(int i = 1; i<=n;i++){
		printf("%d ",arr[i]);
		
	}
	
}
