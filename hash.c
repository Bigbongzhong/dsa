#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node*next;
};
int size=10;
struct node** hashtable;
double loadFactor=0;
int elements=0;
int hashFunction(int key){
    int sum=0;
    for ( ; key ; key/=10, sum+=key%10)
    return sum%size;
}
void insert(int key){
    elements+=1;
    loadFactor=elements/size;
    int index=hashFunction(key);
    if(loadFactor>=0.75){
        size*=2;
        hashtable = (struct node**)realloc(hashtable, size * sizeof(struct node*));
        
    }
    while(hashtable[index]!=NULL){
        printf("collision occured :");
        // index=(index+1)%10;
        elements-=1;
        return;
    }
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->key=key;
    hashtable[index]=newNode;
}
void displayHashTable() {
    for (int i = 0; i < 10; i++) {
        if (hashtable[i]!=NULL) {
            printf("Index %d: Key %d\n", i, hashtable[i]->key);
        } else {
            printf("Index %d: NULL\n", i);
        }
    }
}
int main() {
    // Initialize the hash table
    for (int i = 0; i < 10; i++) {
        hashtable[i] = NULL;
    }
    int key;
    int o;
    printf("press 1 for insertion: \n");
    printf("press 2 for display: \n");
    scanf("%d", &o);
    switch (o)
    {
    case 1:
        printf("enter the key to be inserted: ");
        scanf("%d", &key);
        insert(key);
        break;
    case 2:
    displayHashTable();
    break;

    default:
        break;
    }
    return 0;
}