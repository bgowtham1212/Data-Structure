/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define SIZE 5
int current_size = 0;
struct node{
    int data;
    struct node *link;
};

struct node *top = NULL ;
int add()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *t = (struct node*)malloc(sizeof(struct node));
    if (top == NULL)
    {
        printf("Enter data: ");
        scanf("%d",&temp->data);
        temp->link = NULL;
        top = temp;
        current_size++;

    return 1;
    }
    else
    {
        struct node *temp1 = (struct node*)malloc(sizeof(struct node));

        temp = top;
        printf("Enter data: ");
        scanf("%d",&temp1->data);
        temp1->link = top;
        top = temp1;
        current_size++;
    }
}

int Remove()
{
    int index;


        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp = top;
         top = top->link;
         temp->link = NULL;
         current_size--;

}

int isFull()
{
    return (current_size >=SIZE);
}
int isEmpty()
{
    return (current_size == 0);
}
int print()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = top;

    while (temp != NULL){
        printf("\n Data is %d\n",temp->data);
        temp = temp->link;
    }
}

int main()
{
    int action,result,f,i;
    while(1){

    printf("\n Provide the action: \n 1) Append\n 2) Remove \n 3) print \n 4) Top Element \n 5) Quit \n");
    scanf("%d",&action);

    if (action == 5)
    break;
    switch(action)
    {
        case 1:
        if(!isFull())
        {
            result = add();
        }
        else
        {
            printf("Stack is full");
        }
        break;

        case 2:
        if(!isEmpty())
        {
            result = Remove();
        }
        else
        {
             printf("Stack is Empty");
        }
        break;


        case 3:
        if(!isEmpty())
        {

            result = print();
        }
        else
        {
            printf("Stack is Empty");
        }
        break;

        case 4:
        if(!isEmpty())
        {
            printf("Top element is %d",top->data);
        }
        else{
            printf("Stack is Empty");
        }
        break;

        default:
        printf("Action required is invalid\n");
        break;
    }
    }
    return 0;
}
