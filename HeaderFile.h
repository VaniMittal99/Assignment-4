#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class CarReport {
public:
    string carNumber;
    string reportType;
    string reportLocation;

    void details() const {
        cout << "Car Number: " << carNumber << endl;
        cout << "Report Type: " << reportType << endl;
        cout << "Report Location: " << reportLocation << endl << endl;
    }
};

//function declaration
vector<CarReport> readCSVFile(const string& csv);
void updateLoaction(vector<CarReport>& reports, const string& vNumber,CarReport );
void printOwnerDetails(const vector<CarReport>& reports,const string& vNumber);