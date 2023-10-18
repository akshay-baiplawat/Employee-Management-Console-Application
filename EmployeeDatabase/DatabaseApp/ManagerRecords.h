#pragma once
#include<string>
#include<iostream>
#include "CheckRecords.h"
using namespace std;

class ManagerRecords:public CheckRecords
{
public:
	void repoted(string name);
};

