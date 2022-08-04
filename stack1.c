#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int size;
    int top;
    int *arr;
} stack;

void construct(stack *st, int n)
{
    st->size = n;
    st->top = -1;
    st->arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        st->arr[i] = INT_MIN;
    }
}

void push(stack *st)
{
    if (st->top < st->size - 1)
    {
        printf("Enter element to be pushed:\n");
        st->top++;
        fflush(stdin);
        scanf("%d", &st->arr[st->top]);
    }
    else
    {
        printf("\nStack Overflow!!!\n");
    }
}

void pop(stack *st)
{
    if (st->top < 0)
    {
        printf("\nStack Underflow!!!\n");
    }
    else
    {
        int a = st->arr[st->top];
        st->arr[st->top--] = INT_MIN;
        printf("%d is popped out.\n", a);
    }
}

void peek(stack st)
{
    if (st.top > -1)
    {
        printf("\nTopmost element is %d\n", st.arr[st.top]);
    }
    else
    {
        printf("\nStack Underflow!!!\n");
    }
}

void seeTop(stack st)
{
    printf("\nTop is at index %d\n", st.top);
}

void printStack(stack st)
{
    if(st.top<0)
        printf("\nStack Underflow!!!\n");
    else{
        printf("\nElements in Stack are\n");
        for (int i = st.top; i >= 0; i--)
        {
            printf("%d\n", st.arr[i]);
        }
    }
    
}

int main()
{
    stack lab1;
    printf("Enter the size of stack:\n");
    int n;
    scanf("%d", &n);
    construct(&lab1, n);
    int i = 0;
    while (i == 0)
    {
        printf("Enter your Choice\n");
        printf("(Press 1 to Push\nPress 2 to Pop\nPress 3 to peek\nPress 4 to see elements in Stack):\n");
        int a;
        fflush(stdin);
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            push(&lab1);
            break;
        case 2:
            pop(&lab1);
            break;
        case 3:
            peek(lab1);
            break;
        case 4:
            printStack(lab1);
            break;
        default:
            printf("\nInvalid Choice\n");
        }

        printf("\nPress 0 to continue:\n");
        fflush(stdin);
        scanf("%d", &i);
    }
}