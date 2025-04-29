#include "member.h"
#include <iostream>
using namespace std;

int member::member_count = 0;

member::member() {
    id = 0;
    name = "";
    date_of_birth = "";
    is_VIP = false;
    password = "";
}

member::member(int id, string name, string date_of_birth, bool is_VIP, string password) {
    this->id = id;
    this->name = name;
    this->date_of_birth = date_of_birth;
    this->is_VIP = is_VIP;
    this->password = password;
    member_count++;
}

int member::getMemberCount() {
    return member_count;
}

int member::getId() const {
    return id;
}

string member::getName() const {
    return name;
}

string member::getDateOfBirth() const {
    return date_of_birth;
}

void member::decrementMemberCount() {
    member_count--;
}

bool member::getIsVIP() const {
    return is_VIP;
}

string member::getPassword() const {
    return password;
}

void member::setId(int id) {
    this->id = id;
}

void member::setName(string name) {
    this->name = name;
}

void member::setDateOfBirth(string date_of_birth) {
    this->date_of_birth = date_of_birth;
}

void member::setIsVIP(bool is_VIP) {
    this->is_VIP = is_VIP;
}

void member::setPassword(string password) {
    this->password = password;
}

void member::addWorkout(const std::string& workout) {
    workout_history.push(workout);
}

void member::displayWorkouts() const {
    if (workout_history.empty()) {
        cout << "No workouts recorded yet.\n";
        return;
    }

    stack<string> temp = workout_history;
    int index = 1;

    while (!temp.empty()) {
        cout << index++ << ": " << temp.top() << "\n"; 
        temp.pop();  
    }
}

// NEW (NOTIFICATION LOGIC)

void member::addNotification(const string& message) {
    notifications.push(message);
}

string member::getNextNotification() {
    if (notifications.empty()) return "";
    string msg = notifications.front();
    notifications.pop();
    return msg;
}

bool member::hasNotifications() const {
    return !notifications.empty();
}

void member::addSubscription(int class_id, const string& start_date, const string& end_date) {
    subscriptions[class_id] = { start_date, end_date };
}

void member::removeSubscription(int class_id) {
    subscriptions.erase(class_id);
}

const map<int, pair<string, string>>& member::getSubscriptions() const {
    return subscriptions;
}