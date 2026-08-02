// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Define the Student struct
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Function to display the menu
void showMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

// Function to add a student
void addStudent(vector<Student>& students) {
    Student newStudent;
    
    // Get student name
    cout << "Student name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, newStudent.name);
    
    // Get student ID
    cout << "Student ID: ";
    cin >> newStudent.id;
    
    // Get number of scores
    int numScores;
    cout << "How many scores? ";
    cin >> numScores;
    
    // Collect scores
    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        newStudent.scores.push_back(score);
    }
    
    // Add student to vector
    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

// Function to calculate average of a student's scores
double calculateAverage(const Student& student) {
    if (student.scores.empty()) {
        return 0.0;
    }
    
    double sum = 0.0;
    for (double score : student.scores) {
        sum += score;
    }
    return sum / student.scores.size();
}

// Function to display all students
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }
    
    cout << "\n" << string(80, '-') << endl;
    cout << left << setw(25) << "Name" 
         << setw(15) << "ID" 
         << setw(30) << "Scores" 
         << "Average" << endl;
    cout << string(80, '-') << endl;
    
    for (const Student& student : students) {
        cout << left << setw(25) << student.name;
        cout << setw(15) << student.id;
        
        // Display all scores
        cout << "[";
        for (size_t i = 0; i < student.scores.size(); i++) {
            cout << student.scores[i];
            if (i < student.scores.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        
        // Align average
        cout << setw(30 - student.scores.size() * 4) << "";
        
        // Display average with 2 decimal places
        cout << fixed << setprecision(2) << calculateAverage(student) << endl;
    }
    cout << string(80, '-') << endl;
}

// Function to find a student by ID
int findStudentById(const vector<Student>& students, int id) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            return i; // Return index
        }
    }
    return -1; // Not found
}

// Function to calculate and display average for a specific student
void calculateStudentAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }
    
    int id;
    cout << "Enter student ID: ";
    cin >> id;
    
    int index = findStudentById(students, id);
    
    if (index == -1) {
        cout << "Error: Student with ID " << id << " not found." << endl;
        return;
    }
    
    const Student& student = students[index];
    double avg = calculateAverage(student);
    
    if (student.scores.empty()) {
        cout << student.name << " has no scores recorded yet." << endl;
    } else {
        cout << student.name << "'s average score: " 
             << fixed << setprecision(2) << avg << endl;
    }
}

int main() {
    vector<Student> students;
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent(students);
                break;
                
            case 2:
                displayAllStudents(students);
                break;
                
            case 3:
                calculateStudentAverage(students);
                break;
                
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }
    } while (choice != 4);
    
    return 0;
}
