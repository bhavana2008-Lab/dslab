#include <stdio.h>
#include <stdlib.h>
struct node {
       int data;
       struct node* next;
};
struct node* createnode(int data){
     struct node* newnode = (struct node*)malloc(sizeof(struct node));
     if (newnode == NULL){
           printf("memory allocation failed\n");exit(1);
     }
     newnode->data = data;
     newnode->next = NULL; return newnode;
}
void insertend(struct node** head_ref, int new_data){
     struct node* new_node = createnode(new_data);
     if (*head_ref == NULL){
          *head_ref = new_node;
          new_node->next = *head_ref;
     }
     else{
         struct node* temp = *head_ref;
         while (temp->next != *head_ref){
         temp = temp->next;
         }
         temp->next = new_node;
         new_node->next  = *head_ref;
    }
  }  
  void printlist(struct node* head){
       if (head == NULL){
       printf("list is empty\n"); return;
       }
        struct node* temp = head;
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }while (temp != head);
        printf("\n");
  }
  void deleteNode(struct node** head_ref, int key){
        if (*head_ref == NULL){
             printf("list is empty\n");
             return;
        }
        struct node* temp =*head_ref, *prev = NULL;
        if (temp->data == key && temp->next == *head_ref){
              *head_ref = NULL;
              free(temp);
              return;
         }
         if (temp->data == key){
                while (temp->next != *head_ref){
                       temp = temp->next;
         }
         temp->next = (*head_ref)->next;
         free(*head_ref);
         *head_ref = temp->next;
         }
         else {
             while (temp->next != *head_ref && temp->data != key){
                    prev = temp;
                    temp = temp->next;
             }
             if (temp->data != key){
                   printf("key not found in the l;ist\n");return;
              }
        prev->next = temp->next; free(temp);
        }
      }
      int main(){
          struct node* head = NULL;
          int data, choice, key;
          do {
               printf("\n1. Insert at end");
               printf("\n2. Delete node");
               printf("\n3. Print list");
               printf("\n0. Exit\n");
               printf("Enter your choice:");
               scanf("%d", &choice);
               switch (choice){
                       case 1:
                            printf("Enter data to insert:");
                            scanf("%d", &data);
                            insertend(&head, data);
                            break;
                      case 2:
                          printf("Enter data to delete:");
                          scanf("%d", &key);
                          deleteNode(&head, key);
                          break;
                      case 3:
                          printf("Circular linked list:"); 
                          printlist(head);
                          break;
                    case 0:
                       printf("Exiting...\n");
                       break;
                    default:
                         printf("Invalid choice!\n");
                    }
                  } while(choice != 0);
                  struct node* current = head; if (current !=NULL){
                         struct node* temp; do{
                                temp = current;
                                current = current->next;
                                free(temp);
                      }while (current!=head);
                  }
                  return 0;
              }

           
