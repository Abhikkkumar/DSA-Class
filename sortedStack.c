#include<stdio.h>
#include<limits.h>

int top=-1;//index position of Original Stack
int dtop=-1;//index position of temporary Stack
int size;//size of array holding Stack

//to print an array
// void printArr(int arr[],int n){
    
//     for(int i=0;i<n;i++){
//         printf("%d ",arr[i]);
//     }
// }

//to push elements in Original Stack
void push(int arr[],int elem){
    top++;
    arr[top]=elem;
    
}

//to pop elements from Original Stack
int pop(int arr[]){
    int m=arr[top];
    arr[top--]=INT_MIN;
    return m;
}

//to push element in temporary stack
void push1(int temp[],int elem){
    if(dtop<size){
        dtop++;
        temp[dtop]=elem;
    }
}

//to pop element from temporary stack
int pop1(int temp[]){
    int m=temp[dtop];
    temp[dtop--]=INT_MIN;
    return m;
}

//to peek in our stack
void peek(int arr[]){
    if(top==-1)
        printf("Your stack is empty.\n");
    else{
        printf("Element at the top of stack is %d\n",arr[top]);
    }
    
}

//to see current position of top
void psTop(){
    printf("Top is at index %d\n",top);
} 

void stackSortInsert(int arr[],int elem,int temp[]){
    if(top<size-1){
        while(top>=0 && elem<arr[top]){
            int m=pop(arr);
            push1(temp,m);
        }
        push(arr,elem);
        while(dtop != -1){
            int m=pop1(temp);
            push(arr,m);
        }
    }
    else{
        printf("\n\nYour stack is full!!!\n\n");
    }
}

int main(){
    int n;//to store size of stack;
    printf("Enter size of your stack\n");
    scanf("%d",&n);
    int arr[n],temp[n];
    size=n;
    for(int l=0;l<n;l++){
        arr[l]=INT_MIN;
        temp[l]=INT_MIN;
    }

    int i=0;//to handle loop
    while(i==0){
        printf("Choose your operation\n(1 for push\n2 for pop\n3 for peek\n");
        printf("4 to know index of top)\n");
        printf("_._._._._._._._._._._\n");
        int m;//to store user's chosen option
        scanf("%d",&m);
        switch(m){
            case 1:
                printf("Enter element to be pushed in stack\n");
                int e;//to store element to be pushed;
                scanf("%d",&e);
                stackSortInsert(arr,e,temp);
                break;
            case 2:
                pop(arr);
                break;
            case 3:
                peek(arr);
                break;
            case 4:
                psTop();
                break;
            default:
                printf("Invalid option chosen.\n");
                
        }
        // printf("Current stack is \n");
        // printArr(arr,n);

        printf("\nEnter 0 to continue\n");
        scanf("%d",&i);

    }
    
}