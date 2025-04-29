#pragma once
#include <vector>
#include <map>
#include <chrono>
#include <ctime>
#include <sstream>
#include "staff.h"
#include "classes.h"
#include "member.h"
#include "padel.h"
using namespace std;

class globals {
public:
    map <int, staff> staffs;
    map <int, member> members;
    map <int, classes> classess;
    map <int, Padel> padels;
    map<int, string> subscription_plans = {
        {1, "1 month (Price: $500)"},
        {3, "3 months (Price: $1200)"},
        {6, "6 months (Price: $2500)"},
        {12, "12 months (Price: $5300)"}
    };

    static int daysBetweenDates(const std::string& date1, const std::string& date2);

    string getCurrentDate();
    string addMonthsToDate(const string& currentDate, int monthsToAdd);

    staff get_staff_by_id(int id);
    string get_staff_pass_by_id(int id);
    bool is_staff_exist(int id);
    void display_staff_member(int id);
    void add_staff_member(char role);
    string get_staff_name_by_id(int id);

    member get_member_by_id(int id);
    string get_member_pass_by_id(int mem_id);
    bool is_member_exist(int mem_id);
    void display_member_by_id(int mem_id);
    void display_member_classes_by_id(int mem_id);
    void add_member();
    void display_all_members();
    void display_member_inbox_by_id(int mem_id);

    // SUBSCRIPTION LOGIC TO BE UPDATED 
    void renew_subscription(int mem_id,int class_id,int period);
    void cancel_subscription(int mem_id, int class_id);
    void apply_subscription(int id, int class_id, int period);
    string get_subscription_plan(int period);
    void remove_member();

    // NEW

    void checkAllSubscriptions();
    void sendEarlyRenewalOffers();
    void applyDiscount(int member_id, int class_id, int months);

    void display_class_by_id(int id);
    void display_coach_classes_by_id(int id);
    void add_class();
    bool search_class_by_id(int mem_id, int class_id);
    void display_classes();
    bool is_class_exist(int class_id);
    void delete_class_by_id(int class_id);
    void join_class(int id);
    void cancel_class(int id);
    void view_workout(int id);
    void add_work(int id,string work);

    void add_court();
    void display_padel_courts();
    bool is_court_exist(int id);
    bool is_court_booked(int id);
    void display_coach_courts_by_id(int id);
    void display_court_by_id(int id);
    void book_padel_court(int mem_id , int p_id);
    void display_closest_time_court(string date, string time, string location , int mem_id);
    void display_court_by_date_time_loc(int mem_id);
    void remove_court();

};
