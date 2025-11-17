#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node*  next;
};
struct Node * createNode (int data){
    struct Node * newnode = (struct Node * ) malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

struct Node * insert (struct Node * head, int data){
    if(head==NULL){
       return createNode(data);
    }
    struct Node * p =head;

    while(p->next){
        p=p->next;
    }

    p->next=createNode(data);
    return head;


}
struct Node * merge(struct Node * head1 , struct Node * head2)
{   
    struct Node* head3 = NULL;
    struct Node * p = head1;
    struct Node * q = head2;

    while(p && q){
        struct Node * t;

        if(p->data <= q->data){
            head3=insert(head3,p->data);
            p=p->next;
        }
        else {
           head3=insert(head3,q->data);
            q=q->next;
        }

    }
    while(p){
        head3=insert(head3,p->data);
        p=p->next;
    }
      while(q){
        head3= insert(head3,q->data);
        q=q->next;
    }
return head3;
}
int main(){

}