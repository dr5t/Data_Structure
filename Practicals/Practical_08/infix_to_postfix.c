/*
 * Practical_08: Infix to Postfix Expression Conversion
 * Supports: +  -  *  /  %  ^  and alphanumeric operands
 * Handles both parenthesized and free-parenthesized expressions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

/* ────────────────────────── Operator Stack ────────────────────────────── */

char stack[MAX];
int  top = -1;

void  push(char c)     { stack[++top] = c; }
char  pop(void)        { return stack[top--]; }
char  peek(void)       { return top == -1 ? '#' : stack[top]; }
int   isEmpty(void)    { return top == -1; }

/* ────────────────────────── Precedence Table ──────────────────────────── */

int precedence(char op)
{
    switch (op) {
        case '^': return 3;  /* right-associative, highest */
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' ||
           c == '/' || c == '%' || c == '^';
}

/* ────────────────────────── Conversion Algorithm ─────────────────────── */

/*
 * Algorithm (Shunting-Yard by Dijkstra):
 * 1. Scan infix left to right.
 * 2. Operand → append to postfix.
 * 3. '(' → push onto stack.
 * 4. ')' → pop & append until '(' found; discard both parentheses.
 * 5. Operator op:
 *      While stack not empty AND peek has higher/equal precedence
 *      AND (op is NOT right-associative OR peek has strictly higher prec):
 *          pop & append.
 *      Push op.
 * 6. End of infix → pop & append all remaining operators.
 */

void infixToPostfix(const char *infix, char *postfix)
{
    int k = 0;
    top   = -1;   /* reset stack */

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (c == ' ') continue;   /* skip spaces */

        if (isalnum(c)) {         /* operand */
            postfix[k++] = c;
            postfix[k++] = ' ';
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (peek() != '(') postfix[k++] = pop(), postfix[k++] = ' ';
            pop();  /* discard '(' */
        } else if (isOperator(c)) {
            /* For '^' (right-assoc) pop only if strictly higher precedence */
            while (!isEmpty() && peek() != '(' &&
                   ( (c != '^' && precedence(peek()) >= precedence(c)) ||
                     (c == '^' && precedence(peek()) >  precedence(c)) )) {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            push(c);
        } else {
            printf("  Warning: Unknown character '%c' skipped.\n", c);
        }
    }

    /* Pop remaining operators */
    while (!isEmpty()) { postfix[k++] = pop(); postfix[k++] = ' '; }
    if (k > 0 && postfix[k-1] == ' ') k--;  /* trim trailing space */
    postfix[k] = '\0';
}

/* ────────────────────────── Step-by-step Trace ────────────────────────── */

void traceConversion(const char *infix)
{
    char postfix[MAX * 2];

    printf("\n  Infix Expression  : %s\n", infix);

    /* Trace table */
    printf("\n  %-6s %-12s %-25s %-25s\n",
           "Step", "Symbol", "Stack", "Postfix");
    printf("  %-6s %-12s %-25s %-25s\n",
           "────", "──────", "─────────────────────────", "─────────────────────────");

    int k = 0, step = 1;
    char postBuf[MAX * 2] = {0};
    int  pb = 0;
    top = -1;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (c == ' ') continue;

        char stackStr[MAX * 2] = {0};
        int  ss = 0;
        for (int s = 0; s <= top; s++) stackStr[ss++] = stack[s];
        stackStr[ss] = '\0';

        if (isalnum(c)) {
            postBuf[pb++] = c; postBuf[pb++] = ' '; postBuf[pb] = '\0';
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (peek() != '(') { postBuf[pb++] = pop(); postBuf[pb++] = ' '; }
            pop();
        } else if (isOperator(c)) {
            while (!isEmpty() && peek() != '(' &&
                   ( (c != '^' && precedence(peek()) >= precedence(c)) ||
                     (c == '^' && precedence(peek()) >  precedence(c)) )) {
                postBuf[pb++] = pop(); postBuf[pb++] = ' ';
            }
            push(c);
        }
        postBuf[pb] = '\0';
        printf("  %-6d %-12c %-25s %-25s\n", step++, c, stackStr, postBuf);
    }

    while (!isEmpty()) {
        postBuf[pb++] = pop(); postBuf[pb++] = ' '; postBuf[pb] = '\0';
        printf("  %-6d %-12s %-25s %-25s\n", step++, "(pop)", "", postBuf);
    }
    if (pb > 0 && postBuf[pb-1] == ' ') postBuf[--pb] = '\0';

    printf("\n  Postfix Expression : %s\n", postBuf);
}

/* ────────────────────────── Main ─────────────────────────────────────── */

int main(void)
{
    char infix[MAX], postfix[MAX * 2];
    int  choice;

    printf("\n═══════════════════════════════════════════════════════\n");
    printf("   Practical_08 : Infix to Postfix Converter          \n");
    printf("   Operators supported: + - * / %% ^ ( )              \n");
    printf("═══════════════════════════════════════════════════════\n");

    do {
        printf("\n┌─────────────────────────────────────────────┐\n");
        printf("│               MAIN MENU                     │\n");
        printf("├─────────────────────────────────────────────┤\n");
        printf("│  1. Convert Infix to Postfix (result only)  │\n");
        printf("│  2. Convert with Step-by-step Trace         │\n");
        printf("│  3. Run built-in test cases                 │\n");
        printf("│  0. Exit                                    │\n");
        printf("└─────────────────────────────────────────────┘\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  /* consume newline */

        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                fgets(infix, MAX, stdin);
                infix[strcspn(infix, "\n")] = '\0';
                infixToPostfix(infix, postfix);
                printf("\n  Postfix: %s\n", postfix);
                break;

            case 2:
                printf("Enter infix expression: ");
                fgets(infix, MAX, stdin);
                infix[strcspn(infix, "\n")] = '\0';
                traceConversion(infix);
                break;

            case 3:
                printf("\n── Built-in Test Cases ─────────────────────────\n");
                {
                    const char *tests[] = {
                        "a+b*c",
                        "(a+b)*c",
                        "a+b*c-d/e",
                        "a^b^c",
                        "(a+b)*(c-d)/e+f",
                        "a*b+c*d-e%f",
                        NULL
                    };
                    for (int t = 0; tests[t]; t++) {
                        infixToPostfix(tests[t], postfix);
                        printf("  Infix : %-25s  Postfix : %s\n", tests[t], postfix);
                    }
                }
                break;

            case 0: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
