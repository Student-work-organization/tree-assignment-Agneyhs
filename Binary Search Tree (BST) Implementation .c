#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

void in_order_traversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    in_order_traversal(root->left);
    printf("%d ", root->data);
    in_order_traversal(root->right);
}

void post_order_traversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    post_order_traversal(root->left);
    post_order_traversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct TreeNode* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder Traversal: ");
    in_order_traversal(root);

    printf("\nPostorder Traversal: ");
    post_order_traversal(root);

    return 0;
}