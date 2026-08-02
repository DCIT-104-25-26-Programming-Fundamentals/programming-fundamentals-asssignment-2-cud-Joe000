// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

// PART A: Print multiplication table for a single number
void printSingleTable(int num) {
    cout << "\nMultiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << setw(2) << num << "  x  " << setw(2) << i << "  =  " << setw(3) << (num * i) << endl;
    }
}

// PART B: Print multiplication tables from 1 to N
void printTablesUpToN(int n) {
    // Validate input
    if (n <= 0) {
        cout << "Error: Number must be positive." << endl;
        return;
    }
    
    for (int num = 1; num <= n; num++) {
        printSingleTable(num);
        
        // Add separator line between tables (but not after the last one)
        if (num < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int choice;
    int number, n;
    
    do {
        cout << "\n===== MULTIPLICATION TABLE MENU =====" << endl;
        cout << "1. Print Single Table (Part A)" << endl;
        cout << "2. Print Tables from 1 to N (Part B)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> number;
                printSingleTable(number);
                break;
                
            case 2:
                cout << "Enter a number N: ";
                cin >> n;
                printTablesUpToN(n);
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
