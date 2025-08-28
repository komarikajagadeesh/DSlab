#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node *next;
};

// Define queue structure
struct queue {
    struct node *front;
    struct node *rear;
};

// Function to enqueue (insert)
struct queue* insert_element(struct queue *q, int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        // Queue is empty
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    return q;
}

// Function to dequeue (delete)
struct queue* delete_element(struct queue *q) {
    struct node *ptr;

    if (q->front == NULL) {
        printf("\nUNDERFLOW - Queue is empty.");
    } else {
        ptr = q->front;
        q->front = q->front->next;
        printf("\nThe value being deleted is: %d", ptr->data);
        free(ptr);

        if (q->front == NULL) {
            // Queue is now empty
            q->rear = NULL;
        }
    }

    return q;
}

// Function to display queue
void display(struct queue *q) {
    struct node *ptr = q->front;

    if (ptr == NULL) {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nQueue elements: ");
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to peek (view front)
int peek(struct queue *q) {
    if (q->front == NULL) {
        printf("\nQUEUE IS EMPTY\n");
        return -1;
    } else {
        return q->front->data;
    }
}

// Main function to demonstrate
int main() {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;

    int choice, value;

    do {
        printf("\n\n*** Queue Menu ***\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                q = insert_element(q, value);
                break;
            case 2:
                q = delete_element(q);
                break;
            case 3:
                value = peek(q);
                if (value != -1)
                    printf("Front element is: %d\n", value);
                break;
            case 4:
                display(q);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(choice != 5);

    // Clean up memory
    while (q->front != NULL) {
        q = delete_element(q);
    }
    free(q);

    return 0;
}

