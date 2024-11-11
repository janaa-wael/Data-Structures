#include <iostream>
#include <vector>

using namespace std;

// Class to represent a node in the linked list
class Node {
public:
    int coeff;  // Coefficient of the polynomial term
    int power;  // Power of x for this term
    Node* next; // Pointer to the next node
    
    // Constructor to initialize a node
    Node(int coeff, int power) : coeff(coeff), power(power), next(nullptr) {}
};

// Class to represent the polynomial as a linked list
class Polynomial {
private:
    Node* head;  // Head of the linked list representing the polynomial
    
public:
    // Constructor to initialize an empty polynomial
    Polynomial() : head(nullptr) {}

    // a. Construct a polynomial linked list from an array of coefficients
    Polynomial(const vector<int>& coeffs) {
        head = nullptr;
        for (int i = 0; i < coeffs.size(); i++) {
            push_back(coeffs[i], coeffs.size() - i - 1);
        }
    }

    // Helper function to add terms to the polynomial
    void push_back(int coeff, int power) {
        Node* newNode = new Node(coeff, power);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // b. Multiply two polynomials and return the resulting polynomial
    Polynomial multiply(const Polynomial& other) {
        Polynomial result;
        Node* ptr1 = this->head;
        
        // Multiply each term of this polynomial with each term of the other polynomial
        while (ptr1) {
            Node* ptr2 = other.head;
            while (ptr2) {
                int newCoeff = ptr1->coeff * ptr2->coeff;
                int newPower = ptr1->power + ptr2->power;
                result.addTerm(newCoeff, newPower);
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
        return result;
    }

    // Helper function to add a term to the polynomial
    void addTerm(int coeff, int power) {
        if (coeff == 0) return;  // Skip zero terms
        
        if (!head || head->power < power) {
            Node* newNode = new Node(coeff, power);
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->power > power) {
                temp = temp->next;
            }
            if (temp->next && temp->next->power == power) {
                temp->next->coeff += coeff;
            } else {
                Node* newNode = new Node(coeff, power);
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    // c. Evaluate the polynomial at a given value of x
    int evaluate(int x) {
        int result = 0;
        Node* temp = head;
        while (temp) {
            result += temp->coeff * pow(x, temp->power);
            temp = temp->next;
        }
        return result;
    }

    // d. Differentiate the polynomial with respect to x
    Polynomial differentiate() {
        Polynomial result;
        Node* temp = head;
        while (temp) {
            if (temp->power > 0) {
                result.push_back(temp->coeff * temp->power, temp->power - 1);
            }
            temp = temp->next;
        }
        return result;
    }

    // Function to print the polynomial in human-readable form
    void print() {
        Node* temp = head;
        while (temp) {
            if (temp->coeff > 0 && temp != head) cout << "+";
            cout << temp->coeff;
            if (temp->power > 0) cout << "x^" << temp->power << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Polynomial() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

// Main function to test the implementation
int main() {
    // Create a polynomial P(x) = 4x^3 + 2x^2 - 1
    vector<int> coeffs = {4, 2, 0, -1};  // Coefficients of the polynomial
    Polynomial poly(coeffs);

    cout << "Original Polynomial: ";
    poly.print();

    // Evaluate P(5)
    int x = 5;
    cout << "P(" << x << ") = " << poly.evaluate(x) << endl;

    // Differentiate the polynomial
    Polynomial derivative = poly.differentiate();
    cout << "Derivative of Polynomial: ";
    derivative.print();

    // Multiply P(x) by itself
    Polynomial product = poly.multiply(poly);
    cout << "P(x) * P(x) = ";
    product.print();

    return 0;
}
