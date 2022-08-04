#include<stdio.h>
#include<limits.h>
int i=-1,size,j;
char m;

//to print an array
void printArr(int arr[],int n){
    
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

//to see current position of top
void psTop(){

    if(m=='a' || m=='A'){
            printf("Top of Stack A is at index %d\n",i);
        }
        else if(m=='b' || m=='B'){
            printf("Top of Stack B is at index %d\n",j);
        }
    
}

//to push element in our stack
void push(int arr[]){
    if(i+1==j){
        printf("\nYour stack is full!!!\nPlease pop some elements out of stack.\n");
    }
    else{
        
        if(m=='a' || m=='A'){
            printf("Enter element to be pushed in stack %c\n",65);
        }
        else if(m=='b' || m=='B'){
            printf("Enter element to be pushed in stack %c\n",66);
        }
        
        int e;//to store element to be pushed;
        scanf("%d",&e);
        if(m=='a' || m=='A'){
            i++;
            arr[i]=e;
        }
        else if(m=='b' || m=='B'){
            j--;
            arr[j]=e;
        }    
        
    }
}

//to pop element out of our stack
void pop(int arr[]){

    if(m=='a' || m=='A'){
        if(i!=-1){
            printf("\n%d has been popped out of your stack.\n",arr[i]);
            arr[i]=INT_MIN;
            i--;
        }
        else
            printf(" Stack A is empty.\n");
    }
    else if(m=='b' || m=='B'){
        if(j!=size){
            printf("\n%d has been popped out of your stack.\n",arr[j]);
            arr[j]=INT_MIN;
            j++;
        }
        else
            printf(" Stack B is empty.\n");
    }   
    
} 

//to peek in our stack
void peek(int arr[]){
    if(m=='a' || m=='A'){
        if(i==-1)
            printf("Your stack is empty.\n");
        else{
            printf("Element at the top of stack is %d\n",arr[i]);
        }
    }
    else if(m=='b' || m=='B'){
        if(j==size)
            printf("Your stack is empty.\n");
        else{
            printf("Element at the top of stack is %d\n",arr[j]);
        }
    }

}

int main(){
    int n;//to store size of stack;
    printf("Enter size of your array\n");
    scanf("%d",&n);
    int arr[n];
    size=n;
    j=n;
    for(int l=0;l<n;l++){
        arr[l]=INT_MIN;
    }


    int q=0;//to handle loop
    while(q==0){
        
        printf("Choose your stack to work on\n(a or A for Stack A\nb or B for Stack B)\n");
        printf("_._._._._._._._._._._\n");
        fflush(stdin);
        scanf("%c",&m);
        printf("Choose your operation\n(1 for push\n2 for pop\n3 for peek\n");
        printf("4 to know index of top)\n");
        printf("_._._._._._._._._._._\n");
        int k;//to store user's chose option
        scanf("%d",&k);
        switch(k){
            case 1:
                
                push(arr);
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
        printf("\nCurrent stack is \n");
        printArr(arr,n);

        printf("\nEnter 0 to continue\n");
        scanf("%d",&q);

    }

}
