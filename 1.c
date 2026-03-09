#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack {
    int items[MAX];
    int top;
};

// Initialize stack top to -1 (empty)
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// PUSH: Add element to top
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->top++;
        s->items[s->top] = value;
        printf("Pushed: %d\n", value);
    }
}

// POP: Remove and return top element
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Nothing to pop.\n");
        return -1;
    } else {
        int poppedValue = s->items[s->top];
        s->top--;
        return poppedValue;
    }
}

int main() {
    struct Stack s;
    initStack(&s);

    // Demonstration
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));

    push(&s, 40);
    
    printf("Current Top Index: %d\n", s.top);

    return 0;
}
