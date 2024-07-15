
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void push(char*);    
char* pop();        

char stack[25][25];  
int top = -1;       

int main() {
    char postfix[25] = {'\0'};
    printf("\nEnter postfix Expression: ");
    scanf("%s", postfix);
    printf("\nPostfix Expression = %s\n", postfix);
    
    for (int i = 0; i < strlen(postfix); i++) {
        char ele = postfix[i];
        if (isalnum(ele)) {
           
            char operand[2] = {ele, '\0'};
            push(operand);
        } else {
           char op2[25];
            char op1[25];
            strcpy(op2, pop());
            strcpy(op1, pop());
            
            char temp[50] = {'\0'};
            strcat(temp, "(");
            strcat(temp, op1);
            strcat(temp, &ele);
            strcat(temp, op2);
            strcat(temp, ")");
            
            push(temp);
        }
    }
    
    printf("\nInfix Expression = %s\n", stack[0]);
    return 0;
}

void push(char* str) {
    if (top == 24) {
        printf("\nStack is Full\n");
    } else {
        top++;
        strcpy(stack[top], str);
    }
}

char* pop() {
    if (top != -1) {
        return stack[top--];
    }
    return NULL;
}
