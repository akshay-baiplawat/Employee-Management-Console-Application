#include "RepotingTree.h"
#include "Globals.h"
#include<string>
#include<iostream>
#include "CheckRecords.h"
using namespace std;

void RepotingTree::repotedtree(string name) {
    int n = objects.size();
    for (int i = 0;i < n;i++) {
        if (SameCheck(objects[i].name, name)) {
            cout << " -> " << objects[i].reporting;
            RepotingTree::repotedtree(objects[i].reporting);

        }
    }
    cout << endl;
}
