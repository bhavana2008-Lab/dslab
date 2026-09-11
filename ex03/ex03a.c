#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct stack {
    int arr[MAX];
    int top;
};
void initializestack(struct stack *stack){
      stack->top = -1;
      }
void push(struct stack *stack, int element){
    if (stack->top == (MAX - 1)){
       printf("Error:stack overflow. cannot push element.\n");
       return;
    }
    stack->arr[++stack->top] = element;
    printf("element pushed:%d\n",element);
}
int pop(struct stack *stack){
    if (stack->top == -1){
        printf("Error: stack underflow. cannot pop element.\n");
        return -1;
    } else {
        int poppedElement = stack->arr[stack->top--];
        printf("\npopped element:%d\n", poppedElement);
        return poppedElement;
   }
}
void displaystack(struct stack *stack){
    int i;
    if(stack->top == -1){
       printf("stack is empty .\n");
       return;
    }
    printf("stack elementd:");
    for (i = stack->top; i >=0; i--){
        printf("%d", stack->arr[i]);
    }
    printf("\n");
}
int main(){
    struct stack stack;
    int choice, element;
    initializestack(&stack);
    while (1){
         printf("\nStack operations menu:\n");
         printf("1. Push\n");
         printf("2. pop\n");
         printf("3. Display\n");
         printf("4. Exit\n");
         printf("Enter your choice:");
         scanf("%d", &choice);
        switch (choice){
           case 1:
              printf("Enter element to push:");
              scanf("%d" , &element);
              push(&stack, element);
              break;
          case 2:
              pop(&stack);
              break;
         case 3:
            displaystack(&stack);
            break;
        case 4:
           exit(0);
       default:
           printf("Invalid choice! please enter a valid optiom.\n");
    }
  }
  return 0;
} 
    

