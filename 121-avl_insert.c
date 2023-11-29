#include <stdio.h>
#include <stdlib.h>

// AVL Tree Node structure
typedef struct avl_node {
    int value;
    struct avl_node *left;
    struct avl_node *right;
    int height;
} avl_t;

// Function to get the height of a node
int height(avl_t *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new AVL node
avl_t *newNode(int value) {
    avl_t *node = (avl_t *)malloc(sizeof(avl_t));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Function to right rotate a subtree rooted with y
avl_t *rightRotate(avl_t *y) {
    avl_t *x = y->left;
    avl_t *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate a subtree rooted with x
avl_t *leftRotate(avl_t *x) {
    avl_t *y = x->right;
    avl_t *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get the balance factor of a node
int getBalance(avl_t *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a value into an AVL Tree
avl_t *avl_insert(avl_t **tree, int value) {
    // Standard BST insert
    if (*tree == NULL)
        return newNode(value);

    if (value < (*tree)->value)
        (*tree)->left = avl_insert(&((*tree)->left), value);
    else if (value > (*tree)->value)
        (*tree)->right = avl_insert(&((*tree)->right), value);
    else // Equal values are not allowed in AVL Tree
        return *tree;

    // Update height of the current node
    (*tree)->height = 1 + max(height((*tree)->left), height((*tree)->right));

    // Get the balance factor to check if this node became unbalanced
    int balance = getBalance(*tree);

    // Left Left Case
    if (balance > 1 && value < (*tree)->left->value)
        return rightRotate(*tree);

    // Right Right Case
    if (balance < -1 && value > (*tree)->right->value)
        return leftRotate(*tree);

    // Left Right Case
    if (balance > 1 && value > (*tree)->left->value) {
        (*tree)->left = leftRotate((*tree)->left);
        return rightRotate(*tree);
    }

    // Right Left Case
    if (balance < -1 && value < (*tree)->right->value) {
        (*tree)->right = rightRotate((*tree)->right);
        return leftRotate(*tree);
    }

    // No rotation needed, return the unchanged node pointer
    return *tree;
}

// Function to print an AVL Tree in-order
void inOrderTraversal(avl_t *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->value);
        inOrderTraversal(root->right);
    }
}

// Function to free the memory allocated for an AVL Tree
void freeAVLTree(avl_t *root) {
    if (root != NULL) {
        freeAVLTree(root->left);
        freeAVLTree(root->right);
        free(root);
    }
}

// Example usage
int main() {
    avl_t *root = NULL;

    root = avl_insert(&root, 10);
    root = avl_insert(&root, 20);
    root = avl_insert(&root, 30);
    root = avl_insert(&root, 40);
    root = avl_insert(&root, 50);
    root = avl_insert(&root, 25);

    printf("In-order traversal of the AVL Tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Free the memory allocated for the AVL Tree
    freeAVLTree(root);

    return 0;
}
