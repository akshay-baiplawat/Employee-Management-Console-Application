#pragma once

#include <iostream>
#include <string>
using namespace std;

// Function declarations
class CheckRecords
{
public:

    CheckRecords()
    {

    }

    ~CheckRecords()
    {

    }

public:
    bool SameCheck(string name1, string name2);
    bool EndSameCheck(string name1, string name2);
    bool ContainsCheck(string name1, string name2);
};
