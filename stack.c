#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int *arr;
    int capacity;
};

struct stack* createStack(int capacity){
struct stack* s=(struct stack*)malloc(sizeof(struct stack));
s->arr=(int*)malloc(s->capacity*sizeof(int));
s->capacity=capacity;
s->top=-1;
return s;
}
int isFull(struct stack* s){
    if(s->top==s->capacity-1){
        return 1;
    }
    else{
        return 0;
    }
    
}
struct stack* push(struct stack* s, int data){
    if(isFull(s)==1)
    {
        printf("stack is full:\n");
    }
    else{
        s->top+=1;
        s->arr[s->top]=data;
    }
    return s;
}
int isEmpty(struct stack* s){
    if (s->top<0)
    {
        return 1;
    }
    else
    return 0;
    
}
void pop(struct stack* s){
    if (isEmpty(s)==1)
    {
        printf("stack is empty:\n");
        return;
    }
    else{
        int temp=s->arr[s->top];
        printf("popped %d", temp);
        s->top-=1;
    }
}
int peek(struct stack* s){
    if (s->top<0)
    {
        printf("empty:");
    }
    else{
    return s->arr[s->top];
}
}
void display(struct stack* s){
    if (isEmpty(s)==1)
    {
        printf("stack empty:\n");
    }
    else{
    for (int i = 0; i <= s->top; i++) {
            printf("element at:%d is %d\n",i, s->arr[i]);
        }
    }
}
struct stack* terminateAll(struct stack* s){
    if (isEmpty(s)==1)
    {
        printf("no elements:\n");
    }
    else{
        while(s->top>=0)
        s->top-=1;
    }
    return s;
    
}
int main(){
    struct stack*s=NULL;
    int choice, value, capacity;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Stack\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Peek\n");
        printf("5. Display\n");
        printf("6. free all elements\n");
        printf("7. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (s != NULL) {
                    printf("Stack already created.\n");
                    break;
                }
                printf("Enter the capacity of the stack: ");
                scanf("%d", &capacity);
                s = createStack(capacity);
                printf("Stack created with capacity %d\n", capacity);
                break;

            case 2:
                if (s == NULL) {
                    printf("Stack not created yet.\n");
                    break;
                }
                printf("Enter the value to push: ");
                scanf("%d", &value);
                s=push(s, value);
                break;

            case 3:
                if (s == NULL) {
                    printf("Stack not created yet.\n");
                    break;
                }
                pop(s);
                break;

            case 4:
                if (s == NULL) {
                    printf("Stack not created yet.\n");
                    break;
                }
                value = peek(s);
                printf("top element is: %d", value);
                break;

            case 5:
                if (s == NULL) {
                    printf("Stack not created yet.\n");
                    break;
                }
                display(s);
                break;
            case 6:
            s=terminateAll(s);
            printf("all elements cleared:\n");
            break;
            case 7:
            return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}