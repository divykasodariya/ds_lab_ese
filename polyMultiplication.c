#include<stdio.h>
#include<stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* link;
};
struct Node* createNode(int data , int exp){
    struct Node* newNode = (struct Node* ) malloc(sizeof(struct Node));
    newNode->coeff=data;
    newNode->link=NULL;
    newNode->exp=exp;
    return newNode;
}
struct Node* insert (struct Node * head ,int co , int exp){

    struct Node * p = head;
    if(p==NULL){
        head= createNode(co,exp);
        return head;
    }
    if(p->exp<exp){
        struct Node* temp = createNode(co,exp);
        temp->link=p;
        head=temp;
        return head;
    }
    while(p->link!=NULL&&p->link->exp > exp){
        p=p->link;
    }
    struct Node * l = p->link;
    p->link = createNode(co,exp);
    p->link->link=l;
    return head;
}

struct Node* createPoly(){
    struct Node * head= NULL;
    struct Node * p=head;
    int m=1;
    while(m){
        printf("do you want to add terms ? (1 for yes and 0 for no )");
        scanf("%d",&m);
        if(m==0) break;
        printf("enter coefficient and exponent ");
        int exp,co; 
        scanf("%d %d",&co,&exp);
        head=insert(head,co,exp);
    }
    return head;
}

struct Node * AddPoly (struct Node* poly1 , struct Node* poly2){
    struct Node* p =poly1;
    struct Node* q =poly2;

    struct Node* newp =NULL;

    for(p=poly1 ; p!=NULL ;p=p->link){

        int found=0;
        for(q=poly2 ;q!=NULL;q=q->link)
        {
            if(q->exp == p->exp){
                int co = q->coeff+p->coeff;
               newp= insert(newp,co,q->exp);
                found=1;
                break;
            }
        }
        // q=poly2;
        if(!found){
            newp=insert(newp,p->coeff,p->exp);
        }
    }
    p=poly2;
    q=poly1;
     for( p =poly2; p!=NULL ;p=p->link){

        int found=0;
        for( q=poly1 ;q!=NULL;q=q->link)
        {
            if(q->exp == p->exp){
               found=1;
                break;
            }
        }
        q=poly1;
        if(!found){
            newp= insert(newp,p->coeff,p->exp);
        }
    }
    return newp;
}
void display(struct Node* poly){

    struct Node* p = poly;

    if(p == NULL){
        printf("Empty polynomial\n");
        return;
    }

    while(p != NULL){                // FIXED: p != NULL
        printf("%dx^%d", p->coeff, p->exp);
        if(p->link != NULL) printf(" + ");
        p = p->link;                // FIXED: move pointer
    }
    printf("\n");
}

int main(){

    struct Node* poly1=createPoly();
    display(poly1);

    struct Node* poly2 = createPoly();
    printf("\n");
    display(poly2);
    printf("\n");
    struct Node* newp= AddPoly(poly1,poly2);
    display(newp);
}