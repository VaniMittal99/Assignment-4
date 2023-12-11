#include "HeaderFile.h"

vector<CarReport> readCSVFile(const string& fname) {
    vector<CarReport> result;
    ifstream file(fname);

    if (!file.is_open()) {
        cerr << "Error opening file: " << fname << endl;
        return result;
    }

    string line;
    getline(file, line); // Read and discard the header line

    while (getline(file, line)) {
        stringstream ss(line);
        CarReport report;
        getline(ss, report.carNumber, ',');
        string sno;
        getline(ss, sno, ',');
        report.carNumber += "-"+ sno;

        
        getline(ss, report.reportType, ',');
        getline(ss, report.reportLocation, ',');

        result.push_back(report);
    }

    file.close();
    return result;
}

void updateLoaction(vector<CarReport>& reports, const string& vNumber,CarReport newReport  ){
    for (auto& report : reports) {
        if (report.carNumber == vNumber) {
            cout << "Updating Record details for Vehicle Number: " << vNumber << endl;

            // Update owner details with new user details
            report.reportLocation = newReport.reportLocation;

            cout << "Report details updated successfully." << endl;
            return;
        }
    }
    cout << "Vehicle with Number: " << vNumber << " not found in the records." << endl;
}
void printOwnerDetails(const vector<CarReport>& reports, const string& vNumber) {
    for (const auto& report : reports) {
        if (report.carNumber == vNumber) {
            cout << "Vehicle Report Found!" << endl;
            report.details();
            return;
        }
    }
    cout << "Report with vehicle Number: " << vNumber << " not found in the records." << endl;
}
