#include "ManagerRecords.h"
#include "ManageRecords.h"
#include "CheckRecords.h"
#include<string>
#include<iostream>
#include "Globals.h"

using namespace std;

void ManagerRecords::repoted(string name) {
    int n = objects.size();
    int c = 0;
    for (int i = 1;i < n;i++) {
        if (SameCheck(objects[i].reporting, name)) {
            cout << "ID : " << objects[i].id << ", Name : " << objects[i].name << ", Age : " << objects[i].age << ", Department: " << objects[i].department << ", Designation : " << objects[i].designation << ", Reporting : " << objects[i].reporting << endl;
            c = 1;
        }
    }
    if (c == 0) {
        cout << "NOT FOUND!" << endl;
    }
    
}