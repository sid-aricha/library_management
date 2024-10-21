#include <iostream>
#include <string>
using namespace std;

// Class to represent a book in the library
class Book {
public:
    string name;
    string author;
    int id;
    Book* next;

    Book(string name, string author, int id) {
        this->name = name;
        this->author = author;
        this->id = id;
        next = nullptr;
    }
};

// Class to represent a student who has borrowed a book
class Student {
public:
    string name;
    string email;
    string bookBorrowed;
    int id;
    Student* next;

    Student(string name, string email, string bookBorrowed, int id) {
        this->name = name;
        this->email = email;
        this->bookBorrowed = bookBorrowed;
        this->id = id;
        next = nullptr;
    }
};

// Pointers to the start of the linked lists
Book* start_lib = nullptr;
Student* start = nullptr;

// Function declarations
Book* initialize_lib(Book*);
Student* book_issue(Student*);
Student* book_return(Student*);
void display_lib(Book*);
Book* delete_book(Book*, int);
Book* add_book(Book*, string, string, int);
void display_students(Student*);
void greetings();
void main_menu();

// Main function
int main() {
    start_lib = initialize_lib(start_lib);
    greetings();
    main_menu();
    return 0;
}

// Function to print a greeting message
void greetings() {
    cout << "\n\n";
    cout << "\t\t\t     ****************************************\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *        Welcome to Library System     *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     ****************************************\n";
}

// Function to initialize the library with some books
Book* initialize_lib(Book* start_lib) {
    // Add some sample books to the library for demonstration purposes
    start_lib = add_book(start_lib, "C++ Programming", "Bjarne Stroustrup", 101);
    start_lib = add_book(start_lib, "Data Structures", "Mark Weiss", 102);
    start_lib = add_book(start_lib, "Operating Systems", "Andrew Tanenbaum", 103);
    return start_lib;
}

// Function to add a book to the library
Book* add_book(Book* start_lib, string name, string author, int id) {
    Book* new_book = new Book(name, author, id);
    if (!start_lib) {
        start_lib = new_book;
    } else {
        Book* temp = start_lib;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_book;
    }
    cout << "Book added successfully: " << name << " by " << author << "\n";
    return start_lib;
}

// Function to display the library books
void display_lib(Book* start_lib) {
    if (!start_lib) {
        cout << "Library is empty.\n";
        return;
    }
    Book* temp = start_lib;
    while (temp) {
        cout << "Book ID: " << temp->id << " | Title: " << temp->name << " | Author: " << temp->author << "\n";
        temp = temp->next;
    }
}

// Function to delete a book from the library
Book* delete_book(Book* start_lib, int id) {
    if (!start_lib) {
        cout << "Library is empty.\n";
        return start_lib;
    }
    Book* temp = start_lib;
    Book* prev = nullptr;
    while (temp != nullptr && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Book not found.\n";
        return start_lib;
    }
    if (prev == nullptr) {
        start_lib = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Book deleted successfully.\n";
    return start_lib;
}

// Function to issue a book to a student (simplified)
Student* book_issue(Student* start) {
    string name, email, book;
    int id;
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student email: ";
    cin >> email;
    cout << "Enter book title: ";
    cin >> book;
    cout << "Enter student ID: ";
    cin >> id;
    Student* new_student = new Student(name, email, book, id);
    if (!start) {
        start = new_student;
    } else {
        Student* temp = start;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_student;
    }
    cout << "Book issued successfully to " << name << ".\n";
    return start;
}

// Function to return a book by a student (simplified)
Student* book_return(Student* start) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;
    Student* temp = start;
    Student* prev = nullptr;
    while (temp != nullptr && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Student record not found.\n";
        return start;
    }
    if (prev == nullptr) {
        start = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Book returned successfully.\n";
    return start;
}

// Function to display the list of students who have borrowed books
void display_students(Student* start) {
    if (!start) {
        cout << "No students have borrowed books.\n";
        return;
    }
    Student* temp = start;
    while (temp) {
        cout << "Student Name: " << temp->name << " | Email: " << temp->email << " | Book: " << temp->bookBorrowed << "\n";
        temp = temp->next;
    }
}

// Main menu function
void main_menu() {
    int choice;
    do {
        cout << "\nLibrary Main Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Delete Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Display Students\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, author;
                int id;
                cout << "Enter book title: ";
                cin >> name;
                cout << "Enter book author: ";
                cin >> author;
                cout << "Enter book ID: ";
                cin >> id;
                start_lib = add_book(start_lib, name, author, id);
                break;
            }
            case 2:
                display_lib(start_lib);
                break;
            case 3: {
                int id;
                cout << "Enter book ID to delete: ";
                cin >> id;
                start_lib = delete_book(start_lib, id);
                break;
            }
            case 4:
                start = book_issue(start);
                break;
            case 5:
                start = book_return(start);
                break;
            case 6:
                display_students(start);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}
