#include<stdio.h>
#include<stdlib.h>
int mgCmp=0;
int mgSwap=0,qkCmp=0,qkSwap=0;


//to copy elements of arr to arr1
void copyArr(int arr[],int arr1[],int n){
    for(int i=0;i<n;i++){
        arr1[i]=arr[i];
    }
    
}

//to take input in an array
void input(int arr[],int size){
    printf("\nEnter %d elemnts in your array:\n",size);
    for(int i=0;i<size;i++){
    	scanf("%d",&arr[i]);
    	}
    
} 
//to print an array
void printArr(int arr[],int n){
    
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//to do swapping of 2 integers
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    
}

//to do bubble sort
void bubbleSort(int arr[],int n){
    
    int i,j,temp,count=0,cmp=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                 swap(&arr[j],&arr[j+1]);
                 count++;
                 cmp++;
            }
        }
    }
    printf("  .......Bubble Sort.........\n");
    printf("Number of swaps: %d\nNumber of comparisions: %d\n",count,cmp);
	
}

//to do insertion sort
void insertionSort(int arr[],int n){
    int count=0,cmp=0;
    for(int i=1;i<n;i++){
        int j=i-1;
        int temp=arr[i];
        while(j>=0 && arr[j]>temp){
            swap(&arr[j],&arr[j+1]);
            cmp++;
            count++;
            j--;
        }
        swap(&arr[j+1],&temp);
        count++;
    }
    printf(".........Insertion Sort.........\n");
    printf("Number of swaps: %d\nNumber of comparisions: %d\n",count,cmp+1);
}

//to do Selection Sort
void selectionSort(int arr[],int n){
    int count=0,cmp=0;
    for(int i=0;i<n-1;i++){
        int mindx=i;
        for(int j=i+1;j<n;j++){
            if(arr[mindx]>arr[j]){
                mindx=j;
                cmp++;
            }
                
        }
        if(mindx !=i){
            swap(&arr[mindx],&arr[i]);
            count++;
        }
    }
    printf("  .........Selection Sort.........\n");
    printf("Number of swaps: %d\nNumber of comparisions: %d\n",count,cmp);
}

//to merge an array whose 2 parts are sorted
void mergeArr(int arr[],int l,int m,int h){
    
    
    int i,j,k;
    int n1=m-l+1,n2=h-m;
    int ar1[n1],ar2[n2];
    for(i=0;i<n1;i++)
        ar1[i]=arr[l+i];
    for(j=0;j<n2;j++)
        ar2[j]=arr[m+1+j];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(ar1[i]<=ar2[j]){
            arr[k++]=ar1[i++];
            mgCmp++;
        }
        else{
            arr[k++]=ar2[j++];
            mgCmp++;
        }
            
    }
    while(i<n1){
        arr[k++]=ar1[i++];
    }
    while(j<n2)
        arr[k++]=ar2[j++];
    
} 

void mergeSort(int arr[],int l,int h){
    //printf("mergeSort(arr,%d,%d)\n",l,h);
    if(h-l>0){
        
        int m=l+(h-l)/2;
        
        mergeSort(arr,l,m);
        
        mergeSort(arr,m+1,h);
        mergeArr(arr,l,m,h);
    }
    
}

//to do partition of Quick Sort
int partition(int A[],int l,int h){
    //printf("partition(A,%d,%d)\n",l,h);
    int pivot=A[l],i=l+1,j=h;
    while(i<=j){
        while(A[i]<=pivot){
            i++;
            qkCmp++;
        }
        
        while(A[j]>pivot){
            j--;
            qkCmp++;
        }
        
        if(i<j){
            swap(&A[i],&A[j]);
            qkSwap++;
        }
        
    }
    swap(&A[l],&A[j]);
    qkSwap++;
    // printArr(A,5);
    
    return j;
}

//to do Quick Sort
void quickSort(int A[],int l,int h){
    //printf("quickSort(A,%d,%d)\n",l,h);
    int j;
    if(l<h){
        j=partition(A,l,h);
        quickSort(A,l,j-1);
        quickSort(A,j+1,h);
    }
}


int main(){
    int n;
    printf("enter size of array to be sorted:\n");
    scanf("%d",&n);
    
    int *arr,*dupArr;
    arr=(int *)malloc(n*sizeof(int));
    dupArr=(int *)malloc(n*sizeof(int));

    if(arr==NULL){
        printf("Memory for Array not allocated:");
        return -1;
    }
    
    input(arr,n);

    copyArr(arr,dupArr,n);    

    char o;
    int l=1;
    while(l==1){
        printf("\n\n");
        printf("Choose the Sorting Technique\n");
        printf("(b or B for bubble Sort,\ni or I for Insertion Sort,\ns or S for Selection Sort,\nm or M for Merge Sort,\nq or Q for Quick Sort.)\n");
        fflush(stdin);
        scanf("%c",&o);
        switch(o){
            case 'b':
            case 'B':
                bubbleSort(arr,n);
                break;
            case 'i':
            case 'I':
                insertionSort(arr,n);
                break;
            case 's':
            case 'S':
                selectionSort(arr,n);
                break;
            case 'm':
            case 'M':
                printf("  .........Merge Sort.........\n");
                mergeSort(arr,0,n-1);
                printf("Number of Comparisions:%d\n",mgCmp);
                mgCmp=0;

                break;
            case 'q':
            case 'Q':
                printf("  .........Quick Sort.........\n");
                quickSort(arr,0,n-1);
                
                printf("Number of swaps: %d\nNumber of comparisions: %d\n",qkSwap,qkCmp);
                qkCmp=qkSwap=0;

                break;
            default:
                printf("Invalid Choice.\n");
            
        }
            
        printf("\nFinal Sorted Array:\n");
        printArr(arr,n);

        printf("\n\nPress 1 to continue comparision:\n");
        scanf("%d",&l);
        if(l==1){
            int a;
            printf("\nPress 2 to sort same Array \n(else press 3 to input new Array):\n");
            scanf("%d",&a);
            if(a==2){
                copyArr(dupArr,arr,n);
            }
            else if(a==3){
                free(arr);
                free(dupArr);
                printf("\nenter size of array to be sorted:\n");
                scanf("%d",&n);
                
                arr=(int *)malloc(n*sizeof(int));
                dupArr=(int *)malloc(n*sizeof(int));

                if(arr==NULL){
                    printf("Memory for Array not allocated:");
                    return -1;
                }
                input(arr,n);

                copyArr(arr,dupArr,n);    
            }
            else {
                printf("Invalid Option Chosen.\n");
                break;
            }
        }
    }
    
    return 0;

}