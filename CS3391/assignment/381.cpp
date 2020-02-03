#include <iostream>
#include <sstream>
#include <string>
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

int toDec(string c) {
    int res;
    std::stringstream sstream;
    sstream << std::hex << c;
    sstream >> res;
    
    return res;
}

string toHex(int c) {
    std::stringstream sstream;
    sstream << std::hex << c;
    return sstream.str();
}

string eval(string a, string b, char op) {
    if(op == '+') {
        int res = toDec(a) + toDec(b);
        return toHex(res);
    }else{
        int res = toDec(a) * toDec(b);
        return toHex(res);
    }
}

int main()
{
    string str;
    while(cin >> str && !cin.eof()) {
        stack<string> oprands;
        stack<char> s;
        s.push('@');
        int len = str.length();
        
        for (int i = 0; i < len; i++) {
            if (str[i] == ')') {
                while (!s.empty() && oprands.size() >= 2 && s.top() != '(') {
                    string op1 = oprands.top(); oprands.pop();
                    string op2 = oprands.top(); oprands.pop();
                    oprands.push(eval(op1, op2, s.top()));
                    s.pop();
                }
                if (s.top() == '(') {
                    s.pop();
                }
            } else if (str[i] == '(') {
                s.push('(');
            } else if (isOperator(str[i])) {
                while (!s.empty() && oprands.size() >= 2 && precedence(str[i]) <= precedence(s.top())) {
                    string op1 = oprands.top(); oprands.pop();
                    string op2 = oprands.top(); oprands.pop();
                    oprands.push(eval(op1, op2, s.top()));
                    
                    s.pop();
                }

                s.push(str[i]);
            } else {
                string op1;
                op1 += str[i];
                oprands.push(op1);
            }
        }

        while (!s.empty() && oprands.size() >= 2 && s.top() != '@') {
            string op1 = oprands.top(); oprands.pop();
            string op2 = oprands.top(); oprands.pop();
            oprands.push(eval(op1, op2, s.top()));
            s.pop();
        }
        
       cout << oprands.top() << endl;
    }

    return 0;
}
