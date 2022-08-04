#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node {
    int data;
    struct Node*next;
};

struct Node *front=NULL, *rear=NULL;

void enque(int data){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    
    if(t==NULL){
        printf("Queue Full!!\n");
    }
    else{
        t->data=data;
        t->next=NULL;
        if(front==NULL){
            front=t;
            rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int deque(){
    int x=INT_MIN;
    if(front==NULL){
        printf("Queue Empty!!\n");

    }
    else{
        struct Node* t=front;
        front=front->next;
        x=t->data;
        t->next=NULL;
        free(t);
    }
    return x;
}

void printLL(struct Node *a){
    struct Node* t=a;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

int main(){
    
    for(int i=0;i<20;i++){
        enque(i+1);
    }
    printLL(front);


    for(int i=0;i<10;i++){
        deque();

    }
    printLL(front);

    return 0;
    

}



