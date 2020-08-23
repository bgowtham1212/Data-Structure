/******************************************************************************

                        Welcome To Binary Search Tree

*******************************************************************************/

#include <stdio.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node *root ;
/*int add()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    if (root == NULL)
    {
        printf("Enter data ");
        scanf("%d",&temp->data);
        temp->right = NULL;
        temp->left = NULL;
        root = temp;

    return 1;
    }
    else
    {

        temp = root;

        struct node *temp1 = (struct node*)malloc(sizeof(struct node));

        printf("Enter data ");
        scanf("%d",&temp1->data);

        temp1->left = temp1->right = NULL;

        if(temp1->data < temp->data)
            appendLeft(&temp->left,temp1);
        else
            appendRight(&temp->right,temp1);

    }

}

int appendLeft(struct node **left_temp,struct node *temp1 ){   //Pointer to pointer (left & right)

        if( (*left_temp) != NULL)   // left_temp = &temp->left   De-ref once provides value at which temp->left points.
        {                           //Checks whether data pointed is null.   (*left_temp)->left = left address value at temp->left
//                   ----------------------
// If &temp->left = | left  | data | right |,then (*left_temp)->left points to left field of temp->left.
//                   ----------------------

            if((temp1)->data < (*left_temp)->data){
                struct node *dummy = &((*left_temp)->left);
                appendLeft(dummy,temp1);
            }
            else{
                struct node *dummy = &((*left_temp)->right);
                appendRight(dummy,temp1);
            }
        }
        else
            (*left_temp) = (temp1);


}
int appendRight(struct node **right_temp,struct node *temp1 ){    //Pointer to pointer (left & right)

        if((*right_temp) != NULL)
        {

            if((temp1)->data < (*right_temp)->data)
            {
                struct node *dummy = &((*right_temp)->left);
                appendLeft(dummy,temp1);
            }
            else{
                struct node *dummy = &((*right_temp)->right);
                appendRight(dummy,temp1);
            }
        }
        else
            (*right_temp) = temp1;

}*/
int add()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));

        printf("Enter data ");
        scanf("%d",&temp->data);
        temp->right = NULL;
        temp->left = NULL;

    if (root == NULL)
    {
        root = temp;
    return 1;
    }
    else
    {

        struct node *temp1 = (struct node*)malloc(sizeof(struct node));
        struct node *last_node = (struct node*)malloc(sizeof(struct node));
        temp1 = root;
        while(temp1!= NULL){
                last_node = temp1;
            if( temp1->data > temp->data ){
               // last_node = temp1->right;
                temp1 = temp1->left;
            }
            else{
             //   last_node = temp1->left;
                temp1 = temp1->right;
            }
        }
        if(last_node->data > temp->data)
            last_node->left = temp;
        else
            last_node->right = temp;

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
            temp = temp->right;
            i++;
        }
        struct node *temp1 = (struct node*)malloc(sizeof(struct node));
       // struct node *temp2 = (struct node*)malloc(sizeof(struct node));
        printf("Enter data ");
        scanf("%d",&temp1->data);
        if ((temp != root)|(index > 0)){
        temp1->right = temp->right;
        temp1->left = temp->right->left; // Or temp
        temp->right->left = temp1;
        temp->right = temp1;
        }
        else{
            temp1->right = temp;
            temp1->left = NULL;
            temp->left = temp1;
            root = temp1;
        }

    }
    return 1;

}
int swap( int index1,  int index2)
{
    unsigned int i = 0, n;
    struct node *left1 = (struct node*)malloc(sizeof(struct node));
    struct node *left2 = (struct node*)malloc(sizeof(struct node));
    if ((index1 >= Size()) || (index2 >= Size())||(index2 <= index1))
    return 0;
    else
    {
        n = index2 - index1;
        if (n>1)
        {
            left1 = root;
            while ((index1 != 0) & (i != index1-1))
                {
                    left1 = left1->right;
                    i++;

                }

            left2 = left1;
            while (i != index2-1)
                {
                    left2 = left2->right;
                    i++;
                }

            struct node *actual1,*actual2,*temp = {(struct node*)malloc(sizeof(struct node)),(struct node*)malloc(sizeof(struct node))};
            actual2 = left2->right;

               printf("\n data of act2 %d",actual2->data);
            if((left1 != root)||(index1!=0))
                {
                    actual1 = left1->right;
                    temp = actual1->right;
                    printf("\n data of act1 %d",actual1->data);
                    actual1->right = actual2->right;
                    actual1->left = actual2->left;
                    left2->right = actual1;
                    actual2->right = temp;
                    actual2->left = left1;
                    left1->right = actual2;
                }
            else{
                    temp = left1->right;
                    left1->right = actual2->right;
                    left1->left = actual2->left;
                    left2->right = left1;
                    actual2->right = temp;
                    actual2->left = NULL;
                    temp->left = actual2;
                    root = actual2;
                }
        }
        else if (n)
        {
            left1 = root;
            while ((index1 != 0) & (i != index1-1))
                {
                    left1 = left1->right;
                    i++;

                }
            struct node *actual1,*actual2,*temp = {(struct node*)malloc(sizeof(struct node)),(struct node*)malloc(sizeof(struct node))};

            if((left1 != root)||(index1!=0))
                {
                    actual1 = left1->right;
                    actual2 = actual1->right;
                    actual1->right = actual2->right;
                    actual1->left = actual2;
                    actual2->right = actual1;
                    actual2->left = left1;
                    left1->right = actual2;
                }
            else{
                    actual1 = left1;
                    actual2 = actual1->right;
                    actual1->right = actual2->right;
                    actual1->left = actual2;
                    actual2->right = actual1;
                    actual2->left = NULL;
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
        temp = root->right;
         root->right = NULL;
         temp->left = NULL;
         root = temp;
    }
    else{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        struct node *right = (struct node*)malloc(sizeof(struct node));
        struct node *node_to_remove = (struct node*)malloc(sizeof(struct node));

        int i = 0;
        temp = root;

        while (i != index-1){
            temp = temp->right;
            i++;
        }

        node_to_remove = temp->right;
        right = node_to_remove->right;

        if(right!= NULL)
            right->left = temp;

        temp->right = right;

        node_to_remove->right = NULL;
        node_to_remove->left = NULL;


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
    temp = temp->right;
    }
    return i;
}
int print()
{
    struct node *left = (struct node*)malloc(sizeof(struct node));
    struct node *right = (struct node*)malloc(sizeof(struct node));
    //temp = root;
    int i = 0, size;

    printf("\n Root Node is %d",root->data);

    left = root->left;
    right = root->right;

    while(left != NULL){
         printf("\n Left Node Elements are %d\n",left->data);
         if (left->right != NULL)
            printf("\n Right Node of %d is %d\n",left->data,left->right->data);
         left = left->left;
    }

       // temp = root;
        while(right != NULL){
         printf("\n Right Node Elements are %d\n",right->data);
                  if (right->left != NULL)
            printf("\n Left Node of %d is %d\n",right->data,right->left->data);
         right = right->right;
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
