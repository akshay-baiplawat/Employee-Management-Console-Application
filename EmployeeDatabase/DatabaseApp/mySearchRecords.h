#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "CheckRecords.h"
#include"ManageRecords.h"
using namespace std;
class mySearchRecords :public CheckRecords
{
public:
	void printdata(vector<Employee> &data);
	vector<Employee> searchName(vector<Employee>& data,string name,string flow);
	vector<Employee> searchAge(vector<Employee>& data,int age, string flow);
	vector<Employee> searchDepartment(vector<Employee>& data,string name);
	vector<Employee> searchDesignation(vector<Employee>& data,string name);
	vector<Employee> searchReporting(vector<Employee>& data,string name);
	vector<Employee> filterObjects;
};

