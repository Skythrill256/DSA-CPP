#include<iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, maxSize;
    int* arr;

public:
    CircularQueue(int size) {
        maxSize = size;
        arr = new int[maxSize];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isFull() {
        return ((front == 0 && rear == maxSize - 1) || (rear == front - 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insert(int item) {
        if (isFull()) {
            cout << "Circular Queue is full. Cannot insert." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == maxSize - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = item;
        cout << "Element " << item << " inserted into the Circular Queue." << endl;
    }

    void remove() {
        if (isEmpty()) {
            cout << "Circular Queue is empty. Cannot delete." << endl;
            return;
        }

        int deletedItem = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else if (front == maxSize - 1) {
            front = 0;
        } else {
            front++;
        }

        cout << "Element " << deletedItem << " removed from the Circular Queue." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is empty." << endl;
            return;
        }

        cout << "Circular Queue elements: ";
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < maxSize; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int maxSize;
    cout << "Enter the size of the Circular Queue: ";
    cin >> maxSize;

    CircularQueue circularQueue(maxSize);

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
                circularQueue.insert(item);
                break;

            case 2:
                circularQueue.remove();
                break;

            case 3:
                circularQueue.display();
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

