#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row,col,data;
    struct node*next;
    struct node*prev;
};
typedef struct node *NODE;
NODE insertend(NODE start,int row,int col, int item)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->row=row;
    temp->col=col;
    temp->data=item;
    temp->next=NULL;
    temp->prev=NULL;
    if(start==NULL)
        return temp;
    cur=start;
    while(cur->next!=NULL)
        cur=cur->next;
    cur->next=temp;
    temp->prev=cur;
    return start;
}
void display(NODE start)
{
    NODE temp;
    if(start==NULL)
        printf("\n the list is empty");
    else
    {
        printf("\nROW\tCOL\tDATA\t");
        temp=start;
        while(temp!=NULL)
        {
            printf("%d\t%d\t%d\n",temp->row,temp->col,temp->data);
            temp=temp->next;
        }
    }
}
void displaymatrix(NODE start,int m,int n)
{
    NODE temp=start;
    int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(temp!=NULL && temp->row==i && temp->col==j)
            {
                printf("%d\t",temp->data);
                temp=temp->next;
        }
    else
        printf("0\t");
}
printf("\n");
    }
}
int main()
{
    int i,j,m,n,item;
    NODE start=NULL;
    printf("\n read order of matrix\n");
    scanf("%d%d",&m,&n);
    printf("\n read elements\n");
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&item);
            if(item!=0)
                start=insertend(start,i,j,item);
        }
    }
    display(start);
    printf("\n sparse matrix is\n");
    displaymatrix(start,m,n);
    return 0;
}
