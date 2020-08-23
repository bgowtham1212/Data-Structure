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

       if(front == -1){     //Initial Data push
                  front = 0;
       rear = 0;
       scanf("%d",&Queue[rear]);
       return 0;
       }
       else if (rear == SIZE-1)   //Reset Rear if it reaches size & front is not 0.
       {rear = 0;
       scanf("%d",&Queue[rear]);
       return 0;}
       rear++;
       scanf("%d",&Queue[rear]);  //  Normal Push

}
_Bool isFull()
{
    if(((rear==SIZE-1) && (!front))  | (front == rear+1))
    {
        return (0==0);
    }

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

    printf("\n Popping item %d",Queue[front]);


   if (front == rear){
    front = -1;
    rear = -1;
   }
   else
    front++;
if (front == SIZE)
    front = 0;

}


int Size()
{
    return rear;
}

int print()
{
    int count,element;
    count = (front<=rear)? rear: SIZE + rear;

    for (int i = front; i <= count; i++)
    {
        element = (front<=rear)? i : i%SIZE ;
        printf("\n Data is %d\n",Queue[element]);
    }

}
int Sort()
{
    printf("\n Sorting");
    int i,j,temp,count,left_element,right_element;

    count = (front<rear)? rear: SIZE + rear;

    for(i = count ; i > front; i--)
    {
        for(j = front ; j < i ; j++)
        {

        left_element = (front<rear)? j : j%SIZE;
        right_element = (front<rear)? j+1 : (j+1)%SIZE;

            if(Queue[left_element] > Queue[right_element])
            {
                temp = Queue[left_element];
                Queue[left_element] = Queue[right_element];
                Queue[right_element] = temp;
            }

        }
    }

}
int main()
{
    int action,result,f,i;
    while(1){

    printf("\n Provide the action: \n 1) Push\n 2) Pop \n 3) Size \n 4) print Data \n 5) Bubble Sort \n 6) Quit\n");
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

       /* case 5:
        printf("\n Index to Swap? ");
        int ind,ind1;
        scanf("%d %d",&ind,&ind1);
        //result = swap(ind,ind1);    // TODO
        (result == 0)? printf("\n Swaping unsuccessful"):printf("\n Swaping Successful");
        break;*/

        case 5:
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
