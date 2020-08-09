/******************************************************************************

                                    Welcome

*******************************************************************************/

#include <stdio.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *root ;
int add()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *t = (struct node*)malloc(sizeof(struct node));
    if (root == NULL)
    {
        printf("Enter data ");
        scanf("%d",&temp->data);
        temp->next = NULL;
        temp->prev = NULL;
        root = temp;

    return 1;
    }
    else
    {

        temp = root;
        while (temp->next != NULL){
            temp = temp->next;
        }
        struct node *temp1 = (struct node*)malloc(sizeof(struct node));
        printf("Enter data ");
        scanf("%d",&temp1->data);
        temp1->next = NULL;
        temp->next = temp1;
        temp1->prev = temp;

    }
    t = root;
    while(t->next!= NULL)
    {
        printf("%d",t->data);
        t=t->next;
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
        while ((i != index-1) & (index > 0))
        {
            temp = temp->next;
            i++;
        }
        struct node *temp1 = (struct node*)malloc(sizeof(struct node));
       // struct node *temp2 = (struct node*)malloc(sizeof(struct node));
        printf("Enter data ");
        scanf("%d",&temp1->data);
        if ((temp != root)|(index > 0)){
        temp1->next = temp->next;
        temp1->prev = temp->next->prev; // Or temp
        temp->next->prev = temp1;
        temp->next = temp1;
        }
        else{
            temp1->next = temp;
            temp1->prev = NULL;
            temp->prev = temp1;
            root = temp1;
        }

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
                    prev1 = prev1->next;
                    i++;

                }

            prev2 = prev1;
            while (i != index2-1)
                {
                    prev2 = prev2->next;
                    i++;
                }

            struct node *actual1,*actual2,*temp = {(struct node*)malloc(sizeof(struct node)),(struct node*)malloc(sizeof(struct node))};
            actual2 = prev2->next;

               printf("\n data of act2 %d",actual2->data);
            if((prev1 != root)||(index1!=0))
                {
                    actual1 = prev1->next;
                    temp = actual1->next;
                    printf("\n data of act1 %d",actual1->data);
                    actual1->next = actual2->next;
                    actual1->prev = actual2->prev;
                    prev2->next = actual1;
                    actual2->next = temp;
                    actual2->prev = prev1;
                    prev1->next = actual2;
                }
            else{
                    temp = prev1->next;
                    prev1->next = actual2->next;
                    prev1->prev = actual2->prev;
                    prev2->next = prev1;
                    actual2->next = temp;
                    actual2->prev = NULL;
                    temp->prev = actual2;
                    root = actual2;
                }
        }
        else if (n)
        {
            prev1 = root;
            while ((index1 != 0) & (i != index1-1))
                {
                    prev1 = prev1->next;
                    i++;

                }
            struct node *actual1,*actual2,*temp = {(struct node*)malloc(sizeof(struct node)),(struct node*)malloc(sizeof(struct node))};

            if((prev1 != root)||(index1!=0))
                {
                    actual1 = prev1->next;
                    actual2 = actual1->next;
                    actual1->next = actual2->next;
                    actual1->prev = actual2;
                    actual2->next = actual1;
                    actual2->prev = prev1;
                    prev1->next = actual2;
                }
            else{
                    actual1 = prev1;
                    actual2 = actual1->next;
                    actual1->next = actual2->next;
                    actual1->prev = actual2;
                    actual2->next = actual1;
                    actual2->prev = NULL;
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

    if ((index > size -1) | (index < 0))
     return 0;

    else if (index == 0){

        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp = root->next;
         root->next = NULL;
         temp->prev = NULL;
         root = temp;
    }
    else{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        struct node *next = (struct node*)malloc(sizeof(struct node));
        struct node *node_to_remove = (struct node*)malloc(sizeof(struct node));

        int i = 0;
        temp = root;

        while (i != index-1){
            temp = temp->next;
            i++;
        }

        node_to_remove = temp->next;
        next = node_to_remove->next;

        if(next!= NULL)
            next->prev = temp;

        temp->next = next;

        node_to_remove->next = NULL;
        node_to_remove->prev = NULL;


    }
 //   print();

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
    temp = temp->next;
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
        temp = temp->next;
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
