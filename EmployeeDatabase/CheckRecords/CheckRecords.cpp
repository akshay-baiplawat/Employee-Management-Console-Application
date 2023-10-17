#include "CheckRecords.h"

using namespace std;

bool CheckRecords::SameCheck(string name1, string name2) {
    int n1 = name1.size();
    int n2 = name2.size();
    for (int i = 0; i < min(n1, n2);i++) {
        if (name1[i] != name2[i]) {
            return false;
        }
    }
    return true;
}

bool CheckRecords::EndSameCheck(string name1, string name2) {

    int n1 = name1.size();
    int n2 = name2.size();
    int p1 = n1 - 1, p2 = n2 - 1;
    for (int i = min(n1, n2) - 1; i >= 0;i--, p1--, p2--) {
        if (name1[p1] != name2[p2]) {
            return false;
        }
    }
    return true;
}

bool CheckRecords::ContainsCheck(string name1, string name2) {
    int n1 = name1.size();
    int n2 = name2.size();

    for (int i = 0; i <= n1 - n2; i++) {
        int j;
        for (j = 0; j < n2; j++) {
            if (name1[i + j] != name2[j]) {
                break;  // Characters don't match, move to the next position in name1
            }
        }
        if (j == n2) {
            return true;  // All characters matched, name1 contains name2
        }
    }
    return false;  // No match found, name1 does not contain name2
}