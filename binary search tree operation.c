#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
//create node
struct Node* createNode(int value)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode -> data = value;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}

// insert node
struct Node* insert(struct Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// inorder traversal ( left ? root ? right)
void inorder(struct Node* root)
{
	if(root != NULL)
	{
		inorder(root -> left);
		printf("%d ",root -> data);
		inorder(root -> right);
	}
}

// preorder traversal (right ? left ? righ)
void preorder(struct Node* root)
{
	if(root != NULL)
	{
		printf("%d ",root -> data);
		preorder(root -> left);
		preorder(root -> right);
	}
}

// post order traversal (left ? right? root)
void postorder(struct Node* root)
{
	if(root != NULL)
	{
		postorder(root -> left);
		postorder(root -> right);
		printf("%d ",root -> data);
	}
}

//smallest Node
struct Node* smallnode(struct Node* root)
{
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

//largest Node
struct Node* largenode(struct Node* root)
{
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

//Delete Node
struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
        
// Node with one child or no child
   
    else {
        
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
// Node with two children
        struct Node* temp = smallnode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

  // total no.of nodes
int countNodes(struct Node* root)
{
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// total external nodes (leaf nodes)
int ExternalNodes(struct Node* root)
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return ExternalNodes(root->left) + ExternalNodes(root->right);
}

// Total internal nodes (non-leaf nodes)
int InternalNodes(struct Node* root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL)) 
        return 0;
    return 1 + InternalNodes(root->left) + InternalNodes(root->right);
}

// Total height of the tree
int height(struct Node* root)
{
    if (root == NULL) return -1;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}

// Delete entire tree
void deleteTree(struct Node* root)
{
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

//options	
int main()
{
    struct Node* root = NULL;
    int choice, value;
    root = createNode(4);
	root -> left = createNode(2);
	root -> right = createNode(6);
	root -> left -> left = createNode(1);
	root -> left -> right = createNode(3);
	root -> right -> left = createNode(5);
	root -> right -> right = createNode(7);
	
    do {
        printf("\n= Binary Search Tree Menu =\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Smallest Node\n");
        printf("6. Largest Node\n");
        printf("7. Delete Node\n");
        printf("8. Total Nodes\n");
        printf("9. Total Internal Nodes\n");
        printf("10. Total External Nodes\n");
        printf("11. Height of Tree\n");
        printf("12. Delete Entire Tree\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                if (root) 
                    printf("Smallest Node: %d\n", smallnode(root)->data);
                else 
                    printf("Tree is empty.\n");
                break;
            case 6:
                if (root) 
                    printf("Largest Node: %d\n", largenode(root)->data);
                else 
                    printf("Tree is empty.\n");
                break;
            case 7:
                printf("Enter node value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 8:
                printf("Total Nodes: %d\n", countNodes(root));
                break;
            case 9:
                printf("Total Internal Nodes: %d\n", InternalNodes(root));
                break;
            case 10:
                printf("Total External Nodes: %d\n", ExternalNodes(root));
                break;
            case 11:
                printf("Height of Tree: %d\n", height(root));
                break;
            case 12:
                deleteTree(root);
                root = NULL;
                printf("Tree deleted.\n");
                break;
            case 13:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 13);

    return 0;
}
