#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode {
    int data;  // Assuming data represents some identifier (e.g., name or ID)
    struct TreeNode* children;  // Pointer to the first child
    struct TreeNode* sibling;   // Pointer to the next sibling
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->children = NULL;
    newNode->sibling = NULL;
    return newNode;
}

// Function to insert a child to a tree node
void insertChild(struct TreeNode* parent, int value) {
    struct TreeNode* newChild = createNode(value);
    newChild->sibling = parent->children;
    parent->children = newChild;
}

// Function to check if a node is a common member
int isCommonMember(struct TreeNode* tree1, struct TreeNode* tree2) {
    if (tree1 == NULL || tree2 == NULL)
        return 0;

    if (tree1->data == tree2->data)
        return 1;

    // Check children and siblings
    return isCommonMember(tree1->children, tree2) || isCommonMember(tree1->sibling, tree2);
}

int main() {
    // Create and populate tree1
    struct TreeNode* tree1 = createNode(1);
    insertChild(tree1, 2);
    insertChild(tree1, 3);
    insertChild(tree1, 4);

    // Create and populate tree2
    struct TreeNode* tree2 = createNode(5);
    insertChild(tree2, 6);
    insertChild(tree2, 7);
    insertChild(tree2, 3);  // Common member with tree1

    // Check if common members exist
    if (isCommonMember(tree1, tree2)) {
        printf("Common members exist in the two trees.\n");
    } else {
        printf("No common members found in the two trees.\n");
    }

    // Clean up memory (free nodes)

    return 0;
}

