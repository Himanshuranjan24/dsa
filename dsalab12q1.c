/* Wap to do the insertion in the bst and do the following on the created bst
i)Inorder traversal
ii)Pre order
iii)Post order
iv)Finding highest elements in the tree 
v)Finding lowest elements in the tree
vi)Display the content of tree in increasing order
vii)Find height. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int data;
    struct node *left,*right;
}*root = NULL;
typedef struct node node;

node* newnode(int item)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
node* insert(node *p, int item)
{
    if(p == NULL)
    {
        return newnode(item);
    }
    if(item < p->data)
    p->left = insert(p->left, item);
    else
    p->right = insert(p->right,item);
    return p;
}
void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int highest(node *root)
{
    if(root == NULL)
    return INT_MIN;

    int res = root->data;
    int lres = highest(root->left);
    int rres = highest(root->right);
    if(lres > res)
    res = lres;
    if(rres > res)
    res = rres;
    return res;
}
int lowest(node *root)
{
    if(root == NULL)
    return INT_MAX;

    int res = root->data;
    int lres = lowest(root->left);
    int rres = lowest(root->right);
    if(lres < res)
    res = lres;
    if(rres < res)
    res = rres;
    return res;
}
int height(node *root)
{
    if(root == NULL)
    return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    if(lheight > rheight)
    return lheight+1;
    else
    return rheight+1;
}

void main()
{
    int max = highest(root);
    int min = lowest(root);
    int h = height(root);
    int n,item;
    printf("Input total no. of elements : ");
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++)
    {
        printf("Enter element to be added in tree : ");
        scanf("%d",&item);
        root = insert(root,item);
    }
    int opt = 0;
    while(opt != 8)
    {
        printf("\n\n1.Inorder Traversal\n");
        printf("2.Preorder Traversal\n");
        printf("3.Postorder Traversal\n");
        printf("4.Find heighest element\n");
        printf("5.Find lowest element\n");
        printf("6.Display BST in increasing order\n");
        printf("7.Find height\n");
        printf("8.Exit\n");
        printf("Choose an option : ");
        scanf("%d",&opt);
        while(opt < 1 || opt > 8)
        {
            printf("Choose valid option : ");
            scanf("%d",&opt);
        }
        switch(opt)
        {
            case 1:
                    printf("\n\nInorder Traversal\n");
                    inorder(root);
                    break;
            case 2:
                    printf("\n\nPreorder Traversal\n");
                    preorder(root);
                    break;
            case 3:
                    printf("\n\nPostorder Traversal\n");
                    postorder(root);
                    break;
            case 4:
                    
                    printf("\n\n%d is the maximum.",max);
                    break;
            case 5:
                    
                    printf("\n\n%d is the minimum.",min);
                    break;
            case 6:
                    printf("\n\nBST in increasing order is :\n");
                    inorder(root);
                    break;
            case 7:
                    
                    printf("\n\nHeight of BST is : %d",h);
                    break;
            case 8:
                    printf("\n\nThank u!\n\n");
                    break;
        }
    }
}