// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// PART A: Print the first N terms of the Fibonacci sequence
void printFibonacciTerms(int n) {
    // Validate input
    if (n <= 0) {
        cout << "Error: Number of terms must be positive." << endl;
        return;
    }
    
    cout << "Fibonacci sequence: ";
    
    // Handle special cases
    if (n >= 1) {
        cout << "0";
    }
    if (n >= 2) {
        cout << " 1";
    }
    
    // Generate and print remaining terms
    long long prev1 = 0; // First term
    long long prev2 = 1; // Second term
    long long current;
    
    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2;
        cout << " " << current;
        prev1 = prev2;
        prev2 = current;
    }
    
    cout << endl;
}

// PART B: Check if a number belongs to the Fibonacci sequence
void checkFibonacciNumber(int num) {
    if (num < 0) {
        cout << num << " is NOT a Fibonacci number (negative numbers are not in the sequence)." << endl;
        return;
    }
    
    // Handle base cases
    if (num == 0 || num == 1) {
        cout << num << " is a Fibonacci number." << endl;
        return;
    }
    
    // Generate Fibonacci numbers until we either find a match or exceed the number
    long long prev1 = 0;
    long long prev2 = 1;
    long long current = 0;
    
    while (current < num) {
        current = prev1 + prev2;
        if (current == num) {
            cout << num << " is a Fibonacci number." << endl;
            return;
        }
        prev1 = prev2;
        prev2 = current;
    }
    
    // If we've exceeded the number, it's not in the sequence
    cout << num << " is NOT a Fibonacci number." << endl;
}

int main() {
    int choice;
    int n, num;
    
    do {
        cout << "\n===== FIBONACCI SEQUENCE MENU =====" << endl;
        cout << "1. Print First N Terms" << endl;
        cout << "2. Check if a Number is Fibonacci" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "How many terms? ";
                cin >> n;
                printFibonacciTerms(n);
                break;
                
            case 2:
                cout << "Enter a number to check: ";
                cin >> num;
                checkFibonacciNumber(num);
                break;
                
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
    
    return 0;
}
