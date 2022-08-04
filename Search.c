#include<stdio.h>

//to take input in an array
int * input(int arr[],int size){
    printf("Enter %d elemnts in your array:\n",size);
    for(int i=0;i<size;i++){
    	scanf("%d",&arr[i]);
    	}
    
} 

//to do linear searching
void SearchLinear(int arr[],int size,int k){
    int i,j=0;
    for(i=0;i<size;i++){
        j++;
        if(arr[i]==k){
            printf("Found at index %d\n",i);
            break;

        }
    }
    if(i==size){
        printf("Not Found.\n");
    }
    printf("Total number of comparisions done: %d",j);
}

//to do binary search
void SearchBinary(int arr[],int l,int h,int k){
    printf("SearchBinary(arr,%d,%d,%d)\n",l,h,k);
    if(h-l>=0){
        
        int m=l+(h-l)/2;
        if(arr[m]==k)
            printf("Found at index %d\n",m);
        else if(k<arr[m])
            SearchBinary(arr,l,m-1,k);
        else if(k>arr[m])
            SearchBinary(arr,m+1,h,k);
    }
    else{
        printf("Not Found.\n");
    }

}

int main(){
    int n;
    printf("enter size of array in which searching has to be done:\n");
    scanf("%d",&n);
    //fflush(stdin);
    int arr[n];
    input(arr,n);

    printf("Enter the number to be searched:\n");
    int k;
    scanf("%d",&k);

    char o;
    printf("Choose the Searchig Technique:\n");
    printf("(l or L for Linear Search,\nb or B for Binary Search)\n");
    fflush(stdin);
    scanf("%c",&o);

    switch(o){
        case 'l':
        case 'L':
            SearchLinear(arr,n,k);
            break;
        case 'b':
        case 'B':
            SearchBinary(arr,0,n-1,k);
            break;
        default:
            printf("Invalid Option Chosen.\n");
    }
    
    return 0;
}