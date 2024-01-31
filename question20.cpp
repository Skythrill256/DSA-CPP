#include<iostream>
using namespace std;

class MergeSort {
private:
    int* arr;
    int size;

    void merge(int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        int leftArray[n1], rightArray[n2];

        for (int i = 0; i < n1; i++)
            leftArray[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArray[j] = arr[middle + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                arr[k] = leftArray[i];
                i++;
            } else {
                arr[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = rightArray[j];
            j++;
            k++;
        }
    }

    void mergeSort(int left, int right) {
        if (left < right) {
            int middle = left + (right - left) / 2;

            mergeSort(left, middle);
            mergeSort(middle + 1, right);

            merge(left, middle, right);
        }
    }

public:
    MergeSort(int n) : size(n) {
        arr = new int[size];
    }

    ~MergeSort() {
        delete[] arr;
    }

    void getInput() {
        cout << "Enter the elements of the array:\n";
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }
    }

    void sort() {
        mergeSort(0, size - 1);
    }

    void display() {
        cout << "Sorted Array: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (size < 0) {
        cout << "Please enter a non-negative integer.\n";
        return 1;
    }

    MergeSort mergeSortObj(size);
    mergeSortObj.getInput();
    mergeSortObj.sort();
    mergeSortObj.display();

    return 0;
}

