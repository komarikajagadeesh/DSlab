#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for isdigit()
#include <string.h>

#define MAX 100

// Stack implementation
int stack[MAX];
int top = -1;

// Push element onto stack
void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top] = value;
}

// Pop element from stack
int pop() {
    if (top < 0) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack[top--];
}

// Evaluate a postfix expression
int evaluatePostfix(char* expr) {
    int i, op1, op2, result;
    char ch;

    for (i = 0; expr[i] != '\0'; i++) {
        ch = expr[i];

        if (isdigit(ch)) {
            // Convert char to int and push
            push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            op2 = pop();
            op1 = pop();

            switch (ch) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("Division by zero!\n");
                        exit(1);
                    }
                    result = op1 / op2;
                    break;
                default:
                    printf("Unsupported operator: %c\n", ch);
                    exit(1);
            }

            push(result);
        } else if (ch == ' ') {
            continue;  // skip spaces
        } else {
            printf("Invalid character in expression: %c\n", ch);
            exit(1);
        }
    }

    return pop();  // final result
}

// Main function
int main() {
    char expr[MAX];

    printf("Enter a postfix expression (e.g., 23*54*+): ");
    scanf("%s", expr);

    int result = evaluatePostfix(expr);
    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}

