#include<iostream>
using namespace std;

class InfixToPostfixConverter {
private:
    char stack[100];
    int top;
    string postfixExpression;

    int getPrecedence(char op) {
        switch (op) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            default:
                return 0;
        }
    }

    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    void push(char ch) {
        stack[++top] = ch;
    }

    char pop() {
        return stack[top--];
    }

public:
    InfixToPostfixConverter() : top(-1) {}

    void convertToPostfix(const string& infixExpression) {
        for (char ch : infixExpression) {
            if (isalnum(ch)) {
                postfixExpression += ch;
            } else if (ch == '(') {
                push(ch);
            } else if (ch == ')') {
                while (top != -1 && stack[top] != '(') {
                    postfixExpression += pop();
                }
                if (top != -1 && stack[top] == '(') {
                    pop(); // Pop '('
                }
            } else if (isOperator(ch)) {
                while (top != -1 && getPrecedence(ch) <= getPrecedence(stack[top])) {
                    postfixExpression += pop();
                }
                push(ch);
            }
        }

        while (top != -1) {
            postfixExpression += pop();
        }
    }

    void displayPostfixExpression() {
        cout << "Postfix Expression: " << postfixExpression << endl;
    }
};

int main() {
    InfixToPostfixConverter converter;
    string infixExpression;

    cout << "Enter Infix Expression: ";
    cin >> infixExpression;

    converter.convertToPostfix(infixExpression);
    converter.displayPostfixExpression();

    return 0;
}

