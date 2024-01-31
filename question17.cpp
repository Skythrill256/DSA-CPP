#include<iostream>
using namespace std;

int factorial(int n, int result = 1) {
    if (n == 0 || n == 1) {
        return result;
    } else {
        return factorial(n - 1, n * result);
    }
}

int main() {
    int n;

    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer.\n";
    } else {
        int result = factorial(n);
        cout << "Factorial of " << n << " is: " << result << endl;
    }

    return 0;
}

