#include<iostream>
using namespace std;

int fibonacci(int n, int a = 0, int b = 1) {
    if (n == 0) {
        return a;
    } else {
        return fibonacci(n - 1, b, a + b);
    }
}

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer.\n";
    } else {
        int result = fibonacci(n);
        cout << "The " << n << "th Fibonacci number is: " << result << endl;
    }

    return 0;
}

