#include <stdio.h>
#include <ctype.h>

/* 
 * QUESTION: Postfix Evaluation
 * Evaluate a postfix expression (e.g., "231*+9-").
 */

#define MAX 50

struct Stack {
    int top;
    int arr[MAX];
};

void push(struct Stack* s, int val) { s->arr[++(s->top)] = val; }
int pop(struct Stack* s) { return s->arr[(s->top)--]; }

int evaluatePostfix(char* exp) {
    struct Stack s; s.top = -1;

    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        } else {
            int val1 = pop(&s);
            int val2 = pop(&s);
            switch (exp[i]) {
                case '+': push(&s, val2 + val1); break;
                case '-': push(&s, val2 - val1); break;
                case '*': push(&s, val2 * val1); break;
                case '/': push(&s, val2 / val1); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char exp[] = "231*+9-";
    printf("Evaluation of %s is: %d\n", exp, evaluatePostfix(exp));
    return 0;
}
