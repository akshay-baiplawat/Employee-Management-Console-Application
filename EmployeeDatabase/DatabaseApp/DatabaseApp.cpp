#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <thread>
#include"ManageRecords.h"
#include"ManagerRecords.h"
#include"SummaryRecoreds.h"
#include "RepotingTree.h"
#include "mySearchRecords.h"
#include "RegistryOp.h"


using namespace std;
vector<Employee> objects;

int main(){
    ManageRecords manage;
    int selected=10, ans=10, option=10;
    cout << "-> Where to load data from : " << endl;
    cout << "-> 1 for text file " << endl;
    cout << "-> 2 for Registry " << endl;
    cout << "-> " ;
    cin >> option;
    auto loadFunc = [&]() {
        manage.load(option);
    };
   thread loadThread(loadFunc);
    mySearchRecords search;
    string garbage;
    string name;
    string flow;
    vector<Employee> filterObjects;
    shared_ptr<ManagerRecords> Manager = make_shared<ManagerRecords>();

    while (true) {
        filterObjects = objects;
        cout << "   Select Option" << endl;
        cout << "-> 1 for Manage records" << endl;
        cout << "-> 2 for Search records" << endl;
        cout << "-> 3 for Manager's records" << endl;
        cout << "-> 4 for Repoting Tree" << endl;
        cout << "-> 5 for Summary of Recoreds" << endl;
        cout << "-> 6 for End program" << endl;
        cout << "-> ";
        
        cin >> selected;
        loadThread.join();
        switch (selected)
        {
        case 1:
            cout << endl;
            cout << "   Select Option" << endl;
            cout << "-> 1 for give input data" << endl;
            cout << "-> 2 for Show All" << endl;
            cout << "-> 3 for Delete record" << endl;
            cout << "-> ";
            cin >> option;
            if (option == 1) {
                cout << "-> 1 for Take Input" << endl;
            }
            else if (option == 2) {
                manage.showAll();
            }
            else if (option == 3) {
                cout << "-> 3 for Delete record" << endl;
            }
            else {
                cout << "-- Not a option --" << endl;
                break;
            }
            break;
        case 2:
            
            while (true)
            {

                cout << endl;
                cout << "   Select type of search"<<endl;
                cout << "-> 1 for Name" << endl;
                cout << "-> 2 for Age" << endl;
                cout << "-> 3 for Department" << endl;
                cout << "-> 4 for Designation" << endl;
                cout << "-> 5 for Reporting" << endl;
                cout << "-> 6 for End program" << endl;
                cout << "-> ";
                cin >> option;

                switch (option) {
                case 1:
                    cout << endl;
                    cout << "   Select search criteria" << endl;
                    cout << "-> 1 for search from starts / equals" << endl;
                    cout << "-> 2 for search from back" << endl;
                    cout << "-> 3 for search that contains" << endl;
                    cout << "-> 4 for search that not contains" << endl;
                    cout << "-> 6 for End program" << endl;
                    cout << "-> ";
                    cin >> option;
                    cout << endl;
                    cout << "-> Enter employee Name : ";
                    cin >> name;
                    cout << endl;
                    if (option == 6) {
                        return 1;
                    }
                    if (option == 1) {
                        flow = "start";

                    }else if (option == 2) {
                        flow = "end";
                    }else if (option == 3) {
                        flow = "contains";
                    }else if (option == 4) {
                        flow = "notContains";
                    }
                    else {
                        cout << "-- Not a option --" << endl;
                        break;
                    }
                    filterObjects=search.searchName(filterObjects,name,flow);
                    search.printdata(filterObjects);
                    if (filterObjects.size() == 0)
                        option = 6;
                    break;
                case 2:
                    cout << endl;
                    cout << "   Select search criteria" << endl;
                    cout << "-> 1 for search that's Age is greater then" << endl;
                    cout << "-> 2 for search that's Age is less then " << endl;
                    cout << "-> 3 for search that's Age is equal" << endl;
                    cout << "-> 4 for search that's Age is not equal " << endl;
                    cout << "-> 6 for End program" << endl;
                    cout << "-> ";
                    cin >> option;
                    if (option == 6) {
                        return 1;
                    }
                    cout << "-> Enter Age : ";
                    cin >> ans;
                    cout << endl;
                    if (option == 1) {
                        flow = ">";

                    }
                    else if (option == 2) {
                        flow = "<";
                    }
                    else if (option == 3) {
                        flow = "=";
                    }
                    else if (option == 4) {
                        flow = "!=";
                    }
                    else {
                        cout << "-- Not a option --" << endl;
                        break;
                    }
                    filterObjects=search.searchAge(filterObjects,ans,flow);
                    search.printdata(filterObjects);
                    if (filterObjects.size() == 0)
                        option = 6;
                    break;
                case 3:
                    cout << endl;
                    cout << "-> Enter employee Department : ";
                    cin >> name;
                    filterObjects=search.searchDepartment(filterObjects,name);
                    search.printdata(filterObjects);
                    if (filterObjects.size() == 0)
                        option = 6;
                    break;
                case 4:
                    cout << endl;
                    cout << "-> Enter employee Designation : ";
                    cin >> name;
                    filterObjects=search.searchDesignation(filterObjects,name);
                    search.printdata(filterObjects);
                    if (filterObjects.size() == 0)
                        option = 6;
                    break;
                case 5:
                    cout << endl;
                    cout << "-> Enter employee Reporting person name : ";
                    cin >> name;
                    filterObjects=search.searchReporting(filterObjects,name);
                    search.printdata(filterObjects);
                    if (filterObjects.size() == 0)
                        option = 6;
                    break;
                case 6:
                    return 1;
                default:
                    cout << endl;
                    cout << "-- Not a option --" << endl;
                    break;
                }
                if (option == 6)
                    break;
                cout << endl;
                cout << "   Want to apply one more filter" << endl;
                cout << "-> 1 for Yes" << endl;
                cout << "-> 2 for No" << endl;
                cout << "-> ";
                cin >> option;
                if (option == 2)
                    break;
                cout << endl;
                cout << "---Select one more filter---" << endl;
            }
            break;
        case 3:
            cout << " Manager's records"<<endl<< "Name of Manager : ";
            //getline(cin, name);
            cin >> name;
            Manager->repoted(name);
            break;
        case 4:
            cout << " Employee name : ";
            cin >> name;
            RepotingTree repoting;
            cout << name;
            repoting.repotedtree(name);
            break;
        case 5:
            cout << endl;
            cout << "   Select Option" << endl;
            cout << "-> 1 for Departments Summary" << endl;
            cout << "-> 2 for Designation Summary" << endl;
            cout << "-> 3 for Managers Summary" << endl;
            cout << "-> 6 for End program" << endl;
            cout << "-> ";
            cin >> option;
            SummaryRecoreds summary;
            if (option == 6) {
                return 1;
            }
            if (option == 1) {
            cout << "-> Departments Summary" << endl;
                summary.showDpartmentsSummary();
            }
            else if (option == 2) {
            cout << "-> Designation Summary" << endl;
                summary.showDesignationSummary();
                
            }
            else if (option == 3) {
            cout << "-> Managers Summary" << endl;
                summary.showManagerSummary();
            }
            else {
                cout << "-- Not a option --" << endl;
            }
            break;
            break;
        case 6:
            return 1;
        default:
            system("cls");
            cout << "-- Not a option --" << endl;
            break;
        }
        cout << " Wating enter any character !!!! ";
        cin >> garbage;
        system("cls");
    }
    return 0;
}