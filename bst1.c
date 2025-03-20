#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node* left;
    struct node* right;
};
struct node* root=NULL;
struct node* rroot=NULL;

struct node* createTree(int data) {
    struct node* s = (struct node*)malloc(sizeof(struct node));
    s->info = data;
    s->left = NULL;
    s->right = NULL;
    return s;
}

struct node* insertNode(struct node* root, int data) {
    if (root == NULL) {
        return createTree(data);
    }
    if (data < root->info) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

struct node* inorderTraverse(struct node* root, int x){
    if (root == NULL) {
        return NULL;
    } 
    if (x == 0) {
        inorderTraverse(root->left, 0);
        printf("%d ", root->info);
        inorderTraverse(root->right, 0);
    } else {
        rroot = inorderTraverse(root->left, 5);
        rroot = inorderTraverse(root->right, 5);
        return rroot;
    }
    return NULL;
}

void preorderTraverse(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->info);
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}

void postorderTraverse(struct node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraverse(root->left);
    postorderTraverse(root->right);
    printf("%d ", root->info);
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) {
        printf("The tree is empty\n");
        return root;
    }
    if (root->info == data) {
        int x = 10;
        rroot = inorderTraverse(root, x);
        root = rroot;
        if (root->left == NULL) {
            root->info = root->right->info;
            return root;
        }
        if (root->right == NULL) {
            root->info = root->left->info;
            return root;
        }
    }
    if (data < root->info) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->info) {
        root->right = deleteNode(root->right, data);
    }
    return root;
}

int main() {
    int a, b, data, node;
    printf("Enter size of tree: ");
    scanf("%d", &a);
    printf("Enter data of root node: ");
    scanf("%d", &data);
    root = createTree(data);

    while (1) {
        printf("What do you want to do?\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traverse\n");
        printf("4. Preorder Traverse\n");
        printf("5. Postorder Traverse\n");
        printf("6. Exit\n");
        scanf("%d", &b);
        switch (b) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter which node you want to delete: ");
                scanf("%d", &node);
                root = deleteNode(root, node);
                break;
            case 3:
                inorderTraverse(root, 0);
                printf("\n");
                break;
            case 4:
                preorderTraverse(root);
                printf("\n");
                break;
            case 5:
                postorderTraverse(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}