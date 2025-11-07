/*
Beginning with an empty binary search tree, Construct a binary search tree by inserting
the values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every node
v. Search a value
*/
#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to count the longest path (height of tree)
int longestPath(struct node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = longestPath(root->left);
    int rightHeight = longestPath(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to find minimum value in BST
int findMin(struct node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return -1;
    }

    while (root->left != NULL)
        root = root->left;

    return root->data;
}

// Function to mirror the tree (swap left and right pointers)
void mirrorTree(struct node* root) {
    if (root == NULL)
        return;

    // Swap left and right
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Mirror left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Function to search for a value in BST
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Function for inorder traversal (to display tree)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct node* root = NULL;
    int choice, value;

    printf("🌳 Binary Search Tree Operations 🌳\n");

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert a node\n");
        printf("2. Display (Inorder Traversal)\n");
        printf("3. Find number of nodes in longest path\n");
        printf("4. Find minimum data value\n");
        printf("5. Mirror (Swap left and right)\n");
        printf("6. Search a value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("✅ Node inserted!\n");
            break;

        case 2:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("📏 Longest path (height) = %d\n", longestPath(root));
            break;

        case 4:
            printf("🔹 Minimum value in tree = %d\n", findMin(root));
            break;

        case 5:
            mirrorTree(root);
            printf("🌿 Tree has been mirrored!\n");
            break;

        case 6:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value))
                printf("✅ Value %d found in the tree!\n", value);
            else
                printf("❌ Value %d not found in the tree.\n", value);
            break;

        case 7:
            printf("👋 Exiting... Thank you!\n");
            return 0;

        default:
            printf("⚠️ Invalid choice. Try again!\n");
        }
    }

    return 0;
}

