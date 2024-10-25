#include<stdio.h>
#include<stdlib.h>
#define stack_size 5
int stack [stack_size];
int top=-1,ele;
void push(int);
int pop();
void stack_status();
void display();
int main()
{
    int ch;
    while(1)
    {
        printf("\n 1. push \n 2. pop \n 3.status \n 4. display \n 5. exit \n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter element to push: ");
            scanf("%d",&ele);
            push(ele);
            break;
            case 2:
            ele=pop();
            printf("%d is popped ", ele);
            case 3:
            stack_status();
            break;
            case 4:
            display();
            break;
            case 5 :
            exit (0);

        }
    } 
    return 0;
}
void push(int ele )
{
    if (top == stack_size-1)
    {
        printf("stack is full ");

    }
    else{
        stack [++top]=ele;
    
    }
}
int pop()
{
    if (top == -1)
    {
        printf("stack is empty");

    }
    else
    {
        return stack [top--];
    }
}
void stack_status()
{
    if (top == stack_size-1)
    {
        printf("stack is full");

    }
    else if (top == -1)
    {
        printf("stack is empty");

    }
    else{
        display();
    }
}
void display()
{
    int i;
    printf("stack elements are ");
    for(i=top; i>0; i--)
    {
        printf("%d \n", stack[i]);
    }
}
