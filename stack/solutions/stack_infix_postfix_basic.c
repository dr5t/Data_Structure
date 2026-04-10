#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * QUESTION: Write a program to convert an infix expression to a postfix expression.
 * 
 * ALGORITHM:
 * 1. Scan the infix expression from left to right.
 * 2. If the character is an operand, add it to the output.
 * 3. If it's '(', push it to stack.
 * 4. If it's ')', pop and add to output until '(' is found.
 * 5. If it's an operator, pop from stack until an operator with lower precedence is found at top.
 */

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char exp[100];
    char *e, x;
    printf("Enter infix expression: ");
    scanf("%s", exp);
    printf("Postfix expression: ");
    e = exp;

    while (*e != '\0') {
        if (isalnum(*e)) {
            printf("%c", *e);
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }

    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}
