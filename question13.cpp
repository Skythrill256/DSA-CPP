#include<iostream>
using namespace std;

class SelectionSort {
private:
    int* array;
    int size;
    int comparisonCount;

public:
    SelectionSort(int arr[], int n) : size(n), comparisonCount(0) {
        array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = arr[i];
        }
    }

    ~SelectionSort() {
        delete[] array;
    }

    void sort() {
        for (int i = 0; i < size - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                comparisonCount++;
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            swap(array[i], array[minIndex]);
        }
    }

    void display() {
        cout << "Sorted Array: ";
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
        cout << "Comparisons: " << comparisonCount << endl;
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

    SelectionSort sorter(arr, size);
    sorter.sort();
    sorter.display();

    delete[] arr;

    return 0;
}

