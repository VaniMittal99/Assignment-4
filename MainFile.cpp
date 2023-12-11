#include "HeaderFile.h"
void displayMenu(const vector<CarReport>& reports);
void updateRecords(vector<CarReport>& reports);
int main() 
{
    string filename = "Q2_A4.csv";
    vector<CarReport> reports = readCSVFile(filename);
    int choice;
    do 
    {
        displayMenu(reports);
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                for (const auto& report : reports) 
                {
                    report.details();
                }
                break;
            case 2:
                string vNumber;
                cout << "Enter Vehicle Number: ";
                cin >> vNumber;
                printOwnerDetails(reports, vNumber);
                break;
            case 3:
                updateRecords(reports);
                break;
            case 4:
                cout << "EXIT" << endl;
                break;
            default:
                cout << "Enter a valid option." << endl;
        }
    } 
    while (choice != 4);
    return 0;
}
void displayMenu(const vector<CarReport>& reports) 
{
    cout << "1) Display CSV" << endl;
    cout << "2) Enter Vehicle Number" << endl;
    cout << "3) Update Records" << endl;
    cout << "4) Exit" << endl;
}
void updateRecords(vector<CarReport>& reports) 
{
    string vNumber;
    CarReport updatedReport;
    cout << "Enter Vehicle Number for the record you want to update: ";
    cin >> vNumber;
    cout << "Enter new details:" << endl;
    cout << "Report_Location: ";
    getline(cin >> ws, updatedReport.reportLocation);
    updateLoaction(reports, vNumber, updatedReport);
}
