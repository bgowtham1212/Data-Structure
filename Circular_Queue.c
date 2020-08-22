/******************************************************************************

                    Welcome to Circular Queue

*******************************************************************************/

#include <stdio.h>
#define SIZE 5
int Queue[SIZE] ;
int rear = -1;
int front = -1;
int add()
{

       printf("\n Enter Data to be stored in Queue ");
       if(front >= SIZE)
        front = 0;
       if(front == -1){
                  front = 0;
       rear = 0;
       scanf("%d",&Queue[rear]);
       return 0;
       }
       else if (rear == SIZE-1)
       {rear = 0;
       scanf("%d",&Queue[rear]);
       return 0;}
       rear++;
       scanf("%d",&Queue[rear]);
     printf("Rear is %d",rear);
}
_Bool isFull()
{
    if(((rear==SIZE-1) && (!front))  || (front == rear+1))
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

    printf("Popping item %d",Queue[front]);
    printf("front is %d",front);
   // if (front < rear)
   if (front == rear){
    front = -1;
    rear = -1;
   }
   if (front < rear)
        front++;


}


int Size()
{
    return rear;
}

int print()
{
    printf("Front is %d",front);
    printf("Rear is %d",rear);
    if (front <= rear){
    for (int i = front; i <= rear; i++)
    {
        printf("\n Data is %d\n",Queue[i]);
    }
    }
    else{
    for (int i = front; i <= SIZE + rear ; i++)
    {
        printf("\n Data is %d\n",Queue[i%SIZE]);
    }
    }
}
int Sort()
{
    printf("\n Sorting");
    int i,j,temp;
    for(i = rear ; i > front; i--)
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

        if((!isEmpty())|(front != -1)) {
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
        if((!isEmpty())|(front != -1)) {
        result = print();}
        else{
        printf("\n No Data to display ");
        }

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
