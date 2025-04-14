#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* top = NULL;

struct Node1 {
    int val;
    struct Node1* next;
};
struct Node1* top1 = NULL;

struct Node2 {
    int val;
    struct Node2* next;
};
struct Node2* top2 = NULL;

void push(int val) {

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));

    ptr->val = val;
    if (top == NULL) {
        ptr->next = NULL;  
        top = ptr;        
    }
    else {
      
        ptr->next = top; 
      top = ptr;       
    }

   
}

void push1(int val) {

    struct Node1* ptr = (struct Node1*)malloc(sizeof(struct Node1));
    
    ptr->val = val;
    if (top1 == NULL) {
        ptr->next = NULL;
        top1 = ptr;
    }
    else {

        ptr->next = top1;
        top1 = ptr;
    }


}
void push2(int val) {

    struct Node2* ptr = (struct Node2*)malloc(sizeof(struct Node2));

    ptr->val = val;
    if (top2 == NULL) {
        ptr->next = NULL;
        top2 = ptr;
    }
    else {

        ptr->next = top2;
        top2 = ptr;
    }


}
int pop() {
   
    if (top == NULL) {
      
        return; 
    }

    
    struct Node* temp1 = top;   
    int temp = top->val;      

    top = top->next;


    free(temp1);

    return temp;
}
int pop1() {

    if (top1 == NULL) {
        
        return;
    }


    struct Node1* temp1 = top1;
    int temp = top1->val;

    top1 = top1->next;


    free(temp1);

    return temp;
}
int pop2() {

    if (top2 == NULL) {
        
        return -1;
    }


    struct Node2* temp1 = top2;
    int temp = top2->val;

    top2 = top2->next;


    free(temp1);

    return temp;
}

int peek()
{

    if (top == NULL) {
       
        return -1;
    }


    struct Node* temp1 = top;
    int temp = top->val;


    return temp;
}
int peek1()
{

    if (top1 == NULL) {

        return -1;
    }


    struct Node1* temp1 = top1;
    int temp = top1->val;


    return temp;
}

int peek2()
{

    if (top2 == NULL) {

        return -1;
    }


    struct Node2* temp1 = top2;
    int temp = top2->val;


    return temp;
}


int findmax() {
    int temp;
    int mx = -3543345;
    while (top != NULL)
    {
        temp = pop();
        if (mx < temp)
            mx = temp;
    }
    return mx;
}


int main() {
    int data = 0;
    printf("Enter the first stack(-1 to end)\n");
        while (data != -1)
        {
            scanf("%d", &data);
            push(data);
        }
        data = pop();
        data = findmax();
        if(data != -3543345)
            printf("max element: %d\n", data);
        else
            printf("the stack is empty\n");
            printf("Enter the second decending stack(-1 to end)\n");
            while (data != -1)
            {
                scanf("%d", &data);
                if (peek() <= data || peek() == -1 || data == -1)
                    push(data);
                else
                    printf("the stack should be descending enter another number\n");
            }
            data = pop();
            data = 0;
            printf("Enter the third decending stack(-1 to end)\n");
            while (data != -1)
            {
                scanf("%d", &data);
                if (peek1() <= data || peek1() == -1 || data == -1)
                    push1(data);
                else
                    printf("the stack should be descending enter another number\n");
            }
            data = pop1();
            while (top != NULL && top1 != NULL)
            {
                if (peek() > peek1())
                    push2(pop());
                else
                    push2(pop1());
            }
            if (top == NULL)
                while (peek1() != -1)
                    push2(pop1());
            else
                while (peek() != -1)
                    push2(pop());
            printf("final stack:");
            while (peek2() != -1) {
                data = pop2();
                printf(" %d", data);
            }
          return 0;
}
