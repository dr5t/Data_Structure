#include <stdio.h>
#include <stdbool.h>

/* 
 * QUESTION: Balanced Parentheses
 * Check if the parentheses in an expression are balanced using a stack.
 */

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

void push(struct Stack* s, char c) {
    s->arr[++(s->top)] = c;
}

char pop(struct Stack* s) {
    return s->arr[(s->top)--];
}

bool isBalanced(char* exp) {
    struct Stack s;
    s.top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(&s, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (s.top == -1) return false;
            char top = pop(&s);
            if ((exp[i] == ')' && top != '(') ||
                (exp[i] == '}' && top != '{') ||
                (exp[i] == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.top == -1;
}

int main() {
    char exp1[] = "{[()]}";
    char exp2[] = "{[(])}";

    if (isBalanced(exp1)) printf("Expression '%s' is balanced.\n", exp1);
    else printf("Expression '%s' is not balanced.\n", exp1);

    if (isBalanced(exp2)) printf("Expression '%s' is balanced.\n", exp2);
    else printf("Expression '%s' is not balanced.\n", exp2);

    return 0;
}
