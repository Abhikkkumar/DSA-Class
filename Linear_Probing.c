#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<stdlib.h>

int size=1;

//to print an array
void printArr(int arr[],int n){
    
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int H_fctn(int key){
    int index=key%size;
    return index;
}


int H_Collision_fctn(int arr[],int key){
    int index=H_fctn(key);
    int i=0;
    while(arr[index]!=INT_MIN){
        i++;
        index=(H_fctn(key)+i)%size;
    }
    return index;
}

//function to  take key as input and insert it.
void H_Insert(int arr[]){
    printf("Enter the key which is to be inserted:\n");
    int key;
    fflush(stdin);
    scanf("%d",&key);
    int index=H_fctn(key);
    if(arr[index]!=INT_MIN){
        index=H_Collision_fctn(arr,key);
    }
    arr[index]=key;
}

int H_Search(int arr[],int key){
    
    int count=0;

    int index=H_fctn(key);
    while(count<size && arr[index]!=key ){
        index++;
        if(index>=size)
            index=index%size;
        if(arr[index]==INT_MIN)
            return -1;
        count++;
    }
    if(count >size)
        return -1;
    return index;
}

void H_Delete(int arr[]){
    printf("Enter the element which you want to delete:\n");
    int key;
    scanf("%d",&key);
    int index=H_Search(arr,key);
    if(index==-1)
        printf("No such element is present in the Hash Table.\n");
    else{
        arr[index]=INT_MAX;
    }
    
}



int main(){
    int n;
    printf("Enter number of keys to be entered:\n");
    scanf("%d",&n);


    size=n;

    int *HsTable=(int *)malloc(n*sizeof(int));
    if(HsTable==NULL){
        printf("not available.");
        return -10;
    }


    for(int lp=0;lp<n;lp++){
        HsTable[lp]=INT_MIN;
    }

    int exit=0,key,count=0;
    while(exit==0){
        int i;
        printf("Choose your operations\n(1 for Insertion\n2 for Deletion\n3 for Searching):\n");
        scanf("%d",&i);
        if(i==1 && count==n){
            printf("Your Hash Table is full.Delete some keys from your Hash Table.\n");
            
        }
        else{
            switch(i){
                case 1:
                    H_Insert(HsTable);
                    count++;
                    break;
                case 2:
                    H_Delete(HsTable);
                    count--;
                    break;
                case 3:
                    printf("Enter the key whose index has to be searched:\n");
                    scanf("%d",&key);
                    printf("Your key is stored at index number %d.\n",H_Search(HsTable,key));
                    break;
                default:
                    printf("Invalid Choice.\n");
            }
        }
        printf("Press 0 to continue operations\n");
        scanf("%d",&exit);
    }

    
    // int m;
    // printf("Press 2 to see Hash Table content:\n");
    // scanf("%d",&m);
    // if(m==2)
    //printArr(HsTable,n);

    return 0;
}