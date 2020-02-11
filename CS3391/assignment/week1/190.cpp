#include <iostream>

#include <stack>

using namespace std;

int precedence(char c) {
    switch (c) {
    case '@':
        return -1;
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;

    return false;
}

int main() {
    int n;
    scanf("%i\n\n", & n);
    while (n--) {
        char eq[50];
        char pos[50];
        stack <char> s;
        int len = 0;

        s.push('@');

        while (~scanf("%c", &eq[len]) && eq[len] != '\n') {
            if(eq[len] != '\n')
                getchar();
            len++;
        }
        if(n > 0)
            scanf("\n\n");
        
        eq[len] = '\0';
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (eq[i] == ')') {
                while (!s.empty() && s.top() != '(') {
                    pos[j++] = s.top();
                    s.pop();
                }
                if (s.top() == '(') {
                    s.pop();
                }
            } else if (eq[i] == '(') {
                s.push('(');
            } else if (isOperator(eq[i])) {
                while (!s.empty() && precedence(eq[i]) <= precedence(s.top())) {
                    pos[j++] = s.top();
                    s.pop();
                }

                s.push(eq[i]);
            } else {
                pos[j++] = eq[i];
            }
        }

        while (!s.empty() && s.top() != '@') {
            pos[j++] = s.top();
            s.pop();
        }

        pos[j] = '\0';
        
        printf("%s\n", pos);
        if(n)
            printf("\n");
    }
    return 0;
}
