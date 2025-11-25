#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

NODE createBST(NODE root,int key)
{
    NODE temp,cur,prev;
    temp=(NODE)malloc(sizeof(struct node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
        return temp;
    cur=root;
    prev=NULL;
    while(cur!=NULL)
    {
        prev=cur;
        if(key<cur->data)
            cur=cur->left;
        else
            cur=cur->right;
    }
    if(key<prev->data)
        prev->left=temp;
    else
        prev->right=temp;
    return root;
}

void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
int main()
{
    NODE root=NULL;
    int ch,item;
    for(;;)
    {
    printf("\n1.insert");
    printf("\n2.preorder");
    printf("\n3.inorder");
    printf("\n4.postorder");
    printf("\n5.exit");
    printf("\n Read choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("\n create item to be inserted:");
                scanf("%d",&item);
                root=createBST(root,item);
                break;
        case 2: printf("\n preorder traversal is\n");
                preorder(root);
                break;
        case 3: printf("\n inorder traversal is\n");
                inorder(root);
                break;
        case 4: printf("\n postorder traversal is\n");
                postorder(root);
                break;
        default:exit(0);
    }
    }
    return 0;
}
