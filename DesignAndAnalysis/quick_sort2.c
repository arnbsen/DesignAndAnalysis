//
//  quick_sort2.c
//  DesignAndAnalysis
//
//  Created by Arnab Sen on 11/10/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
int partition(int* a, int p, int r){
    int x = a[r];
    int i = p - 1;
    for (int j = p; j<=r-1; j++) {
        if (a[j]<=x) {
            i = i + 1;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;
    return i+1;
}
void quick_sort(int* a, int p,int r){
    if (p < r){
        int q = partition(a, p, r);
        quick_sort(a, p, q-1);
        quick_sort(a, q+1, r);
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
    quick_sort(arr,1,n);
    for(int i = 1; i<=n;i++){
        printf("%d ",arr[i]);
        
    }
    
}
