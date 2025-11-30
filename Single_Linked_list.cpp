#include <iostream>
using namespace std;

//----------------------------
// Node structure for patient
//----------------------------
struct Node {
    int patientID;     // Patient ID
    Node* next;        // Pointer to next node
};

// Head pointer to the linked list
Node* head = NULL;

//----------------------------------------------------
// 1. Insert patient at the END (normal check-in)
//----------------------------------------------------
void insertAtEnd(int id) {
    Node* newNode = new Node();
    newNode->patientID = id;
    newNode->next = NULL;

    // If list is empty ? new node becomes head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Otherwise traverse to the last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;  // Insert at end
}

//----------------------------------------------------
// 2. Insert patient at the BEGINNING (emergency)
//----------------------------------------------------
void insertAtBeginning(int id) {
    Node* newNode = new Node();
    newNode->patientID = id;

    // New node points to current head
    newNode->next = head;

    // New node is now new head
    head = newNode;
}

//----------------------------------------------------
// 3. Display all patients
//----------------------------------------------------
void displayPatients() {
    if (head == NULL) {
        cout << "No patients in the system.\n";
        return;
    }

    Node* temp = head;
    cout << "\nCurrent Patients:\n";
    while (temp != NULL) {
        cout << "Patient ID: " << temp->patientID << endl;
        temp = temp->next;
    }
}

//----------------------------------------------------
// Main Menu
//----------------------------------------------------
int main() {
    int choice, id;

    while (true) {
        cout << "\n===== Hospital Patient Check-In System =====\n";
        cout << "1. Add new patient at END (Normal Check-In)\n";
        cout << "2. Add patient at BEGINNING (Emergency)\n";
        cout << "3. Display all patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Patient ID: ";
            cin >> id;
            insertAtEnd(id);
            cout << "Patient added at END successfully!\n";
            break;

        case 2:
            cout << "Enter Patient ID: ";
            cin >> id;
            insertAtBeginning(id);
            cout << "Emergency patient added at BEGINNING!\n";
            break;

        case 3:
            displayPatients();
            break;

        case 4:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}