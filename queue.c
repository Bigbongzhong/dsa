#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int front;
    int rear;
    int arr[100]
};

createQueue(struct Queue *q){
    q->front=-1;
    q->rear=-1;
}
isEmpty(struct  Queue *q){
    if (q->front==-1)
    {
        return 1;
    }
    else
    return 0;
}
isFull(struct Queue *q){
    if (q->rear==-1)
    {
        return 1;
    }
    else
    return 0;
}
void enqueue(struct Queue *q,int data){
    if (isFull(q)==1)
    {
        printf("queue is full");
        return;
    }
    else{
        if (isEmpty==1)
        {
            q->front=0;
        }
        q->rear++;
        q->arr[q->rear]=data;
    }
    
}
void dequeue(struct Queue *q){
if (isEmpty(q)==1)
{
    printf("queue is empty");
    return;
}
else{
    int data=q->arr[q->front];
    
    if (q->front==q->rear)
    {
        q->front=-1;
        q->rear=-1;
    }
    else
    q->front++;
    
}
}
int main(){
    struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
    
}