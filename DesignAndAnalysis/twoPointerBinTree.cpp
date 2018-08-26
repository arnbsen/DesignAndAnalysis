//
//  twoPointerBinTree.cpp
//  DesignAndAnalysis
//
//  Created by Arnab Sen on 26/08/18.
//  Copyright © 2018 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class Node{
public:
    int val;
    Node* leftChild;
    Node* rightChild;
    Node* parent;
    Node(int,Node*);
    void operator+(int); //For left Child
    void operator-(int); //For Right Child
    bool search(Node*,int);
    int commonAncestor(Node*,int, int);
    Node* returnAddress(Node*,int);
};
Node::Node(int val,Node* parent){
    this->val = val;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->parent = parent;
}
void Node::operator+(int a){
    this->leftChild = new Node(a, this);
}
void Node::operator-(int a){
    this->rightChild = new Node(a, this);
}
bool Node::search(Node* root,int p){
    if(root == nullptr){
        return false;
    }
    if(root->val == p){
        return true;
    }else{
        return search(root->leftChild, p) || search(root->rightChild, p);
    }
}
Node* Node::returnAddress(Node* root, int p){
    if(root->leftChild == nullptr && root->rightChild == nullptr && root->val != p){
        return nullptr;
    }
    if(root->val == p){
        return root;
    }
    if(root->val < p){
        return returnAddress(root->rightChild, p);
    }else{
        return returnAddress(root->leftChild, p);
    }
}

int Node::commonAncestor(Node* root, int p, int q){
    Node* pa = returnAddress(root, p);
    Node* x = pa->parent;
    if(search(x, q)){
        return x->val;
    }else{
        return commonAncestor(root,x->val, q);
    }
}
int main(){
    Node* root = new Node(10,nullptr);
    *root+5;
    *root-13;
    *root->leftChild+4;
    *root->leftChild-6;
    *root->rightChild+12;
    *root->rightChild-15;
    cout<<"The common ancestor is: "<<root->commonAncestor(root, 4, 15)<<endl;
    
    
    
}
