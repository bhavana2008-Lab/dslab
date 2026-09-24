#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


void insertEnd(struct Node **head_ref, int data) {
    struct Node *newNode = createNode(data);

    if (*head_ref == NULL) {
        *head_ref = newNode;
        newNode->next = *head_ref;
        return;
    }

    struct Node *temp = *head_ref;

    while (temp->next != *head_ref) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head_ref;
}


void deleteNode(struct Node **head_ref, int key) {
    if (*head_ref == NULL) {
        printf("Error: List is empty.\n");
        return;
    }

    struct Node *temp = *head_ref;
    struct Node *prev = NULL;

    
    if (temp->data == key && temp->next == *head_ref) {
        *head_ref = NULL;
        free(temp);
        return;
    }

    
    if (temp->data == key) {
        while (temp->next != *head_ref) {
            temp = temp->next;
        }

        struct Node *head_ref_temp = *head_ref;
        temp->next = head_ref_temp->next;
        *head_ref = head_ref_temp->next;
        free(head_ref_temp);
        return;
    }

    temp = *head_ref;

    while (temp->next != *head_ref &&
           temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next->data != key) {
        printf("Key not found in the list\n");
        return;
    }

    struct Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);

void printList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int data, choice, key;

    do {
        printf("\n1. Insert at End");
        printf("\n2. Delete Node");
        printf("\n3. Print List"); 
        printf("\n0. Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch(choice){

            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;

            case 3:
                printf("Circular Linked List: ");
                printList(head);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    /* Free memory */
    if (head != NULL) {
        struct Node *current = head->next;
        while (current != head) {
            struct Node *temp = current;
            current = current->next;
            free(temp);
        }
        free(head);
    }

    return 0;
}