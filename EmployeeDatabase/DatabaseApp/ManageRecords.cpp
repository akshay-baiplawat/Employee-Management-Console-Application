#include "ManageRecords.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Globals.h"

using namespace std;

void getStringValue(string &value,HKEY hKey, const char* valueName) {
    DWORD valueDataSize = 256;
    char valueData[256] = {};
    if ((RegQueryValueExA(hKey, valueName, nullptr, nullptr, LPBYTE(valueData), &valueDataSize) == ERROR_SUCCESS)) {
        value = string(valueData);
    }
}

void getIntValue(int& value, HKEY hKey, const char* valueName) {
    DWORD valueDataSize = sizeof(DWORD);
    DWORD valueData = 0;

    if (RegQueryValueExA(hKey, valueName, nullptr, nullptr, reinterpret_cast<LPBYTE>(&valueData), &valueDataSize) == ERROR_SUCCESS) {
        value = static_cast<int>(valueData);
    }
}



void ManageRecords::load(int option)
{
    if (option == 1)
    {
        ifstream file("EpData.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                istringstream ss(line);
                string token;
                vector<string> tokens;

                while (getline(ss, token, ',')) {
                    tokens.push_back(token);
                }

                if (tokens.size() == 6) {
                    int id = stoi(tokens[0]);
                    string name = tokens[1];
                    int age = stoi(tokens[2]);
                    string department = tokens[3];
                    string designation = tokens[4];
                    string reporting = tokens[5];
                    objects.push_back(Employee(id, name, age, department, designation, reporting));
                }
            }
            file.close();
        }
        else {
            cout << "error : text file not open ." << endl;
        }
    }
    else if (option == 2)
    {

        HKEY hEmployeeDataKey;
        const char* keyPath = "SOFTWARE\\WOW6432Node\\EmployeeData";

        if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, keyPath, 0, KEY_READ, &hEmployeeDataKey) == ERROR_SUCCESS) {

            DWORD subkeyIndex = 0;
            char subkeyName[256];
            DWORD subkeyNameSize = sizeof(subkeyName);

            while (RegEnumKeyExA(hEmployeeDataKey, subkeyIndex, subkeyName, &subkeyNameSize, nullptr, nullptr, nullptr, nullptr) == ERROR_SUCCESS) {
                
                HKEY hSubkey;

                if (RegOpenKeyExA(hEmployeeDataKey, subkeyName, 0, KEY_READ, &hSubkey) == ERROR_SUCCESS) {

                    int id = -1, age = -2;
                    string name = "--", department = "--", designation = "--", reporting = "--";

                    getIntValue(id, hSubkey, "id");
                    getStringValue(name, hSubkey, "name");
                    getIntValue(age, hSubkey, "age");
                    getStringValue(department, hSubkey, "department");
                    getStringValue(designation, hSubkey, "designation");
                    getStringValue(reporting, hSubkey, "reporting");

                    objects.push_back(Employee(id, name, age, department, designation, reporting));

                    
                    RegCloseKey(hSubkey);
                }
                else {
                    std::cerr << "Error opening subkey." << std::endl;
                }

                
                subkeyIndex++;
                subkeyNameSize = sizeof(subkeyName);
            }

            RegCloseKey(hEmployeeDataKey);
        }
        else {
            std::cerr << "Error opening parent key." << std::endl;
        }

    }
    else
    {
        cout << "-- Not a option --" << endl;
        cout << "-- Data load failed --" << endl;
    }

}

void ManageRecords::input()
{
    int id=-1, age=-1;
    string name="--", department="--", designation="--", reporting="--";
    int option = 10;
    HKEY hKey;
    cout << "   Select Option" << endl;
    cout << "-> 1 for give input in Text file " << endl;
    cout << "-> 2 for Registry " << endl;
    cout << "-> ";
    cin >> option;
    if (option == 1)
    {
        cout << "-> Not working for now work in ... " << endl;
    }
    else if (option == 2)
    {
        cout << "   Write input data" << endl;
        cout << "-> ID : ";
        cin >> id;
        cout << "-> Name : ";
        cin.ignore();
        getline(cin, name);
        cout << "-> Age : ";
        cin >> age;
        cout << "-> Department : ";
        cin.ignore();
        getline(cin, department);
        cout << "-> Designation : ";
        cin.ignore();
        getline(cin, designation);
        cout << "-> Reporting : ";
        cin.ignore();
        getline(cin, reporting);
       // CreatSubKey(hKey, HKEY_LOCAL_MACHINE,keyPath);
        
    }

}

void ManageRecords::showAll()
{
    int n = objects.size();
    for (int i = 0;i < n;i++) {
        cout << "ID : " << objects[i].id << ", Name : " << objects[i].name << ", Age : " << objects[i].age << ", Department: " << objects[i].department << ", Designation : " << objects[i].designation << ", Reporting : " << objects[i].reporting << endl;
    }
}

void ManageRecords::deleto(int Id) 
{
	cout << "delet";
}