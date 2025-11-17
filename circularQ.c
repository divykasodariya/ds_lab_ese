    #include<stdio.h>
    #include<stdlib.h>
    int size = 5;
    int front =-1;
    int rear=-1;

    int isFull(){
        if((rear+1)%size ==  front){
            return 1;
        }
        return 0;
    }
    int isEmpty(){
        if(front == -1){
            return 1;
        }
        return 0;
    }
    int dequeue(int queue[]){
        if(!isEmpty()){
            int q = queue[front];
            if(front == rear){
                front =-1;
                rear=-1;
            }else{
                front  =(front+1)%size;
            }
            return q;
        }   
        else{
            printf("queue empty cant dequeue \n");
            return -1;
        }
    }
    void enqueue(int queue[], int data){
        if(isFull()){
            printf("queue full \n ");
        }
        else{
            if(front==-1) {
                front=0;
                rear=0;
            }
            else{
                rear=(rear+1)%size;
            }
            queue[rear]=data;
        }
        
    }

    int main(){
        printf("enter the size of the queue \n" );
        scanf("%d",&size);
        int queue[size];

    }