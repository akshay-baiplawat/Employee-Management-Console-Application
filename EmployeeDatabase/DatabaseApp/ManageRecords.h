#pragma once
#include<iostream>
#include <string>
#include <vector>
#include "RegistryOp.h"
using namespace std;
class Employee 
{
public:
    int id;
    string name;
    int age;
    string department;
    string designation;
    string reporting;
    Employee(int gid, string gname, int gage, string gdepartment, string gdesignation, string greporting = "--") {
        id = gid;
        name = gname;
        age = gage;
        department = gdepartment;
        designation = gdesignation;
        reporting = greporting;
    }

};
class ManageRecords : public RegistryOp
{

    public:
        void load(int option);
        void input();
        void showAll();
        void deleto(int Id);

};




