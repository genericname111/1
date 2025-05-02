#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* top = NULL;
Node* top1 = NULL;
Node* top2 = NULL;

void push(Node** top_ptr, int val) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->val = val;
    ptr->next = *top_ptr;
    *top_ptr = ptr;
}

int pop(Node** top_ptr) {
    if (*top_ptr == NULL) {
        return -1;
    }
    Node* temp = *top_ptr;
    int val = temp->val;
    *top_ptr = (*top_ptr)->next;
    free(temp);
    return val;
}

int peek(Node* top_ptr) {
    if (top_ptr == NULL) {
        return -1;
    }
    return top_ptr->val;
}

int findmax(Node** top_ptr) {
    int max_val = -5555555;
    Node* current = *top_ptr;
    while (current != NULL) {
        if (current->val > max_val) {
            max_val = current->val;
        }
        current = current->next;
    }
    return max_val;
}

int main() {
    int data = 0;

    printf("Enter the first stack (-1 to end):\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) break;
        push(&top, data);
    }

    int max_val = findmax(&top);
    if (max_val != -5555555) {
        printf("Max element: %d\n", max_val);
    }
    else {
        printf("The stack is empty\n");
    }

    printf("Enter the second descending stack (-1 to end):\n");
    data = 0;
    while (1) {
        scanf("%d", &data);
        if (data == -1) break;
        if (peek(top) <= data || peek(top) == -1) {
            push(&top, data);
        }
        else {
            printf("The stack should be descending. Enter another number.\n");
        }
    }

    printf("Enter the third descending stack (-1 to end):\n");
    data = 0;
    while (1) {
        scanf("%d", &data);
        if (data == -1) break;
        if (peek(top1) <= data || peek(top1) == -1) {
            push(&top1, data);
        }
        else {
            printf("The stack should be descending. Enter another number.\n");
        }
    }


    while (peek(top) != -1 && peek(top1) != -1) {
        if (peek(top) > peek(top1)) {
            push(&top2, pop(&top));
        }
        else {
            push(&top2, pop(&top1));
        }
    }

    while (peek(top) != -1) {
        push(&top2, pop(&top));
    }
    while (peek(top1) != -1) {
        push(&top2, pop(&top1));
    }


    printf("Final stack:");
    while (peek(top2) != -1) {
        data = pop(&top2);
        printf(" %d", data);
    }
    printf("\n");

    return 0;
}
