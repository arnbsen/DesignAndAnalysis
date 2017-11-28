//
//  bellmanford1.c
//  DesignAndAnalysis
//
//  Created by Arnab Sen on 12/10/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct bfd{
    int u;
    int v;
    int w;
}bfd[100],bfd1[100];
struct wi{
    int i;
    int w;
}w[100],w1[100];
int adj[100][100];
void copy(int n){
    for (int i=1; i<=n; i++) {
        w[i] = w1[i];
    }
}
int main(){
    int n,e;
    printf("Enter no of edges\n");
    scanf("%d",&e);
    printf("Enter the number of Vertices\n");
    scanf("%d",&n);
    for (int i =1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            adj[i][j] = 99999;
        }
    }
    printf("Enter the start and end vertex with weight if edge exists\n");
    for (int i = 1; i<=e; i++) {
        scanf("%d%d%d",&bfd[i].u,&bfd[i].v,&bfd[i].w);
        adj[bfd[i].u][bfd[i].v] = bfd[i].w;
    }
    for (int i = 1; i<=n; i++) {
        w[i].i = i;
        w[i].w = 99999;
        w1[i].i = i;
        w1[i].w = 99999;
    }
    /*for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
     */
    printf("Enter the start vertex\n");
    int s;
    scanf("%d",&s);
    w[s].w = 0;
    w1[s].w = 0;
    for (int i =1 ; i<n; i++) {
        for (int j = 1; j<=e; j++) {
            if(w1[bfd[j].v].w > w[bfd[j].u].w + adj[bfd[j].u][bfd[j].v]&&adj[bfd[j].u][bfd[j].v]!=99999){
                
                w1[bfd[j].v].w = w[bfd[j].u].w + adj[bfd[j].u][bfd[j].v];
                
            }
        }
        copy(n);
        for (int i = 1; i<=n; i++) {
            if (w1[i].w > 99000) {
                printf("inf ");
            }else{
                printf("%d ",w1[i].w);
            }
        }
        
        printf("\n");
    }
    
    
    
}
