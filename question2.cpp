#include<iostream>
using namespace std;

class Queue {
private:
    int front, rear, maxSize;
    int* arr;

public:
    Queue(int size) {
        maxSize = size;
        arr = new int[maxSize];
        front = rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isFull() {
        return (rear == maxSize - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void insert(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert." << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        arr[++rear] = item;
        cout << "Element " << item << " inserted into the Queue." << endl;
    }

    void remove() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot delete." << endl;
            return;
        }

        int deletedItem = arr[front++];
        cout << "Element " << deletedItem << " removed from the Queue." << endl;

        if (front > rear) {
            front = rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int maxSize;
    cout << "Enter the size of the Queue: ";
    cin >> maxSize;

    Queue queue(maxSize);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int item;
                cout << "Enter the element to insert: ";
                cin >> item;
                queue.insert(item);
                break;

            case 2:
                queue.remove();
                break;

            case 3:
                queue.display();
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

