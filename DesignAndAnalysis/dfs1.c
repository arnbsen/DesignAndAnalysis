//
//  dfs1.c
//  DesignAndAnalysis
//
//  Created by Arnab Sen on 09/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int adj[100][100],colour[100],pi[100];
void DFS_VISIT(int u, int n){
    colour[u] = 2;
    printf("%d ",u);
    for (int v = 1; v<=n; v++) {
        if (colour[v]==1&&adj[u][v]) {
            pi[v] = u;
            DFS_VISIT(v, n);
        }
    }
    colour[u] = 3;
}
void DFS(int n){
    for (int i = 1; i<=n; i++) {
        colour[i] = 1;
        pi[i] = 99999;
    }
    for (int u = 1; u<=n; u++) {
        if (colour[u]==1) {
            DFS_VISIT(u,n);
        }
    }
}
int main(){
    int e,n;
    printf("Enter the number of edges\n");
    scanf("%d",&e);
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            adj[i][j] = 0;
        }
    }
    int v1,v2;
    printf("Enter vertex pair if edges exist\n");
    for (int i = 1; i<=e; i++) {
        scanf("%d%d",&v1,&v2);
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;
    }
    printf("The traversal order\n");
    DFS(n);
}
