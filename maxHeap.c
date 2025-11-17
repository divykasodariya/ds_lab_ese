#include<stdio.h>
#include<stdlib.h>


void heapify(int a[], int i , int n ){
    int largest = i;
    int l = 2*i +1;
    int r= 2*i +2;
    if(l<n&& a[l]>a[largest]){
        largest=l;
    }
    if(r<n && a[r]>a[largest]){
        largest=r;
    }

    if(largest!=i){
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,largest,n);
    }
}
void extractMax(int a[],int n){
    for(int i = n/2 -1 ;i>=0;i--){
        heapify(a,i,n);   
    }
    for(int i =n-1 ;i>=1;i--){
        int temp =a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,0,i);
    }
}
int main(){
    printf("entet the size of the array \n");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("enter n elements \n");
    for(int i =0;i<n;i++){
        scanf("%d",&a[i]);
    }
    extractMax(a,n);
    for(int i =0;i<n;i++){

        printf("%d ",a[i]);
    }

}