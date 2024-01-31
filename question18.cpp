#include<iostream>
using namespace std;

class InsertionSort {
private:
    int* array;
    int size;
    int comparisonCount;

public:
    InsertionSort(int arr[], int n) : size(n), comparisonCount(0) {
        array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = arr[i];
        }
    }

    ~InsertionSort() {
        delete[] array;
    }

    void sort() {
        for (int i = 1; i < size; ++i) {
            int key = array[i];
            int j = i - 1;

            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                comparisonCount++;
                j--;
            }
            array[j + 1] = key;
        }
    }

    void display() {
        cout << "Sorted Array: ";
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
        cout << "Number of comparisons: " << comparisonCount << endl;
    }
};

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    InsertionSort insertionSorter(arr, size);
    insertionSorter.sort();
    insertionSorter.display();

    delete[] arr;

    return 0;
}

