#include<iostream>
using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int value, int p) : data(value), priority(p), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() : front(nullptr) {}

    ~PriorityQueue() {
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

    void insert(int value, int priority) {
        Node* newNode = new Node(value, priority);
        if (isEmpty() || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* current = front;
            while (current->next != nullptr && priority <= current->next->priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        cout << "Item " << value << " with priority " << priority << " inserted into the priority queue." << endl;
    }

    void del() {
        if (isEmpty()) {
            cout << "Priority Queue is empty. Cannot delete." << endl;
        } else {
            Node* temp = front;
            front = front->next;
            cout << "Item " << temp->data << " with priority " << temp->priority << " deleted from the priority queue." << endl;
            delete temp;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty." << endl;
        } else {
            Node* current = front;
            cout << "Priority Queue: ";
            while (current != nullptr) {
                cout << "(" << current->data << ", " << current->priority << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    PriorityQueue priorityQueue;

    int choice, value, priority;

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
                if (priorityQueue.isEmpty()) {
                    cout << "Priority Queue is empty." << endl;
                } else {
                    cout << "Priority Queue is not empty." << endl;
                }
                break;

            case 2:
                cout << "Enter the value to insert into the priority queue: ";
                cin >> value;
                cout << "Enter the priority of the item: ";
                cin >> priority;
                priorityQueue.insert(value, priority);
                break;

            case 3:
                priorityQueue.del();
                break;

            case 4:
                priorityQueue.display();
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

