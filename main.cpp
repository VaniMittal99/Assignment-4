#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
class ViolationData {
public:
    string licensePlate;
    string violationSource;
    string violationLocation;

    ViolationData(const string& plate, const string& source, const string& location)
        : licensePlate(plate), violationSource(source), violationLocation(location) {}
};
class GatheredEvidence {
public:
    string licensePlate;
    string statement;
    vector<string> eyewitnesses;
    GatheredEvidence(const string& plate, const string& stmt, const vector<string>& witnesses)
        : licensePlate(plate), statement(stmt), eyewitnesses(witnesses) {}
};
vector<ViolationData> readViolationData(const string& fileName) {
    vector<ViolationData> violations;
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Unable to open file " << fileName << endl;
        return violations;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string licensePlate, violationSource, violationLocation;

        getline(ss, licensePlate, ',');
        getline(ss, violationSource, ',');
        getline(ss, violationLocation, ',');

        violations.emplace_back(licensePlate, violationSource, violationLocation);
    }
    file.close();
    return violations;
}
GatheredEvidence gatherEvidence(const vector<ViolationData>& violationRecords) {
    string licensePlate, statement;
    int numEyewitnesses;
    cout << "Enter License Plate: ";
    cin >> licensePlate;
    cout << "Enter the number of eyewitnesses: ";
    cin >> numEyewitnesses;
    vector<string> eyewitnesses;
    string eyewitnessName;
    for (int j = 0; j < numEyewitnesses; ++j) {
        cout << "Enter name of eyewitness " << j + 1 << ": ";
        cin >> eyewitnessName;
        eyewitnesses.push_back(eyewitnessName);
    }
    cout << "Enter your statement for the case: ";
    cin.ignore(); 
    getline(cin, statement);
    return GatheredEvidence(licensePlate, statement, eyewitnesses);
}
void printGatheredEvidence(const GatheredEvidence& evidence) {
    cout << "\nGathered Evidence:\n";
    cout << "License Plate: " << evidence.licensePlate << endl;
    cout << "Statement: " << evidence.statement << endl;
    cout << "Eyewitnesses: ";
    for (const auto& eyewitness : evidence.eyewitnesses) {
        cout << eyewitness << " ";
    }
    cout << endl;
}

// Function to find and print matching violation records
void findAndPrintMatchingViolations(const vector<ViolationData>& violationRecords, const string& licensePlate) {
    cout << "\nMatching Violation Record:\n";
    for (const auto& violation : violationRecords) {
        if (violation.licensePlate == licensePlate) {
            cout << "License Plate: " << violation.licensePlate << endl;
            cout << "Source: " << violation.violationSource << endl;
            cout << "Location: " << violation.violationLocation << endl;
        }
    }
    cout << "\n\n";
}

int main() {
    string violationFileName = "Q2_A4.csv";

    vector<ViolationData> violationRecords = readViolationData(violationFileName);

    int numChallenges;
    cout << "Enter the number of violations you want to challenge: ";
    cin >> numChallenges;

    for (int i = 0; i < numChallenges; ++i) 
    {
        GatheredEvidence gatheredEvidence = gatherEvidence(violationRecords);

        printGatheredEvidence(gatheredEvidence);

        findAndPrintMatchingViolations(violationRecords, gatheredEvidence.licensePlate);
    }

    return 0;
}
