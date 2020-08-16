/******************************************************************************

                    Welcome to Bubble Sort technique in stack

*******************************************************************************/

#include <stdio.h>
#define SIZE 5
int stack[SIZE] ;
int top = 0;
int add()
{

       printf("\n Enter Data to be stored");
       scanf("%d",&stack[top]);
       top++;

}
_Bool isFull()
{
    if(top==SIZE)
        return (0==0);
    return (0!=0);
}
_Bool isEmpty()
{
    if(top==0)
        return (0==0);
    return (0!=0);
}
int pop(void)
{
    stack[top-1] = 0;
    top--;
}


int Size()
{
    return top;
}
int print()
{
    for (int i = 0; i < top; i++)
    {
        printf("\n Data is %d\n",stack[i]);
    }
}
int Sort()
{
    //TODO: Sorting
}
int main()
{
    int action,result,f,i;
    while(1){

    printf("\n Provide the action: \n 1) Push\n 2) Pop \n 3) Size \n 4) print Data \n g) Swap \n 6) Quit\n");
    scanf("%d",&action);
    int count;
    if (action == 6)
    break;
    switch(action)
    {
        case 1:

        if(!isFull()){
        add();
        }
        else
            printf("Stack is full");
        break;

        case 2:

        if(!isEmpty()){
        result = pop();
        }
        else
            printf("Empty Stack ");
        break;

        case 3:
        result = Size();
        printf("\n size is %d",result);
        break;

        case 4:
        result = print();
        printf("\n printing");
        break;

        case 5:
        printf("\n Index to Swap? ");
        int ind,ind1;
        scanf("%d %d",&ind,&ind1);
        //result = swap(ind,ind1);
        (result == 0)? printf("\n Swaping unsuccessful"):printf("\n Swaping Successful");
        break;

        default:
        printf("Action required is invalid\n");
        break;
    }
    }
    return 0;
}
