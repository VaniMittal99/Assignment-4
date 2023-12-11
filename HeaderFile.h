#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class VehicleDetails {
public:
    string vehicleNo;
};

class UserDetails {
public:
    string firstName;
    string lastName;
    string age;
    string gender;
    string address;
};


//class veichleOwner inherits UserDetails and VechileDetails   
class VehicleOwner : public UserDetails, public VehicleDetails {
public:
    void details() const {
        cout << "Vehicle Number: " << vehicleNo << endl;
        cout << "Owner Name: " << firstName<<" "<< lastName << endl;
        cout << "Age: " << age << " Gender: " << gender<<" Address: " << address << endl << endl;
    }
};
//function declaration
vector<VehicleOwner> readCSVFile(const string& csv);
void changeOwner(vector<VehicleOwner>& owners, const string& vNumber,UserDetails newUser);
void printOwnerDetails(const vector<VehicleOwner>& owners,const string& vNumber);