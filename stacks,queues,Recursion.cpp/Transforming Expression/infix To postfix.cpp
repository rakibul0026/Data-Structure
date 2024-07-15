#include <stdio.h>

void pushopr(char);    
char popopr();          
char peepopr();          
void pushout(char);      
void displayopr();      
void displayout();       
int getpriority(char); 

char opr[25] = {'\0'};  
char out[25] = {'\0'};   
int topopr = -1;        
int topout = -1;         
char ch;

int main() {
    char infix[25] = {'\0'}, ele, popele;
    int i;
    printf("\nEnter infix Expression: ");
    scanf("%s", infix);
    printf("\nInfix Expression = %s\n", infix);
    
    i = 0;
    while (infix[i] != '\0') {
        ele = infix[i];
        if (ele == '(') {
            pushopr(ele);
        } else if (ele == ')') {
            while (topopr != -1 && peepopr() != '(') {
                popele = popopr();
                pushout(popele);
            }
            if (topopr != -1) {
                popopr(); 
            }
        } else if (ele == '^' || ele == '*' || ele == '/' || ele == '-' || ele == '+') {
            while (topopr != -1 && getpriority(peepopr()) >= getpriority(ele)) {
                popele = popopr();
                pushout(popele);
            }
            pushopr(ele);
        } else {
            pushout(ele); 
        }
        
        i++;
    }
    
    while (topopr != -1) {
        popele = popopr();
        pushout(popele);
    }
    
    printf("\nPostfix Expression = %s\n", out);
    return 0;
}

int getpriority(char ele) {
    switch (ele) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

void pushopr(char ele) {
    if (topopr == 24) {
        printf("\nOperator Stack is Full\n");
    } else {
        topopr++;
        opr[topopr] = ele;
    }
}

char popopr() {
    if (topopr != -1) {
        ch = opr[topopr];
        topopr--;
        return ch;
    }
    return '\0';
}

char peepopr() {
    if (topopr != -1) {
        return opr[topopr];
    }
    return '\0'; 
}

void pushout(char ele) {
    if (topout == 24) {
        printf("\nOutput Stack is Full\n");
    } else {
        topout++;
        out[topout] = ele;
    }
}

void displayopr() {
    int i;
    printf("\nOperator Stack =");
    for (i = 0; i <= topopr; i++) {
        printf(" |%c", opr[i]);
    }
    printf("\n");
}

void displayout() {
    int i;
    printf("\nOutput Stack =");
    for (i = 0; i <= topout; i++) {
        printf(" |%c", out[i]);
    }
    printf("\n");
}
