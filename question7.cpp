#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Node with value " << value << " inserted at the beginning." << endl;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Node with value " << value << " inserted at the end." << endl;
    }

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from the beginning." << endl;
        } else {
            Node* temp = head;
            head = head->next;
            cout << "Node with value " << temp->data << " deleted from the beginning." << endl;
            delete temp;
        }
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from the end." << endl;
        } else if (head->next == nullptr) {
            // Only one node in the list
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            Node* prev = nullptr;

            while (current->next != nullptr) {
                prev = current;
                current = current->next;
            }

            prev->next = nullptr;
            cout << "Node with value " << current->data << " deleted from the end." << endl;
            delete current;
        }
    }

    void display() {
        Node* current = head;
        cout << "Linked List: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;

    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Delete from the beginning\n";
        cout << "4. Delete from the end\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                linkedList.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter the value to insert: ";
                cin >> value;
                linkedList.insertAtEnd(value);
                break;

            case 3:
                linkedList.deleteAtBeginning();
                break;

            case 4:
                linkedList.deleteAtEnd();
                break;

            case 5:
                linkedList.display();
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}

