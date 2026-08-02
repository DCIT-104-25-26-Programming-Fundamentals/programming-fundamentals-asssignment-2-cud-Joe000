// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to display the menu
void showMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

// Function to get two numbers from the user
void getNumbers(double& a, double& b) {
    cout << "Enter first number : ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
}

// Addition function
void add() {
    double a, b;
    getNumbers(a, b);
    cout << "Result: " << a << " + " << b << " = " 
         << fixed << setprecision(2) << (a + b) << endl;
}

// Subtraction function
void subtract() {
    double a, b;
    getNumbers(a, b);
    cout << "Result: " << a << " - " << b << " = " 
         << fixed << setprecision(2) << (a - b) << endl;
}

// Multiplication function
void multiply() {
    double a, b;
    getNumbers(a, b);
    cout << "Result: " << a << " * " << b << " = " 
         << fixed << setprecision(2) << (a * b) << endl;
}

// Division function
void divide() {
    double a, b;
    getNumbers(a, b);
    
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return;
    }
    
    cout << "Result: " << a << " / " << b << " = " 
         << fixed << setprecision(2) << (a / b) << endl;
}

// Modulus function (only works with integers)
void modulus() {
    int a, b;
    cout << "Enter first number : ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    
    if (b == 0) {
        cout << "Error: Cannot perform modulus by zero." << endl;
        return;
    }
    
    cout << "Result: " << a << " % " << b << " = " << (a % b) << endl;
}

// Exponentiation function
void exponentiate() {
    double a, b;
    getNumbers(a, b);
    double result = pow(a, b);
    cout << "Result: " << a << " ^ " << b << " = " 
         << fixed << setprecision(2) << result << endl;
}

int main() {
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                add();
                break;
                
            case 2:
                subtract();
                break;
                
            case 3:
                multiply();
                break;
                
            case 4:
                divide();
                break;
                
            case 5:
                modulus();
                break;
                
            case 6:
                exponentiate();
                break;
                
            case 7:
                cout << "Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please select a number between 1 and 7." << endl;
                break;
        }
    } while (choice != 7);
    
    return 0;
}
