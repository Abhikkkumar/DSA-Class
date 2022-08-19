#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    char name[30];
    struct Node *next;
};

// It takes node 'head' of a circular LinkedList and a number 'n'
// then starting from 'head' starts deleting every n-th node starting from
// 'head' and print the 'name' of deleted node
// It keeps doing it till only one node is left. It prints 'name' of left node
// and exits.
void fun(struct Node*head, int n){
    if(head->next==NULL)
        printf("%s\n",head->name);
    else{
        struct Node*t1=head,*t2=head->next;
        int c=2;
        while(t1 !=t2){
            if(c!=n){
                t2=t2->next;
                t1=t1->next;
                c++;
            }
            if(c==n){
                t1->next=t2->next;
                t2->next=NULL;
                printf("%s\n",t2->name);
                free(t2);
                t2=t1->next;
                c=1;
            }
        }
        printf("%s\n",t2->name);
    }
}

int main(){

    struct Node *a,*b,*c,*d,*e;
    a=(struct Node *)malloc(sizeof(struct Node));
    b=(struct Node *)malloc(sizeof(struct Node));
    c=(struct Node *)malloc(sizeof(struct Node));
    d=(struct Node *)malloc(sizeof(struct Node));
    e=(struct Node *)malloc(sizeof(struct Node));
    
    // strncpy(a->name,"A",5);
    // strncpy(b->name,"B",5);
    // strncpy(c->name,"C",5);
    // strncpy(d->name,"D",5);
    // strncpy(e->name,"E",5);

    printf("Enter names of differnt nodes serial wise:\n");
    gets(a->name);
    gets(b->name);
    gets(c->name);
    gets(d->name);
    gets(e->name);

    
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=a;

    fun(a,3);

    

    return 0;
}