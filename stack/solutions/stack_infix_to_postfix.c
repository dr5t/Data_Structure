#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 
 * QUESTION: Infix to Postfix Conversion
 * A core stack problem for college exams.
 */

#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
};

void push(struct Stack* s, char c) { s->arr[++(s->top)] = c; }
char pop(struct Stack* s) { return s->arr[(s->top)--]; }
int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void infixToPostfix(char* exp) {
    struct Stack s; s.top = -1;
    int k = 0; char res[MAX];

    for (int i = 0; exp[i]; i++) {
        if (isalnum(exp[i])) {
            res[k++] = exp[i];
        } else if (exp[i] == '(') {
            push(&s, '(');
        } else if (exp[i] == ')') {
            while (s.top != -1 && s.arr[s.top] != '(') res[k++] = pop(&s);
            pop(&s);
        } else {
            while (s.top != -1 && prec(exp[i]) <= prec(s.arr[s.top])) res[k++] = pop(&s);
            push(&s, exp[i]);
        }
    }
    while (s.top != -1) res[k++] = pop(&s);
    res[k] = '\0';
    printf("Postfix Expression: %s\n", res);
}

int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    printf("Infix Expression: %s\n", exp);
    infixToPostfix(exp);
    return 0;
}
