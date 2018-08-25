//
//  greatchase.c
//  DesignAndAnalysis
//
//  Created by Arnab Sen on 26/07/18.
//  Copyright © 2018 Arnab Sen. All rights reserved.
//

#include <stdio.h>
int main(){
    int t,s,z,n = 0;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        scanf("%d%d%d",&s, &z, &n);
        if(z > n){
            printf("-1");
        }else{
            int j = 0;
            while ((s + z*j) % n != 0) {
                j = j + 1;
            }
            printf("%d",(s + z*j)/n);
        }
    }
    
    
    
    
}
