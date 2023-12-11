#include "HeaderFile.h"

void displayMenu(const vector<VehicleOwner>& owners);
UserDetails getNewUserDetails();

int main() {
    string filename = "Q1_A4.csv";
    vector<VehicleOwner> owners = readCSVFile(filename);

    int choice;
    string vNumber;
    UserDetails newUser;

    do {
        displayMenu(owners);
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Display CSV
                for (const auto &owner : owners) {
                    owner.details();
                }
                break;

            case 2:
                // Enter Vehicle Number
                cout << "Enter Vehicle Number: ";
                cin >> vNumber;
                printOwnerDetails(owners, vNumber);
                break;

            case 3:
                // Update Owner Details
                cout << "Enter Vehicle Number for the owner you want to update: ";
                cin >> vNumber;

                newUser = getNewUserDetails();
                changeOwner(owners, vNumber, newUser);
                break;

            case 4:
                // Exit
                cout << "Shutting down..." << endl;
                break;

            default:
                cout << "Enter a valid option." << endl;
        }

    } while (choice != 4);

    return 0;
}

void displayMenu(const vector<VehicleOwner>& owners) {
    cout << "Menu:" << endl;
    cout << "1. Display CSV" << endl;
    cout << "2. Enter Vehicle Number" << endl;
    cout << "3. Update records" << endl;
    cout << "4. Exit" << endl;
}

UserDetails getNewUserDetails() {
    UserDetails newUser;

    cout << "Enter new details:" << endl;
    cout << "First Name: ";
    cin >> newUser.firstName;
    cout << "Last Name: ";
    cin >> newUser.lastName;
    cout << "Age: ";
    cin >> newUser.age;
    cout << "Gender: ";
    cin >> newUser.gender;
    cout << "Address: ";
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, newUser.address);

    return newUser;
}
