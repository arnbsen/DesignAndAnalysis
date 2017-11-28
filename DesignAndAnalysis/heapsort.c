#include<stdio.h>
#include<stdlib.h>
void adjust(int* a, int i, int n){
	int j = 2*i;
	int item = a[i];
	while(j<=n){
		if((j<n)&&(a[j]<a[j+1])){
			j= j + 1;

		}
		if(item>=a[j]){
			break;
		}
		a[j/2] = a[j];
		j = 2*j;
	}
	a[j/2] = item;
}
void max_heapify(int* a, int i, int n){
    int l = 2*i,largest;
    int r = 2*i + 1;
    if ((l<=n)&&a[l]>a[i]){
        largest = l;
    }else{
        largest = i;
    }
    if((r<=n)&&(a[r]>a[largest])){
        largest = r;
    }
    if (largest!=i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, largest, n);
    }
}
void build_max_heap(int* a, int n){
	for(int i = n/2;i>=1;i--){
        max_heapify(a, i, n);
	}
}
void heap_sort(int* a, int n){
    build_max_heap(a, n);
    int sz = n;
	for(int i = n;i>=2;i--){
		int t = a[i];
		a[i] = a[1];
		a[1] = t;
        sz = sz - 1;
        max_heapify(a, 1, sz);
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
	heap_sort(arr,n);
	for(int i = 1; i<=n;i++){
		printf("%d ",arr[i]);
		
	}
	
}
