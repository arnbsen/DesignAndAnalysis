//
//  pointerToFunctions.c
//  DesignAndAnalysis
//
//  Created by Arnab Sen on 25/08/18.
//  Copyright © 2018 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
void func1(int a, int b){
    printf("First:  %d----%d\n", a, b);
}
void func2(int a, int b){
    printf("Second:  %d----%d\n", a, b);
}
int *funcp1(int* a, int b){
    printf("F: Value of Int constant is: %d\n", b);
    return a;
}
int *funcp2(int* a, int b){
    printf("S: Value of Int constant is: %d\n", b);
    return a;
}
int main(){
    void (*func_ptr[2])(int, int);
    func_ptr[0] = &func1;
    func_ptr[1] = &func2;
    func_ptr[0](1,2);
    func_ptr[1](3,4);
    int* (*funcptr[2])(int*, int);
    funcptr[0] = &funcp1;
    funcptr[1] = &funcp2;
    int a[] = {1,2,3,4};
    int b[] = {5,6,7,8};
    int *a1 = funcptr[0](a, 1);
    int *b1 = funcptr[1](b, 2);
    
    
}
