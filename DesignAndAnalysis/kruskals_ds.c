#include<stdio.h>
#include<stdlib.h>
struct set{
	int rep;
	int v;
}s_arr[100];
struct krus{
	int i;
	int j;
	int w;
};
void merge(struct krus *a,int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	struct krus L[n1+2],R[n2+2];
	for(int i=1;i<=n1;i++){
		L[i] = a[p+i-1];
	}
	for(int i=1;i<=n2;i++){
		R[i] = a[q+i];
	}
	L[n1+1].w = 9999;
	R[n2+1].w = 9999;
	int i=1,j = 1;
	for(int k=p;k<=r;k++){
		if(L[i].w<=R[j].w){
			a[k] = L[i];
			i = i + 1;
		}
		else{
			a[k] = R[j];
			j = j + 1;

		}
	}
}

int find_set(int v,int n){
    if(v!=s_arr[v].rep){
        s_arr[v].rep = find_set(s_arr[v].rep, n);
    }
    return s_arr[v].rep;
}
void un_ion(int v1, int v2, int n){
    int c1 = find_set(v1, n);
    int c2 = find_set(v2, n);
    s_arr[c2].rep = s_arr[c1].v;
}
struct krus arr[100];
void merge_sort(struct krus *a, int p, int r){
	if(p<r){	
	int q = (p + r)/2;
	merge_sort(a,p,q);
	merge_sort(a,q+1,r);
	merge(a,p,q,r);
	}
}
int main(){
	int pr[100];
	int n,i,j,n1,prc,ch,sum;
	printf("Enter the number of edges:  ");
	scanf("%d",&n);
	printf("Enter the number of vertices\n");
	scanf("%d",&n1);
    printf("Enter the vertex pair and the weight\n");
	for(i=1;i<=n;i++){
			
			scanf("%d%d%d",&arr[i].i,&arr[i].j,&arr[i].w);
	}
	
	merge_sort(arr,1,n);
	
	for(i=1;i<=n1;i++){
		s_arr[i].v = i;
		s_arr[i].rep = i;
	}
	sum = 0;
	for(i=1;i<=n-1;i++){
		if(find_set(arr[i].i,n1)!=find_set(arr[i].j,n1)){
			printf("%d to %d weight = %d\n",arr[i].i,arr[i].j,arr[i].w);
			sum = sum  + arr[i].w;
			un_ion(arr[i].i,arr[i].j,n1);	
		}


	}
	printf("The total weight = %d" , sum);
	
}
