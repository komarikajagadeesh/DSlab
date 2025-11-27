#include <stdio.h>
#include <stdlib.h>

// Define BST Node
struct Node {
    int key;
    struct Node *left, *right;
};

// Create a new node
struct Node* newNode(int item) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
struct Node* insertElement(struct Node* root, int key) {
    if (root == NULL)
        return newNode(key);
    if (key < root->key)
        root->left = insertElement(root->left, key);
    else if (key > root->key)
        root->right = insertElement(root->right, key);
    return root;
}

// Search for an element in BST
struct Node* searchElement(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return searchElement(root->left, key);
    else
        return searchElement(root->right, key);
}

int main() {
    struct Node* tree = NULL;
    struct Node* ptr;
    int choice, val;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. Search\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                tree = insertElement(tree, val);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &val);
                ptr = searchElement(tree, val);
                if (ptr)
                    printf("Element %d found in the tree.\n", val);
                else
                    printf("Element %d not found in the tree.\n", val);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


