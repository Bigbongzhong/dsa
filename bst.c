#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node* left;
    struct node* right;
};
struct node* root=NULL;
struct node* rroot=NULL;
createNode(int data) {
    struct node* s = (struct node*)malloc(sizeof(struct node));
    s->info = data;
    s->left = NULL;
    s->right = NULL;
    return s;
}
struct node* insertNode(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->info) {
        root->left = insertTree(root->left, data);
    } else {
        root->right = insertTree(root->right, data);
    }
    return root;
}

struct node* inorderTraverse(struct node* root, int x){
    if (root==NULL){
        return root;
    } 
    if (x==0)
    {
        inorderTraverse(root->left,0);
        printf(root->info);
        inorderTraverse(root->right,0);
    }
    else{
        rroot=inorderTraverse(root->left,5);
        rroot=inorderTraverse(root->right,5);
        return rroot;
    }
}
preorderTraverse(struct node* root){
    if (root==NULL)
    {
        return;
    }
    printf(root->info);
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}
postorderTraverse(struct node* root){
    if (root==NULL)
    {
        return;
    }
    postorderTraverse(root->left);
    postorderTraverse(root->right);
    printf(root->info);
}
struct node* deleteNode(struct node* root, int data) {
    if (root == NULL){
        printf("the tree is empty:");
        return root;
    }
    if (root->info==data){
        int x=10;
            rroot=inorderTraverse(root, x);
            root=rroot;
        if (root->left==NULL){
        
            root->info=root->right->info;
            return root;
        }
        if (root->right==NULL)
        {
            root->info=root->left->info;
            return root;
        }
    }
    if (data<root->info)
    {
        deleteNode(root->left, data);
    }
    if (data>root->info)
    {
        deleteNode(root->right, data);
    }
}











int main(){

    int a, b, data, root, node ;
    scanf("enter size of tree:%d", &a);
    scanf("enter data of root node:%d",&data);
    root =createNode(data);
    printf("what do you want to do?");
        printf("1. Create root node\n");
        printf("2. Insert\n");
        printf("3. delete:");
        printf("4. inorderTraverse\n");
        printf("5. preorderTraverse\n");
        printf("6. postorderTraverse\n");
        printf("7. Exit\n");
        scanf("%d", &b);
        switch (b)
        {
        case 1:
            root=createTree(data);
            break;
        case 2:
            root=insertNode(root, data);
            break;
        case 3:
            scanf("enter which node you want to delete:%d", node);
            root=deleteNode(root, node);
            break;
        case 4:
            root=inorderTraverse(root, 0);
            break;
        case 5:
            preorderTraverse(root);
            break;
        case 6:
            postorderTraverse(root);
            break;
        case 7:
            printf("Exiting program:");
            break;
        default:
            break;
        }

}