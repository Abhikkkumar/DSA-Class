#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef struct
{
    int size;
    int top;
    char* arr;
} stack;

void create(stack *stk,int n){
    stk->size=n+1;
    stk->top=-1;
    stk->arr=(char*)malloc(stk->size*sizeof(char));
    
}

void push(stack*stk,char elm){
    if(stk->top<stk->size-2){
        stk->top++;
        stk->arr[stk->top]=elm;
    }
    else{
        printf("Stack Overflow!!!!\n");
    }
        
}

char pop(stack *stk){
    if(stk->top > -1){
        char c=stk->arr[stk->top];
        stk->arr[stk->top--]='!';
        return c;
    }
    else
        printf("Stack Underflow!!!!\n");
    
}

int isOperand(char c){
    if(c=='+' || c=='-'|| c=='*'|| c=='/'|| c=='('||c==')')
        return 0;
    return 1;
}

int priority(char c){
    if(c=='+'||c=='-')
        return 0;
    else if(c=='*'||c=='/')
        return 1;
    else if(c=='(')
        return 2;
    else if(c==')')
        return 3;
    
}

char* change(char infix[],int len){
    stack H,F;
    create(&H,len);
    create(&F,len);
    for(int i=0;i<len;i++){
        int a=isOperand(infix[i]);
        if(a==1){
            push(&F,infix[i]);
        }
        else if(a==0){
            int b=priority(infix[i]);
            int c=priority(H.arr[H.top]);
            if(H.top==-1)
                push(&H,infix[i]);
            else{
                
                if(b==3){
                    while(c!=2){
                        push(&F,pop(&H));
                        c=priority(H.arr[H.top]);
                    }
                    char m=pop(&H);//here value of char m is of no use
                }
                else if(b==2){
                    push(&H,infix[i]);
                }
                else if(b>c){
                    push(&H,infix[i]);
                }
                else if(b<=c && c!=2){
                    while(H.top>-1 && b<=c){
                        push(&F,pop(&H));
                        if(H.top>-1){
                            c=priority(H.arr[H.top]);
                        }
                    }
                    push(&H,infix[i]);
                }
                else if(b<=c && c==2){
                    push(&H,infix[i]);
                }
            }
        }
    }
    while(H.top>-1){
        push(&F,pop(&H));
    }
    F.arr[F.top+1]='\0';
    return F.arr;
}

//to print an array
void printString(char*str){
    int i=0;
    while(str[i]!='\0')
        printf("%c",str[i++]);
    printf("\n");
}

int main(){
    char infix[]="a+(b*c)/(d+e*f)";

    char *postfix=change(infix,strlen(infix));
    printString(postfix);
    // printf("%d",strlen(infix));
    return 0;
}
