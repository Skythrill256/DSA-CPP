#include<iostream>
using namespace std;

class PostfixEvaluator {
private:
    char expression[100];
    int stack[100];
    int top;

    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    void push(int value) {
        stack[++top] = value;
    }

    int pop() {
        return stack[top--];
    }

    int stringToInt(const char* str) {
        int result = 0;
        while (*str != '\0') {
            result = result * 10 + (*str - '0');
            str++;
        }
        return result;
    }

public:
    PostfixEvaluator() : top(-1) {}

    void setExpression(const char* postfixExpr) {
        int i = 0;
        while (postfixExpr[i] != '\0' && i < 99) {
            expression[i] = postfixExpr[i];
            i++;
        }
        expression[i] = '\0';
    }

    void allocateStack(int size) {
        // No dynamic allocation needed since stack is a fixed-size array
    }

    int evaluate() {
        int len = 0;
        while (expression[len] != '\0') {
            len++;
        }

        allocateStack(len);

        for (int i = 0; i < len; i++) {
            if (isdigit(expression[i])) {
                push(expression[i] - '0');
            } else if (isOperator(expression[i])) {
                int operand2 = pop();
                int operand1 = pop();
                switch (expression[i]) {
                    case '+':
                        push(operand1 + operand2);
                        break;
                    case '-':
                        push(operand1 - operand2);
                        break;
                    case '*':
                        push(operand1 * operand2);
                        break;
                    case '/':
                        push(operand1 / operand2);
                        break;
                }
            }
        }

        int result = pop();
        return result;
    }
};

int main() {
    PostfixEvaluator evaluator;
    char postfixExpr[100];

    cout << "Enter Postfix Expression: ";
    cin >> postfixExpr;

    evaluator.setExpression(postfixExpr);

    int result = evaluator.evaluate();

    cout << "Result: " << result << endl;

    return 0;
}

