#pragma once
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

class member {
private:
    int id;
    string name;
    string date_of_birth;
    bool is_VIP;
    string password;
    stack<string> workout_history;
    static int member_count;
    queue<string> notifications;
    map<int, set<pair<string, int>>> booked_courts;

public:
    string subscription_type, subscription_expire;
    map<int, pair<pair<string, string>, string>> classes_id;
    vector<string>inbox; // TO STORE REMINDERS
    member();
    member(int id, string name, string date_of_birth, bool is_VIP, string password);
    map<int, pair<string, string>> subscriptions;

    //// SUBSCRIPTION 
    //void join_class(int class_id, const std::string& class_name, const std::string& expiry_date);
    //void cancel_class(int class_id);

    //// WORKOUT HISTORY
    //void add_workout(const std::string& workout);
    //void display_workouts() const;

    //// MESSAGES
    //void add_message(const std::string& msg);
    //void display_inbox() const;

    static int getMemberCount();

    int getId() const;
    string getName() const;
    string getDateOfBirth() const;
    bool getIsVIP() const;
    string getPassword() const;

    static void decrementMemberCount();
    void setId(int id);
    void setName(string name);
    void setDateOfBirth(string date_of_birth);
    void setIsVIP(bool is_VIP);
    void setPassword(string password);
    void addWorkout(const string& workout); // NEW
    void displayWorkouts() const; // NEW


    void addNotification(const std::string& message);
    std::string getNextNotification();
    bool hasNotifications() const;
    void addSubscription(int class_id, const std::string& start_date, const std::string& end_date);
    void removeSubscription(int class_id);
    const std::map<int, std::pair<std::string, std::string>>& getSubscriptions() const;
    void checkSubscriptionExpiry(const std::string& current_date);

};
