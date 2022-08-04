#include<stdio.h>
#include<limits.h>

int top=-1;
int size=0;

//to print an array
void printArr(int arr[],int n){
    
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

//to see current position of top
void psTop(){
    printf("Top is at index %d\n",top);
} 

//to push element in our stack
void push(int arr[],int e){
    if(top+1==size){
        printf("\nYour stack is full!!!\nPlease pop some elements out of stack.\n");
    }
    else{
        
        top++;
        arr[top]=e;
    }
}

//to pop element out of our stack
void pop(int arr[]){
    if(top!=-1){
        printf("\n%d has been popped out of your stack.\n",arr[top]);
        arr[top]=INT_MIN;
        top--;
    }
    else
        printf("Your stack is empty.\n");
} 

//to peek in our stack
void peek(int arr[]){
    if(top==-1)
        printf("Your stack is empty.\n");
    else{
        printf("Element at the top of stack is %d\n",arr[top]);
    }
    
}

int main(){
    int n;//to store size of stack;
    printf("Enter size of your stack\n");
    scanf("%d",&n);
    int arr[n];
    size=n;
    for(int l=0;l<n;l++){
        arr[l]=INT_MIN;
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
                push(arr,e);
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

    return 0;

}

