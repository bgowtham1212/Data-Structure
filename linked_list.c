/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
struct node{
    int data;
    struct node *link;
};
struct node *root ;
int add()
{
    //printf("ent");
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *t = (struct node*)malloc(sizeof(struct node));
    if (root == NULL)
    {
        printf("Enter data ");
        scanf("%d",&temp->data);
        temp->link = NULL;
        root = temp;

    return 1;
    }
    else
    {

        temp = root;
        while (temp->link != NULL){
            temp = temp->link;
        }
        struct node *temp1 = (struct node*)malloc(sizeof(struct node));
        printf("Enter data ");
        scanf("%d",&temp1->data);
        temp1->link = NULL;
        temp->link = temp1;

    }
    t = root;
    while(t->link!= NULL)
    {
        printf("%d",t->data);
        t=t->link;
    }
}
int insert(int index)
{
    int i = 0;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (index >= Size())
    return 0;
    else
    {
        temp = root;
        while (i!=index-1)
        {
            temp = temp->link;
            i++;
        }
        struct node *temp1 = (struct node*)malloc(sizeof(struct node));
        printf("Enter data ");
        scanf("%d",&temp1->data);
        temp1->link = temp->link;
        temp->link = temp1;

    }
    return 1;

}
int swap( int index1,  int index2)
{
    unsigned int i = 0, n;
    struct node *prev1 = (struct node*)malloc(sizeof(struct node));
    struct node *prev2 = (struct node*)malloc(sizeof(struct node));
    if ((index1 >= Size()) || (index2 >= Size())||(index2 <= index1))
    return 0;
    else
    {
        n = index2 - index1;
        if (n>1)
        {
            prev1 = root;
            while ((index1 != 0) & (i != index1-1))
                {
                    prev1 = prev1->link;
                    i++;

                }
            //   printf("\n 1st ind %d",prev1->data);
           // j = i;
            prev2 = prev1;
            while (i != index2-1)
                {
                    prev2 = prev2->link;
                    i++;
                }

            struct node *actual1,*actual2,*temp = {(struct node*)malloc(sizeof(struct node)),(struct node*)malloc(sizeof(struct node))};
            actual2 = prev2->link;

              // printf("\n data of act1 %d",actual1->data);
               printf("\n data of act2 %d",actual2->data);
            if((prev1 != root)||(index1!=0))
                {
                    actual1 = prev1->link;
                    temp = actual1->link;
                    printf("\n data of act1 %d",actual1->data);
                    actual1->link = actual2->link;
                    prev2->link = actual1;
                    actual2->link = temp;
                    prev1->link = actual2;
                }
            else{
                    temp = prev1->link;
                    prev1->link = actual2->link;
                    prev2->link = prev1;
                    actual2->link = temp;
                    root = actual2;
                }
        }
        else if (n)
        {
            prev1 = root;
            while ((index1 != 0) & (i != index1-1))
                {
                    prev1 = prev1->link;
                    i++;

                }
            struct node *actual1,*actual2,*temp = {(struct node*)malloc(sizeof(struct node)),(struct node*)malloc(sizeof(struct node))};

            if((prev1 != root)||(index1!=0))
                {
                    actual1 = prev1->link;
                    actual2 = actual1->link;
                    actual1->link = actual2->link;
                    actual2->link = actual1;
                    //actual2->link = temp;
                    prev1->link = actual2;
                }
            else{
                    actual1 = prev1;
                    actual2 = actual1->link;
                    actual1->link = actual2->link;
                    actual2->link = actual1;
                    //actual2->link = temp;
                    root = actual2;
                }
        }
    }

return 1;
}
int Remove()
{
    int index;
    scanf("%d",&index);
    int size = Size();
    if (index > size -1)
     return 0;
    else if (index == 0){
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp = root->link;
         root->link = NULL;
         root = temp;
    }
    else{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
         struct node *temp1 = (struct node*)malloc(sizeof(struct node));
        int i = 0;
        temp = root;
        while (i != index-1){
            temp = temp->link;
            i++;
        }
        temp1 = temp->link;
        temp->link = temp1->link;
        temp1->link = NULL;

    }
    print();

}
int Size()
{
    int i = 0;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = root;
    while (temp != NULL)
    {
    i++;
    //printf("\n Data is %d",temp->data);
    temp = temp->link;
    }
    return i;
}
int print()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = root;
    int i = 0, size;
    size = Size();
    for (i = 0; i < size; i++)
    {
        printf("\n Data is %d\n",temp->data);
        temp = temp->link;
    }
}

int main()
{
    int action,result,f,i;
    while(1){

    printf("\n Provide the action: \n 1) Append\n 2) Remove \n 3) Size \n 4) print Data \n 5) Insert element \n 6) Swap \n 7) Quit\n");
    scanf("%d",&action);

    if (action == 7)
    break;
    switch(action)
    {
        case 1:
        result = add();
        break;

        case 2:
        printf("\n Index to remove? ");

        result = Remove();
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
        printf("\n Index to Insert? ");
        int index;
        scanf("%d",&index);
        result = insert(index);
        break;

        case 6:
        printf("\n Index to Swap? ");
        int ind,ind1;
        scanf("%d %d",&ind,&ind1);
        result = swap(ind,ind1);
        (result == 0)? printf("\n Swaping unsuccessful"):printf("\n Swaping Successful");
        break;

        default:
        printf("Action required is invalid\n");
        break;
    }
    }
    return 0;
}
