#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
    struct node *prev;
};

struct node* head = NULL; 


struct node* createnode(int data) {
    struct node* s = (struct node*)malloc(sizeof(struct node));
    s->info = data;
    s->next = NULL;
    s->prev = NULL;
    return s;
}


struct node* insertAtTop(struct node* head, int data) {
    struct node* s = createnode(data);
    s->next = head;
    head->prev = s;
    s->prev = NULL;
    head = s;
    return head;
}


struct node* deleteAtTop(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct node* temp = head;
    head = head->next;  
    free(temp);
    head->prev=NULL;  
    return head;
}


void traverse(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->info); 
        head = head->next;  
    }
    printf("\n");
}
void revtraverse(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head->next != NULL) {
        // printf("%d ", head->info); 
        head = head->next;  
    }
    while (head !=NULL)
    {
        printf("%d ", head->info); 
        head = head->prev;  
    }
    
    printf("\n");
}

int main() {
    int a, dat;
    while (1) {
    
        printf("Enter choice:\n");
        printf("1. Create first node\n");
        printf("2. Insert at top\n");
        printf("3. Delete at top\n");
        printf("4. Traverse\n");
        printf("5. revTraverse\n");
        printf("6. Exit\n");
        scanf("%d", &a);

        switch (a) {
            case 1:
                printf("Enter first node element: ");
                scanf("%d", &dat);
                head = createnode(dat); 
                break;
            case 2:
                printf("Enter element to insert at top: ");
                scanf("%d", &dat);
                head = insertAtTop(head, dat);
                break;
            case 3:
                head = deleteAtTop(head);
                break;
            case 4:
                traverse(head);  
                break;
            case 5:
                revtraverse(head);
                break;
            case 6:
                return 0; 
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
