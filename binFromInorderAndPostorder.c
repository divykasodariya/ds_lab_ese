#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* right;
    struct Node* left;

};
struct Node * createNode(int data){
    struct Node * newNode= (struct Node* ) malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node * insert (struct Node * root , int data){
    
    if(root ==NULL){
        return createNode(data);
    }
    if(data>root->data){
        root->right=insert(root->right,data);
        
    }
    else {
        root->left =insert(root->left,data);
    }
    return root;
    
}
int pos (int inorder[],int start , int end, int target){
    for(int i =start;i<=end;i++){
        if(inorder[i]==target){
            return i ;
        }
    }
    return -1;
}
struct Node * buildTree (int inorder[], int preorder[], int start , int end , int * preindex){

    if(start>end)
    {
        return NULL;
    }
    int current = preorder[(*preindex)];
    (*preindex)++;
    struct Node * newnode= createNode(current);
    if(start==end){

        return newnode;
    }

    int idx = pos(inorder,start,end,current);
    newnode->left=buildTree(inorder,preorder,start,idx-1,preindex);
    newnode->right=buildTree(inorder,preorder,idx+1,end,preindex);
    return newnode;
}