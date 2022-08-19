#include<stdio.h>
#include<stdlib.h>

 struct node{
    int data;
    struct node *next,*rear;
}nd;

// It inserts 'elm2' after 'elm1' in a doubly circular LinkedList having one 
// node 'head' and returns 'head'. if 'elm1' is not present then 'head' is 
// returned without inserting 'elm2'
struct node* insert(struct node* head, int elm1, int elm2){
    int a=sizeof(struct node);
    if(head->data==elm1){
        struct node*one =(struct node *)malloc(a);
        one->data=elm2;
        one->next=head->next;
        one->rear=head;
        head->next=one;
        return head;
    }
    else{
        struct node*temp=head->next;
        while(temp!=head){
            if(temp->data==elm1){
                struct node*one=(struct node*)malloc(a);
                one->data=elm2;
                one->next=temp->next;
                one->rear=temp;
                temp->next=one;
                return head;
            }
            temp=temp->next;
        }
    }
    return head;
}

// It prints the node data of each nodes of the given doubly circular
// LinkedList
void print(struct node*head){
    printf("%d ",head->data);
    struct node*t=head->next;
    while(t!=head){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

int main(){
    struct node *a,*b,*c;
    a=(struct node*)malloc(sizeof(struct node));
    b=(struct node*)malloc(sizeof(struct node));
    c=(struct node*)malloc(sizeof(struct node));


    a->data=1;
    b->data=2;
    c->data=3;

    a->next=b;
    a->rear=c;

    b->next=c;
    b->rear=a;

    c->next=a;
    c->rear=b;

    print(a);

    a=insert(a,5,55);

    print(a);

    return 0;
}