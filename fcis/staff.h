#pragma once
#include <string>
#include <map>
#include <set>
using namespace std;

class staff {
private:
    int id;
    string name;
    string date_of_birth;
    string password;
    char role;
    static int staff_count;
    map<int, std::set<int>> coach_classes;

public:
    staff();
    staff(int id, string name, string date_of_birth, string password, char role);
    //void assign_class(int class_id);
    //void remove_class(int class_id);
    //const std::set<int>& get_assigned_classes() const;

    static int getstaffcount();

    int getid();
    string getname();
    char getrole();
    string getpassword();
    string getbirth();

    static void decrementStaffCount();
    void setid(int id);
    void setname(string name);
    void setrole(char role);
    void setpassword(string pass);
    void setbirth(string birth);

    //bool is_staff_exist(int id);
    //void get_staff_by_id(int id);

    staff get_info();
};
