#include "staff.h"
#include "globals.h"
#include <iostream>
using namespace std;

int staff::staff_count = 0;

staff::staff() {
    id = 0;
    name = "";
    role = 'n';
    date_of_birth = "";
    password = "";
}

staff::staff(int id, string name, string date_of_birth, string password, char role) {
    this->id = id;
    this->name = name;
    this->date_of_birth = date_of_birth;
    this->password = password;
    this->role = role;
    staff_count++;
}

int staff::getstaffcount() {
    return staff_count;
}

int staff::getid() {
    return id;
}

void staff::setid(int id) {
    this->id = id;
}

void staff::setname(string name) {
    this->name = name;
}

void staff::setrole(char role) {
    this->role = role;
}

void staff::setpassword(string pass) {
    this->password = pass;
}

void staff::setbirth(string birth) {
    date_of_birth = birth;
}

string staff::getname() {
    return name;
}

char staff::getrole() {
    return role;
}

string staff::getpassword() {
    return password;
}

string staff::getbirth() {
    return date_of_birth;
}

void staff::decrementStaffCount() {
    staff_count--;
}

staff staff::get_info() {
    staff s;
    s.setid(getid());
    s.setname(getname());
    s.setrole(getrole());
    s.setpassword(getpassword());
    s.setbirth(getbirth());
    return s;
}

//bool staff::is_staff_exist(int id) {
//    return staffs.find(id) != staffs.end();
//}
//
//void staff::get_staff_by_id(int id) {
//    if (staffs.find(id) != staffs.end()) {
//        return staffs[id];
//    }
//    cout << "-------------------\nNo User Exist With This ID\n-------------------\n";
//    return staff();
//}

//void staff::assign_class(int class_id) {
//    coach_classes[this->id].insert(class_id);
//}
//
//const std::set<int>& staff::get_assigned_classes() const {
//    static const std::set<int> empty_set;
//    auto it = coach_classes.find(this->id);
//    return (it != coach_classes.end()) ? it->second : empty_set;
//}
