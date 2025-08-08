#include <stdio.h>
#include <ctype.h>

char stack[30];
int top = -1;

int priority(char op) {
    if (op == '^') 
        return 3;
    if (op == '*' || op == '/') 
        return 2;
    if (op == '+' || op == '-') 
        return 1;
    return 0;
}

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

void main() {
    char exp[30], ch;
    int i;
    
    printf("Enter the expression: ");
    scanf("%s", exp);
    
    for (i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i])) 
            printf("%c", exp[i]);
        else if (exp[i] == '(') 
            push(exp[i]);
        else if (exp[i] == ')') {
            while ((ch = pop()) != '(')
                printf("%c", ch);
        } else {
            while (priority(stack[top]) >= priority(exp[i])) {
                printf("%c", pop());
            }
            push(exp[i]);
        }
    }

    while (top != -1)
        printf("%c", pop());
}
