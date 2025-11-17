#include<stdio.h>
#include<stdlib.h>

struct Node  {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data){
    struct Node * newNode= (struct Node* ) malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

void createBin(struct Node * root){
    int m ;
    printf("current Node %d \n",root->data);
    printf("enter 1 to enter data on the left\n2 to enter data on the right\n0 for none\n");
    scanf("%d",&m);
    if(m==1){
        printf("enter data \n");
        scanf("%d",&m);
        root->left=createNode(m);
        createBin(root->left);
        printf("current Node %d \n",root->data);
        printf("1 to enter data on the right\n0 for none\n");
        scanf("%d",&m);
        if(m==1){
            printf("enter data \n");
            scanf("%d",&m);
            root->right=createNode(m);
            createBin(root->right);
        }    

    }
    else if (m==2){
        printf("enter data \n");
        scanf("%d",&m);
        root->right=createNode(m);
        createBin(root->right);
        printf("current Node %d \n",root->data);
        printf("1 to enter data on the left\n0 for none\n");
        scanf("%d",&m);
        if(m==1){
        printf("enter data \n");
        scanf("%d",&m);
        root->left=createNode(m);
        createBin(root->left);
        }
    }
    
    // return root;    
}
int isFull(int top){
    if(top==100){
        return 1;
    }
    return 0;
}
int isEmpty(int top){
    if(top==-1){
        return 1;
    }
    return 0;
}
void inorder(struct Node * root){
    struct Node* stack[100];
    int top =-1;
    
  
   if(isFull(top)==1){
        printf("stack overflow \n");
   }
   
   while(root!=NULL || ( top>=0 && top<101)){

   
    while(root!=NULL){
        stack[++top]=root;
        root=root->left;
    }
    struct Node* l = stack[top--];
    printf("%d ", l->data);
    root=l->right;
   
   }

}
int height(struct Node * root)
{
    if(root == NULL){
        return -1;
    }
    int l = height(root->left);
    int r = height(root->right);
    return l>r? l+1 : r+1;
}

void preorder( struct Node * root){
    struct Node * stack [100];
    int top=-1;
    stack[++top]=root;
    while((top>=0 && top<101)){

        root= stack[top--];
      if(root!=NULL) printf("%d ",root->data);

    if(root->right!=NULL) stack[++top]=root->right;
       
       if(root->left!=NULL) stack[++top]=root->left;
       
    }
}
void postorder(struct Node * root){

    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1=-1;
    int top2=-1;
   if(root!=NULL) stack1[++top1]=root;
    while(top1!=-1){
        struct Node * l = stack1[top1--];
        stack2[++top2]=l;

        if(l->left!=NULL) stack1[++top1]=l->left;
        if(l->right!=NULL) stack1[++top1]=l->right;
        
    }
    while(top2!=-1){
        printf("%d ",stack2[top2--]->data);
    }

}
int countTerminal(struct Node * root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right ==NULL){
        return 1;
    }
    int l = countTerminal(root->left);
    int r=  countTerminal(root->right);
    return l+r;

}
int countTotalNodes(struct Node* root){
    if(root==NULL){
        return 0;
    }
   int l = 1+countTotalNodes(root->left);
   int r =  countTotalNodes(root->right);
   return l+r;
}
int main()
{
    struct Node * root = createNode(10);
    createBin(root);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");

    postorder(root);
    printf("\nthe height of the tree is %d ",height(root));
    printf("\nthe terminal nodes are : %d ",countTerminal(root));
    printf("\nthe total nodes are : %d ",countTotalNodes(root));

}