#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data > root->data) {
        root->right = insertNode(root->right, data);
    } else {
        root->left = insertNode(root->left, data);
    }
    return root;
}

// Function to perform Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int number, data;
    struct Node* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &number);

    for (int i = 0; i < number; i++) {
        printf("Enter node value: ");
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    return 0;
}
