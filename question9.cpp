#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        Node* current = front;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Item " << value << " inserted into the queue." << endl;
    }

    void del() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot delete." << endl;
        } else {
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            cout << "Item " << temp->data << " deleted from the queue." << endl;
            delete temp;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            Node* current = front;
            cout << "Queue: ";
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue queue;

    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. isEmpty\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (queue.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;

            case 2:
                cout << "Enter the value to insert into the queue: ";
                cin >> value;
                queue.insert(value);
                break;

            case 3:
                queue.del();
                break;

            case 4:
                queue.display();
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

