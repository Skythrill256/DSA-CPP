#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    ~CircularLinkedList() {
        if (head == nullptr) return;

        Node* current = head->next;
        while (current != head) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        delete head;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            newNode->next = head->next;
            head->next = newNode;
        }
        cout << "Node with value " << value << " inserted at the beginning." << endl;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from the end." << endl;
        } else if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* current = head->next;
            Node* prev = nullptr;

            while (current->next != head) {
                prev = current;
                current = current->next;
            }

            prev->next = head;
            delete current;
            cout << "Node deleted from the end." << endl;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Circular Linked List is empty." << endl;
        } else {
            Node* current = head->next;
            cout << "Circular Linked List: " << head->data << " ";
            while (current != head) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    CircularLinkedList circularList;

    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Delete from the end\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                circularList.insertAtBeginning(value);
                break;

            case 2:
                circularList.deleteAtEnd();
                break;

            case 3:
                circularList.display();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

