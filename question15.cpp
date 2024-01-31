#include<iostream>
using namespace std;

class BubbleSort {
private:
    int* array;
    int size;
    int comparisonCount;

public:
    BubbleSort(int arr[], int n) : size(n), comparisonCount(0) {
        array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = arr[i];
        }
    }

    ~BubbleSort() {
        delete[] array;
    }

    void sort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                comparisonCount++;
                if (array[j] > array[j + 1]) {
                    swap(array[j], array[j + 1]);
                }
            }
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

    BubbleSort bubbleSorter(arr, size);
    bubbleSorter.sort();
    bubbleSorter.display();

    delete[] arr;

    return 0;
}

