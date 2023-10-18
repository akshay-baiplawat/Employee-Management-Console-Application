#include "SummaryRecoreds.h"
#include "Globals.h"
#include<string>
#include<iostream>
#include <map>
using namespace std;

void SummaryRecoreds::showDpartmentsSummary() {
    int n = objects.size();
    map<string, int> difftime;
    for (int i = 0;i < n;i++) {
        if (difftime[objects[i].department]) {
            difftime[objects[i].department] += 1;
        }
        else {
            difftime[objects[i].department] = 1;
        }
    }

    for (auto it : difftime) {
        pair<string, int> pr = it;
        cout << "Department : " << pr.first << " , Count : " << pr.second << endl;
    }

}
void SummaryRecoreds::showDesignationSummary() {
    int n = objects.size();
    map<string, int> difftime;
    for (int i = 0;i < n;i++) {
        if (difftime[objects[i].designation]) {
            difftime[objects[i].designation] += 1;
        }
        else {
            difftime[objects[i].designation] = 1;
        }
    }

    for (auto it : difftime) {
        pair<string, int> pr = it;
        cout << "Designation : " << pr.first << " , Count : " << pr.second << endl;
    }

}

void SummaryRecoreds::showManagerSummary() {
    int n = objects.size();
    map<string, int> difftime;
    for (int i = 1;i < n;i++) {
        if (difftime[objects[i].reporting]) {
            difftime[objects[i].reporting] += 1;
        }
        else {
            difftime[objects[i].reporting] = 1;
        }
    }

    for (auto it : difftime) {
        pair<string, int> pr = it;
        cout << "Name : " << pr.first << " , Count : " << pr.second << endl;
    }

}

