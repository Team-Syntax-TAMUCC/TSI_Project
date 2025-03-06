//#include <emscripten.h>

// extern "C" { 
//     EMSCRIPTEN_KEEPALIVE
//     int add(int a, int b) {
//         return a + b;
//     }
// }

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

// Structure to store student data
struct Student {
    string name;
    string id;
    string tsi_category;
    string status;
    string guidance;
    
    // Constructor for initializing the struct
    Student(string n, string i, string tsi, string s, string g) 
        : name(n), id(i), tsi_category(tsi), status(s), guidance(g) {}
};

// Function to generate JSON data for front-end consumption
void generateJSON(const vector<Student>& students) {
    ofstream file("students.json");
    file << "{\"students\": [";
    for (size_t i = 0; i < students.size(); ++i) {
        file << "{\"name\": \"" << students[i].name << "\", "
             << "\"id\": \"" << students[i].id << "\", "
             << "\"tsi_category\": \"" << students[i].tsi_category << "\", "
             << "\"status\": \"" << students[i].status << "\", "
             << "\"guidance\": \"" << students[i].guidance << "\"}";
        if (i != students.size() - 1) file << ", ";
    }
    file << "]}";
    file.close();
}

int main() {
    // Sample student data
    vector<Student> students;
    students.push_back(Student("Emily Rodriguez", "20241234", "Not College Ready (NCR)", "ELAR: Writing Failed", "Enroll in INRW 0399"));
    students.push_back(Student("Daniel Nguyen", "20242345", "College Ready (CR)", "TSI Scores Met", "No further action required"));
    students.push_back(Student("John Doe", "20245678", "Not College Ready (NCR)", "Math: Failed", "Enroll in MATH 0314"));
    students.push_back(Student("Jane Smith", "20246789", "Exempt (HB5)", "Multiple Measures Assessment", "Follow college guidelines"));
    
    generateJSON(students);
    
    cout << "JSON file generated successfully. Use this file in your HTML front-end." << endl;
    return 0;
}

