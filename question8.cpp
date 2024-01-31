#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        Node* current = top;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Item " << value << " pushed onto the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
        } else {
            Node* temp = top;
            top = top->next;
            cout << "Item " << temp->data << " popped from the stack." << endl;
            delete temp;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            Node* current = top;
            cout << "Stack: ";
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;

    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. isEmpty\n";
        cout << "2. Push\n";
        cout << "3. Pop\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (stack.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;

            case 2:
                cout << "Enter the value to push onto the stack: ";
                cin >> value;
                stack.push(value);
                break;

            case 3:
                stack.pop();
                break;

            case 4:
                stack.display();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}

