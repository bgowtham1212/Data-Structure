/******************************************************************************

                    Welcome to Queue

*******************************************************************************/

#include <stdio.h>
#define SIZE 5
int Queue[SIZE] ;
int rear = 0;
int front = 0;
int add()
{

       printf("\n Enter Data to be stored in Queue");
       scanf("%d",&Queue[rear]);
       rear++;

}
_Bool isFull()
{
    if(rear==SIZE)
        return (0==0);
    return (0!=0);
}
_Bool isEmpty()
{
    if(front==rear)
        return (0==0);
    return (0!=0);
}
int pop(void)
{
    int i;
    for ( i = 1 ; i < rear ; i++ ){
        Queue[i-1] = Queue[i];
    }
    rear--;
}


int Size()
{
    return rear;
}
int print()
{
    for (int i = front; i < rear; i++)
    {
        printf("\n Data is %d\n",Queue[i]);
    }
}
int Sort()
{
    printf("\n Sorting");
    int i,j,temp;
    for(i = rear ; i > 0; i--)
    {
        for(j = 0 ; j < i-1 ; j++){
        if(Queue[j] > Queue[j+1]){
            temp = Queue[j];
            Queue[j] = Queue[j+1];
            Queue[j+1] = temp;
        }

        }
    }
}
int main()
{
    int action,result,f,i;
    while(1){

    printf("\n Provide the action: \n 1) Push\n 2) Pop \n 3) Size \n 4) print Data \n 5) Swap \n 6) Bubble Sort \n 7) Quit\n");
    scanf("%d",&action);
    int count;
    if (action == 7)
    break;
    switch(action)
    {
        case 1:

        if(!isFull()){
        add();
        }
        else
            printf("Queue is full");
        break;

        case 2:

        if(!isEmpty()){
        result = pop();
        }
        else
            printf("Empty Queue ");
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
        //result = swap(ind,ind1);    // TODO
        (result == 0)? printf("\n Swaping unsuccessful"):printf("\n Swaping Successful");
        break;

        case 6:
            printf("Bubble Sort");
            Sort();
            break;
        default:
        printf("Action required is invalid\n");
        break;
    }
    }
    return 0;
}
