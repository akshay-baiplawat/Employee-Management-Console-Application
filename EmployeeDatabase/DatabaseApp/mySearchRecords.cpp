#include "mySearchRecords.h"
#include <iostream>
#include <vector>
#include"ManageRecords.h"
using namespace std;

void mySearchRecords::printdata(vector<Employee> &data) {
    int n = data.size();
    if (n == 0) {
        cout << "---NOT FOUND !!! ---" << endl;
        return;
    }
    for (int i = 0;i < n;i++) {
        cout << "ID : " << data[i].id << ", Name : " << data[i].name << ", Age : " << data[i].age << ", Department: " << data[i].department << ", Designation : " << data[i].designation << ", Reporting : " << data[i].reporting << endl;
    }
}

vector<Employee> mySearchRecords::searchName(vector<Employee>& data, string name, string flow) {

    int n = data.size();
    vector<Employee> newdata;

    if (flow == "start") {
        for (int i = 0;i < n;i++) {
            if (SameCheck(data[i].name, name)) {
                newdata.push_back(data[i]);
            }
        }
    }

    if (flow == "end") {
        for (int i = 0;i < n;i++) {
            if (EndSameCheck(data[i].name, name)) {
                newdata.push_back(data[i]);
            }
        }
    }
    
    if (flow == "contains") {
        for (int i = 0;i < n;i++) {
            if (ContainsCheck(data[i].name, name)) {
                newdata.push_back(data[i]);
            }
        }
    }

    if (flow == "notContains") {
        for (int i = 0;i < n;i++) {
            if (!ContainsCheck(data[i].name, name)) {
                newdata.push_back(data[i]);
            }
        }
    }
   
    return newdata;
}

vector<Employee> mySearchRecords::searchAge(vector<Employee>& data, int age, string flow) {
    vector<Employee> newdata;
    int n = data.size();

    if (flow == ">") {
        for (int i = 0;i < n;i++) {
            if (data[i].age>age) {
                newdata.push_back(data[i]);
            }
        }
    }

    if (flow == "<") {
        for (int i = 0;i < n;i++) {
            if (data[i].age<age) {
                newdata.push_back(data[i]);
            }
        }
    }

    if (flow == "=") {
        for (int i = 0;i < n;i++) {
            if (data[i].age== age) {
                newdata.push_back(data[i]);
            }
        }
    }

    if (flow == "!=") {
        for (int i = 0;i < n;i++) {
            if (data[i].age!= age) {
                newdata.push_back(data[i]);
            }
        }
    }

    
    return newdata;
}

vector<Employee> mySearchRecords::searchDepartment(vector<Employee>& data, string name) {
    vector<Employee> newdata;
    int n = data.size();
    for (int i = 0;i < n;i++) {
        if (SameCheck(data[i].department, name)) {
            newdata.push_back(data[i]);
        }
    }
    
    return newdata;
}

vector<Employee> mySearchRecords::searchDesignation(vector<Employee>& data, string name) {
    vector<Employee> newdata;
    int n = data.size();
    for (int i = 0;i < n;i++) {
        if (SameCheck(data[i].designation, name)) {
            newdata.push_back(data[i]);
        }
    }
    
    return newdata;
}

vector<Employee> mySearchRecords::searchReporting(vector<Employee>& data, string name) {
    vector<Employee> newdata;
    int n = data.size();
    for (int i = 0;i < n;i++) {
        if (SameCheck(data[i].reporting, name)) {
            newdata.push_back(data[i]);
        }
    }
    
    return newdata;
}
