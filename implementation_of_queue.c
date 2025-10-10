#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct queue
{
    int front,rear;
    int data[SIZE];

};
typedef struct queue QUEUE;
void enqueue(QUEUE *q,int item)
{
    if(q->rear==SIZE-1)

        printf("\n queue overflow-queue is full!\n");


    else
{   q->rear=q->rear+1;
    q->data[q->rear]=item;
    if (q->front==-1)
        q->front=0;
    printf("\n inserted %d into the queue.\n",item);

}
}

void dequeue(QUEUE*q)
{
    if(q->front==-1){
    printf("\n queue underflow-queue is empty!\n");
}
else
{
    printf("\n deleted element is %d\n",q->data[q->front]);
   if(q->front==q->rear){
    q->front=-1;
    q->rear=-1;
   }
else{
    q->front++;
}
}
} 

void display(QUEUE q)
{
    int i;
    if(q.front==-1){
    printf("\n queue is empty.\n");
    }
    else
{
    printf("\n queue content are \n");
    for(i=q.front;i<=q.rear;i++)
    printf("%d\t",q.data[i]);
}
}
int main()
{
    int ch, item;
    QUEUE q;
    q.front=-1;
    q.rear=-1;
    for(;;)
{
        printf("\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit");
        printf("\n read choice:");
        scanf("%d",&ch);
        switch(ch)
{
    case 1: printf("\n read element to be inserted:");
            scanf("%d",&item);
            enqueue(&q,item);
            break;
    case 2: dequeue(&q);
            break;
    case 3: display(q);
            break;
    default: exit(0);
}
}
return 0;
}
