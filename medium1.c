#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        root->right = insert(root->right, value);
    }

    return root;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    return root;
}

// Function to free the memory allocated for the tree nodes
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int n, value;

    // Input the number of nodes in the tree
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);

    // Input the values of the nodes
    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Input the values for nodes p and q
    int pVal, qVal;
    printf("Enter the value of node p: ");
    scanf("%d", &pVal);
    printf("Enter the value of node q: ");
    scanf("%d", &qVal);

    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->val = pVal;
    p->left = p->right = NULL;

    struct TreeNode* q = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    q->val = qVal;
    q->left = q->right = NULL;

    // Find and print the lowest common ancestor
    struct TreeNode* result = lowestCommonAncestor(root, p, q);
    printf("Lowest Common Ancestor: %d\n", result->val);

    // Free the memory allocated for the tree nodes
    freeTree(root);
    free(p);
    free(q);

    return 0;
}
