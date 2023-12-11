#include "HeaderFile.h"

vector<VehicleOwner> readCSVFile(const string& fname) {
    vector<VehicleOwner> result;
    ifstream file(fname);
    if (!file.is_open()) {
        cerr << "Error opening file: " << fname << endl;
        return result;
    }
    string line;
    getline(file, line);
    while (getline(file, line))
     {
        stringstream ss(line);
        VehicleOwner owner;
        getline(ss, owner.vehicleNo, ',');
        string sno;
        getline(ss, sno, ',');
        owner.vehicleNo += "-"+ sno;
        getline(ss, owner.firstName, ',');
        getline(ss, owner.lastName, ',');
        getline(ss, owner.age, ',');
        getline(ss, owner.gender, ',');
        getline(ss, owner.address, ',');
        result.push_back(owner);
    }
    file.close();
    return result;
}
void changeOwner(vector<VehicleOwner>& owners, const string& vNumber,UserDetails newUser) {
    for (auto& owner : owners) {
        if (owner.vehicleNo == vNumber) {
            cout << " Manipulating details for Vehicle Number: " << vNumber << endl;
            owner.firstName = newUser.firstName;
            owner.lastName = newUser.lastName;
            owner.age = newUser.age;
            owner.gender = newUser.gender;
            owner.address = newUser.address;
            cout << "Owner details updated successfully." << endl;
            return;
        }
    }
    cout << "Vehicle with Number: " << vNumber << " not found in the records." << endl;
}
void printOwnerDetails(const vector<VehicleOwner>& owners, const string& vNumber) {
    for (const auto& owner : owners) {
        if (owner.vehicleNo == vNumber) {
            cout << "Vehicle Owner Found!" << endl;
            owner.details();
            return;
        }
    }
    cout << "Vehicle" << vNumber << "not present in the records." << endl;
}