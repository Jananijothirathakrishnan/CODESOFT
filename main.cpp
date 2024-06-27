#include <iostream>
using namespace std;
void displayMenu();
void performAddition();
void performSubtraction();
void performMultiplication();
void performDivision();

int main() {
    int choice;

    do {
        displayMenu();

        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                performAddition();
                break;
            case 2:
                performSubtraction();
                break;
            case 3:
                performMultiplication();
                break;
            case 4:
                performDivision();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
        cout << endl;
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "Calculator Menu:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Exit" << endl;
}

void performAddition() {
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Result: " << num1 + num2 << endl;
}

void performSubtraction() {
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Result: " << num1 - num2 << endl;
}

void performMultiplication() {
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Result: " << num1 * num2 << endl;
}

void performDivision() {
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    if (num2 != 0) {
        cout << "Result: " << num1 / num2 << endl;
    } else {
        cout << "Error: Division by zero is not allowed." << endl;
    }
}
