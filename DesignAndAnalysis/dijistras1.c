//
//  dijistras1.c
//  DesignAndAnalysis
//
//  Created by Arnab Sen on 25/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(){
    int adj[100][100],v[100],d[100],d1[100],s,u[100],v1,v2,w,n,e,flag[100];
    int i,j,k;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the number of edges\n");
    scanf("%d",&e);
    for (i=1; i<=n; i++) {
        d[i] = 99999;
        d1[i] = 99999;
        flag[i] = 1;
        for (j=1; j<=n; j++) {
            adj[i][j] = 99999;
        }
    }
    printf("Enter v1 and v2 and the edge weigth\n");
    for (i=1; i<=e; i++) {
        scanf("%d%d%d",&v1,&v2,&w);
        adj[v1][v2] = w;
        //adj[v2][v1] = w;
    }
    k = 1;
    printf("Enter the start vertex\n");
    scanf("%d",&s);
    d[s] = 0;
    d1[s] = 0;
    u[s] = -1;
    flag[s] = 1;
   /* for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
           printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    */
    int min;
    while(k<=n){
        min = 99999;
        v1 = 1;
        for (i=1; i<=n; i++) {
            if((d[i] < min)&&flag[i]==1){
                min = d[i];
                v1 = i;
            }
        }
        k = k + 1;
        flag[v1] = 0;
        for (j=1; j<=n; j++) {
            int val = d[v1] + adj[v1][j];
            if(val < d1[j]&&flag[j]==1){
                d1[j] = d[v1] + adj[v1][j];
                u[j] = v1;
            }
        }
        printf("\n");
        for (i=1; i<=n; i++) {
            d[i] = d1[i];
        }
    }
    printf("Distance: ");
    for (i=1; i<=n; i++) {
        printf("%d ",d[i]);
    }
    printf("\n");
    printf("Parent: ");
    for (i=1; i<=n; i++) {
        printf("%d ",u[i]);
    }
    printf("\n");
}
