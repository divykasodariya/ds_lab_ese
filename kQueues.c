#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

int nq=1;
int arr[SIZE];

int *front , *rear , * start , * end;


void init(){

     front = (int * ) (malloc(sizeof(int) * nq));
     rear = (int * ) (malloc(sizeof(int) * nq));
     start = (int * ) (malloc(sizeof(int) * nq));
     end= (int * ) (malloc(sizeof(int) * nq));

    int eachSize=SIZE/nq;
    for(int i =0;i<nq;i++){
        front[i]= i * eachSize -1 ;
        start[i]=front[i]+1;
        end[i]=start[i]+eachSize-1; 
        rear[i]=front[i]+1;
    }

}

int isFull(int qn){
    
    if(front[qn]==end[qn]){
        return 1;
    }
    return 0;

}
int isEmpty(int qn){
    if(front[qn]<rear[qn]){
        return 1;

    }
    return 0;
}


// 0 24 
// 25 49 
// 50 74 
// 75 100

void enqueue(int qn, int data){
    if(!isFull(qn)){
        front[qn]++;
        arr[front[qn]]=data;
    }
}
int dequeue(int qn){
    if(!isEmpty(qn)){
        int ele=  arr[rear[qn]];
        rear[qn]++;
        return ele;
    }
    printf("queue is empty cant pop \n");
    return -1;
}   
void displayq(int qn){
    for(int i = rear[qn];i<=front[qn];i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void displayAll(){
    for(int j=0;j<nq;j++){
        printf("%d th queue elemetns \n",j);
    for(int i = rear[j];i<=front[j];i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
}

int main(){
    printf("enter the number of queues you want \n");
    scanf("%d",&nq);
    init();
    while(1){
        int m ;
        printf("enter 1 to enqueue \n2 to dequeue \n3 to display a queue \n4 to display all the queues\n5 to stop\n");
        scanf("%d",&m);
        int qn;
        if(m==1){
            printf("enter the queue number\n");
            scanf("%d",&qn);
            printf("enter the data\n");
            int d;
            scanf("%d",&d);
            enqueue(qn,d);
        }
        else if(m==2){
            printf("enter the queue number\n");
            scanf("%d",&qn);
           int ele= dequeue(qn);
            printf("dequeued element : %d \n",ele);

        }
        else if(m==3){
            printf("enter the queue number\n");
            scanf("%d",&qn);
           displayq(nq);

        }
        else if(m==4){
            displayAll();
        }
        else{
            break;
        }
    
    }

}