/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define SIZE 5
int current_size = 0, temp_current_size = 0;
struct node{
    int data;
    struct node *link;
};

struct node *top,*temp_top = {NULL,NULL};
int add(_Bool Sort,int temp2,_Bool UserInput)
{
        struct node *temp = (struct node*)malloc(sizeof(struct node));

    if(!Sort){
            struct node *t = (struct node*)malloc(sizeof(struct node));
            if ((top == NULL)&&(UserInput))
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
                if(UserInput){
                printf("Enter data: ");
                scanf("%d",&temp1->data);
                temp1->link = top;
                top = temp1;
                current_size++;
                }
                else{
                temp1->data = temp2;
                temp1->link = top;
                top = temp1;
                current_size++;
                }
            }
        }
    else{                       //True

            if (temp_top == NULL)
            {

                temp->data = temp2;
                temp->link = NULL;
                temp_top = temp;
                temp_current_size++;

            return 1;
            }
            else
            {
                struct node *temp1 = (struct node*)malloc(sizeof(struct node));

                temp1->data = temp2;
                temp1->link = temp_top;
                temp_top = temp1;
                temp_current_size++;
            }
        }
}

int* Remove(_Bool FirstPop)
{
    int index, *current_size1;



        struct node *temp = (struct node*)malloc(sizeof(struct node));
         struct node *top1 = (struct node*)malloc(sizeof(struct node));

        top1 = (FirstPop)?(top):(temp_top);
        current_size1 = (FirstPop)?(&current_size):(&temp_current_size);
        *temp = *top1;
        if(top1->link!= NULL)
         *top1 = *(top1->link);
         else{
                 top1 = NULL;
                 if(FirstPop)
                    top = NULL;
                 else
                    temp_top = NULL;
         }
         temp->link = NULL;
         (*current_size1)--;
        return &temp->data;


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
int sort()
{
    int *pop = 0, *temp_pop = 0;

    while(top!= NULL)
    {

      pop = Remove((0==0));

      if(temp_top == NULL){
      add((0==0),*pop,(0==0));
      }
      else{
        if(temp_top->data < *pop){
            add((0==0),*pop,(0==0));
        }
        else{
                temp_pop = pop;
                while(temp_top!= NULL){
             pop = Remove((0!=0));
             add((0!=0),*pop,(0!=0));
            }
        add((0==0),*temp_pop,(0==0));
        }
      }
    }


    struct node *t = (struct node*)malloc(sizeof(struct node));
    t = temp_top;
    while (t != NULL){
        printf("\n Sorted Data is %d\n",t->data);
        t = t->link;
    }
}
int main()
{
    int action,result,f,i;
    int* Popped_data;
    while(1){

    printf("\n Provide the action: \n 1) Append\n 2) Remove \n 3) print \n 4) Top Element \n 5) Sort \n 6) Quit \n ");
    scanf("%d",&action);

    if (action == 6)
    break;
    switch(action)
    {
        case 1:
        if(!isFull())
        {
            result = add((0!=0),NULL,(0==0));
        }
        else
        {
            printf("Stack is full");
        }
        break;

        case 2:
        if(!isEmpty())
        {
            Popped_data = Remove((0==0));
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

        case 5:
        if(!isEmpty())
        {
            sort();
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
