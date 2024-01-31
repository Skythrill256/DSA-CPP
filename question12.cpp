#include<iostream>
using namespace std;

class Node {
public:
    int coefficient;
    int exponent;
    Node* next;

    Node(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() : head(nullptr) {}

    ~Polynomial() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insertTerm(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);
        if (head == nullptr || exp > head->exponent) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && exp <= current->next->exponent) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->coefficient << "x^" << current->exponent;
            if (current->next != nullptr) {
                cout << " + ";
            }
            current = current->next;
        }
        cout << endl;
    }

    static Polynomial addPolynomials(const Polynomial& poly1, const Polynomial& poly2) {
        Polynomial result;
        Node* current1 = poly1.head;
        Node* current2 = poly2.head;

        while (current1 != nullptr || current2 != nullptr) {
            int coeff1 = (current1 != nullptr) ? current1->coefficient : 0;
            int exp1 = (current1 != nullptr) ? current1->exponent : -1;

            int coeff2 = (current2 != nullptr) ? current2->coefficient : 0;
            int exp2 = (current2 != nullptr) ? current2->exponent : -1;

            if (exp1 > exp2) {
                result.insertTerm(coeff1, exp1);
                current1 = current1->next;
            } else if (exp1 < exp2) {
                result.insertTerm(coeff2, exp2);
                current2 = current2->next;
            } else {
                int sumCoeff = coeff1 + coeff2;
                if (sumCoeff != 0) {
                    result.insertTerm(sumCoeff, exp1);
                }
                current1 = current1->next;
                current2 = current2->next;
            }
        }
        return result;
    }
};

int main() {
    Polynomial poly1, poly2, result;

    int terms, coeff, exp;

    cout << "Enter the number of terms in Polynomial 1: ";
    cin >> terms;
    cout << "Enter the terms (coefficient exponent) separated by space:\n";
    for (int i = 0; i < terms; ++i) {
        cin >> coeff >> exp;
        poly1.insertTerm(coeff, exp);
    }

    cout << "Enter the number of terms in Polynomial 2: ";
    cin >> terms;
    cout << "Enter the terms (coefficient exponent) separated by space:\n";
    for (int i = 0; i < terms; ++i) {
        cin >> coeff >> exp;
        poly2.insertTerm(coeff, exp);
    }

    result = Polynomial::addPolynomials(poly1, poly2);

    cout << "Polynomial 1: ";
    poly1.display();
    cout << "Polynomial 2: ";
    poly2.display();
    cout << "Sum of Polynomials: ";
    result.display();

    return 0;
}

