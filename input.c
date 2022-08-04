#include<stdio.h>

void copyArr(int arr[],int arr1[],int n){
    for(int i=0;i<n;i++){
        arr1[i]=arr[i];
    }
    
}

//to take input in an array
void input(int arr[],int size){
    printf("Enter %d elemnts in your array:\n",size);
    for(int i=0;i<size;i++){
    	scanf("%d",&arr[i]);
    	}
    
} 

//to display elements of array in reverse order
void revDisplay(int arr[],int size){
	for(int i=size-1;i>=0;i--)
        
		printf("%d ",arr[i]);
}

// to display elements of arra in normal order
void Display(int arr[],int size){
    printf("\n");
	for(int i=0;i<size;i++){
        if(arr[i]==-9999999)
            continue;
        printf("%d ",arr[i]);
    }
        
		
}


//to remove last element and display all other left


int main(){
    int a[10],b[10];


    input(a,10);
    //copyArr(a,b,10);
    //a[9]=-9999999;
    //revDisplay(a,10);
    Display(a,10);
    return 0;
}