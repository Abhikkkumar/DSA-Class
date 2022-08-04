#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue{
    int size;
    int front;
    int rear;
    int* a;
};

void create(struct Queue*q,int size){
    q->size=size;
    q->front=q->rear=0;
    q->a=(int*)malloc(size*sizeof(int));
}

void enque(struct Queue*q,int data){
    if((q->rear+1)%q->size==q->front)
        printf("Queue is full.\n");
    else {
        q->rear=(q->rear+1)%q->size;
        q->a[q->rear]=data;
    }
}

int deque(struct Queue*q){
    int x=INT_MIN;
    if(q->rear==q->front)
        printf("Queue is empty.\n");
    else{
        q->front++;
        x=q->a[q->front];

    }
    return x;
}

void printQueue(struct Queue*q){
    printf("size: %d\n",q->size);
    int i=q->front+1;
    do{
        printf("%d ",q->a[i]);
        i=(i+1)%q->size;
    }while(i!=(q->rear+1)%q->size);
}

int main(){

    struct Queue W1;
    create(&W1,6);
    enque(&W1,1);
    enque(&W1,2);
    enque(&W1,3);

    printQueue(&W1);
    printf("\n%d\n",deque(&W1));
    printf("\n%d\n",deque(&W1));
    printf("\n%d\n",deque(&W1));
    
    return 0;

}