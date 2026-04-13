#include <stdio.h>
#include <stdlib.h>

// TreeNode structure
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert (simple level-order insertion)
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    // Use queue for level-order insertion
    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = createNode(data);
            return root;
        } else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = createNode(data);
            return root;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}

// Pre-order traversal
void pre_order_traversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);           // Visit root
    pre_order_traversal(root->left);     // Left
    pre_order_traversal(root->right);    // Right
}

// Main function
int main() {
    struct TreeNode* root = NULL;

    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    printf("Pre-order traversal: ");
    pre_order_traversal(root);

    return 0;
}