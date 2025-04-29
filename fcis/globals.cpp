#include "globals.h"
#include <iostream>
#include <chrono>
using namespace std;

 string globals::getCurrentDate() { // HELPER FUNCTION LEAVE AS IS

    auto now =  chrono::system_clock::now();
     time_t currentTime =  chrono::system_clock::to_time_t(now);

    struct tm tm {};
    localtime_s(&tm, &currentTime);
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tm);

    return string(buffer);
}

 string globals::addMonthsToDate(const  string& currentDate, int monthsToAdd) { 

    struct tm tm {};

    sscanf_s(currentDate.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
    tm.tm_year -= 1900;
    tm.tm_mon -= 1;

    tm.tm_mon += monthsToAdd;
    mktime(&tm);

    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tm);

    return  string(buffer);
}

staff globals::get_staff_by_id(int id) {
    if (staffs.find(id) != staffs.end()) {
        return staffs[id];
    }
    cout << "-------------------\nNo User Exist With This ID\n-------------------\n";
    return staff();
}

string globals::get_staff_pass_by_id(int id) {
    return staffs[id].getpassword();
}

string globals::get_staff_name_by_id(int id) {
    return staffs[id].getname();
}

string globals::get_member_pass_by_id(int id) {
    return members[id].getPassword();
}

void globals::add_staff_member(char role) {
    string name, date_of_birth, password;
    cout << "Enter name:\n";
    cin >> name;
    cout << "Enter date of birth:\n";
    cin >> date_of_birth;
    cout << "Enter password:\n";
    cin >> password;
    staff new_staff(staff::getstaffcount() + 1, name, date_of_birth, password, role);
    staffs[new_staff.getid()] = new_staff;
}

void globals::display_staff_member(int id) {
        cout << "-------------------\n";
        cout << "Name: " << staffs[id].getname() << endl;
        cout << "Date Of birth: " << staffs[id].getbirth() << endl;
        cout << "ID: " << staffs[id].getid() << endl;
        cout << "password: " << staffs[id].getpassword() << endl;
        cout << "role: " << staffs[id].getrole() << endl;
        cout << "-------------------\n";
}


void globals::add_member() {
    int c;
    string name, date_of_birth, password;
    bool is_VIP;
    cout << "Enter name:\n";
    cin >> name;
    cout << "Enter date of birth:\n";
    cin >> date_of_birth;
    cout << "Enter password:\n";
    cin >> password;
    cout << "VIP ?\n1 - yes\n2 - no\n";
    cin >> c;
    if (c == 1)
        is_VIP = true;
    else
        is_VIP = false;
    member new_member(member::getMemberCount() + 1, name, date_of_birth, is_VIP, password);
    members[new_member.getId()] = new_member;
}

void globals::display_member_by_id(int id) {
    cout << "-------------------\n";
    cout << "Name: " << members[id].getName() << endl;
    cout << "Date Of birth: " << members[id].getDateOfBirth() << endl;
    cout << "VIP: " << (members[id].getIsVIP() ? "Yes" : "No") << endl;
    cout << "ID: " << members[id].getId() << endl;
    cout << "password: " << members[id].getPassword() << endl;
    cout << "-------------------\n";
}

bool globals::is_member_exist(int id) {
    return members.find(id) != members.end();
}

member globals::get_member_by_id(int id) {
    return members[id];
}

void globals::display_member_classes_by_id(int id) {
    if (!members[id].classes_id.empty()) {
        for (const auto& entry : members[id].classes_id) {
            int class_id = entry.first;
            cout << "-------------------\n";
            cout << "Class Name: " << classess[class_id].getTitle() << endl;
            cout << "Join Date: " << entry.second.first.second << endl;
            cout << "-------------------\n";
        }
    }
    else cout << "-------------------\nYou haven't joined any classes yet\n-------------------\n";
}

void globals::display_member_inbox_by_id(int mem_id) {
    if (members[mem_id].inbox.size() > 0) {
        for (int i = 0; i < members[mem_id].inbox.size(); i++) {
            cout << "-------------------\n";
            cout << members[mem_id].inbox.at(i) << endl;
            cout << "-------------------\n";
        }
    }
    else
        cout << "-------------------\nYou Don't Have Messages yet\n-------------------\n";
}

void globals::remove_member() {
    int temp;
    if (members.size() > 0) {
        display_all_members();
        cout << "Enter Member ID\n";
        cin >> temp;
        if (is_member_exist(temp)) {
            members.erase(temp);
            member::decrementMemberCount();
            cout << "-------------------\nMember Removed Successfully\n-------------------\n";
        }
        else cout << "-------------------\nNo Member Exist With This ID\n-------------------\n";
    }
    else cout << "-------------------\nNo Members Yet\n-------------------\n";
}

void globals::display_all_members() {
    if (members.size() > 0) {
        for (auto i : members) {
            cout << "-------------------\n";
            cout << "member ID: " << i.first << endl;
            cout << "member Name: " << i.second.getName() << endl;
            cout << "member Date Of Birth: " << i.second.getDateOfBirth() << endl;
            cout << "VIP: " << (i.second.getIsVIP() ? "YES" : "NO") << endl;
            cout << "member Password: " << i.second.getPassword() << endl;
            cout << "-------------------\n";
        }
    }
    else cout << "-------------------\nNo Members Exist Yet\n-------------------\n";
}

bool globals::search_class_by_id(int mem_id, int class_id) {
    if (members.find(mem_id) != members.end()) {
        return members[mem_id].classes_id.find(class_id) != members[mem_id].classes_id.end();
    }
    return false;
}

void globals::add_class() {
    string title, coachName, dateAndTime;
    int coach_id;
    int capacity;
    cout << "Enter Class Name:\n";
    cin >> title;
    cout << "Enter Coach ID:\n";
    cin >> coach_id;
    if (staffs[coach_id].getrole() == 'c') {
        cout << "Enter Date and Time:\n";
        cin >> dateAndTime;
        cout << "Enter Class Capacity:\n";
        cin >> capacity;
        if (capacity > 0) {
            classes new_class(classes::getclasscount() + 1, coach_id, title, staffs[coach_id].getname(), dateAndTime, capacity);
            classess[new_class.getId()] = new_class;
            cout << "-------------------\nClass Added Successfully\n-------------------\n";
        }
        else cout << "-------------------\nThe Capacity Cannot be Zero\n-------------------\n";
    }
    else cout << "-------------------\nNo Coach With This ID\n-------------------\n";
}

void globals::display_classes() {
    if (classess.size() > 0) {
        for (auto i : classess) {
            cout << "-------------------\n";
            cout << "Class ID: " << i.first << endl;
            cout << "Class Name: " << i.second.getTitle() << endl;
            cout << "Coach ID: " << i.second.getCoachID() << endl;
            cout << "Coach Name: " << i.second.getCoachName() << endl;
            cout << "Date and Time: " << i.second.getDateAndTime() << endl;
            cout << "Capacity: " << i.second.getCapacity() << endl;
            cout << "Current Size: " << i.second.getSize() << endl;
            cout << "-------------------\n";
        }
    }
    else
        cout << "-------------------\nNo Classes Exist\n-------------------\n";
}

bool globals::is_class_exist(int class_id) {
    for (auto i : classess) {
        if (i.first == class_id) {
            return true;
        }
    }
    return false;
}

void globals::delete_class_by_id(int class_id) {
    classess.erase(class_id);
    classes::decrementClassCount();
    for (auto i : members) {
        i.second.classes_id.erase(class_id);
    }
}

string globals::get_subscription_plan(int period) { // NEW
    if (subscription_plans.find(period) != subscription_plans.end()) {
        return subscription_plans[period];
    }
    return "Invalid plan";
}

void globals::apply_subscription(int member_id, int class_id, int period) { // NEW
    string start_date = getCurrentDate();
    string end_date = addMonthsToDate(start_date, period);
    members[member_id].classes_id[class_id] = {
        {classess[class_id].getTitle(), start_date},
        end_date
    };
    classess[class_id].listOfMembers[member_id] = members[member_id].getName();
    classess[class_id].setSize(classess[class_id].getSize() + 1);
}

void globals::join_class(int member_id) { // UPDATED JOIN CLASS
    if (classess.empty()) {
        cout << "No classes available.\n";
        return;
    }

    display_classes();
    cout << "Enter Class ID to join:\n";
    int class_id;
    cin >> class_id;

    if (!is_class_exist(class_id)) {
        cout << "Invalid Class ID.\n";
        return;
    }

    auto& cls = classess[class_id];
    if (cls.listOfMembers.find(member_id) != cls.listOfMembers.end()) {
        cout << "You are already enrolled in this class.\n";
        return;
    }

    if (cls.getSize() < cls.getCapacity()) {
        string start_date = getCurrentDate();
        members[member_id].classes_id[class_id] = {
            {cls.getTitle(), start_date},  
            addMonthsToDate(start_date, 1) 
        };

        cls.listOfMembers[member_id] = members[member_id].getName();
        cls.setSize(cls.getSize() + 1);
        cout << "Successfully joined the class!\n";
    }
    else {
        if (members[member_id].getIsVIP()) {
            cls.wait_list_vip.push(member_id);
            cout << "Class full! Added to VIP waitlist.\n";
        }
        else {
            cls.wait_list.push(member_id);
            cout << "Class full! Added to regular waitlist.\n";
        }
    }
}

bool globals::is_staff_exist(int id) {
    return staffs.find(id) != staffs.end();
}

void globals::renew_subscription(int member_id, int class_id, int months) {
    if (members[member_id].classes_id.count(class_id)) {
        string new_expiry = addMonthsToDate(
            members[member_id].classes_id[class_id].second,
            months
        );
        members[member_id].classes_id[class_id].second = new_expiry;

        // Added notification for renewal
        string renewal_msg = "Your subscription for class '" +
            classess[class_id].getTitle() +
            "' has been renewed until " + new_expiry;
        members[member_id].inbox.push_back(renewal_msg);
    }
}

void globals::cancel_subscription(int mem_id, int class_id) {
    members[mem_id].classes_id.erase(class_id);
}

void globals::cancel_class(int member_id) {
    // CHECK IF MEMBER IS IN ANY CLASSES
    if (members[member_id].classes_id.size() > 0) { 
        display_member_classes_by_id(member_id);
        cout << "Enter Class ID to leave:\n";
        int class_id;
        cin >> class_id;

        if (is_class_exist(class_id) && classess[class_id].listOfMembers.erase(member_id)) {
            classess[class_id].setSize(classess[class_id].getSize() - 1);
            members[member_id].classes_id.erase(class_id);
            cout << "Successfully left the class.\n";

            auto& cls = classess[class_id]; 
            //CHECK VIP WAITLIST FIRST
            if (!cls.wait_list_vip.empty()) {
                // IF VIP -> POP
                int vip_member = cls.wait_list_vip.front();
                cls.wait_list_vip.pop();

                cls.listOfMembers[vip_member] = members[vip_member].getName();
                cls.setSize(cls.getSize() + 1);
                members[vip_member].inbox.push_back("You’ve been added to class " + cls.getTitle());
                // NOTIFICATION
                cout << "VIP member " << vip_member << " added from waitlist.\n";
            }
            // IF NO VIP -> CHECK REGULAR WAITLIST
            else if (!cls.wait_list.empty()) {
                int reg_member = cls.wait_list.front();
                cls.wait_list.pop();
                cls.listOfMembers[reg_member] = members[reg_member].getName();
                cls.setSize(cls.getSize() + 1);
                members[reg_member].inbox.push_back("You’ve been added to class " + cls.getTitle());
                cout << "Member " << reg_member << " added from waitlist.\n";
            }
        }
        else {
            cout << "You are not enrolled in this class.\n";
        }
    }
    else {
        cout << "You haven’t joined any classes yet.\n";
    }
}

void globals::add_work(int id, string work) { // UPDATED INSTEAD OF VECTOR USED STACK
    members[id].addWorkout(work);  // CALLS THE PUSH OF THE STACK
}

void globals::view_workout(int id) {
    members[id].displayWorkouts();
}

void globals::display_class_by_id(int id) {
    cout << "-------------------\n";
    cout << "Class ID: " << classess[id].getId() << endl;
    cout << "Class Name: " << classess[id].getTitle() << endl;
    cout << "Coach ID: " << classess[id].getCoachID() << endl;
    cout << "Coach Name: " << classess[id].getCoachName() << endl;
    cout << "Date and Time: " << classess[id].getDateAndTime() << endl;
    cout << "Capacity: " << classess[id].getCapacity() << endl;
    cout << "Current Size: " << classess[id].getSize() << endl;
    cout << "-------------------\n";
}

void globals::display_coach_classes_by_id(int id) {
    bool s = false;
    for (auto i : classess) {
        if (i.second.getCoachID() == id) {
            s = true;
            display_class_by_id(i.first);
        }
    }
    if (!s)
        cout << "-------------------\nYou Don't manage any class yet\n-------------------\n";
    
}

void globals::add_court() {
    int coachID;
    string location;
    string date;
    string time;
    cout << "Enter Court Location\n";
    cin >> location;
    cout << "Enter Court Time\n";
    cin >> time;
    cout << "Enter Court Date\n";
    cin >> date;
    cout << "Enter Coach ID\n";
    cin >> coachID;
    if (staffs[coachID].getrole() == 'c') {
        Padel p(Padel::getPadelCount() + 1, location, staffs[coachID].getname(), coachID, date, time);
        padels[p.getCourtID()] = p;
        cout << "-------------------\nAdded Successfully\n-------------------\n";
    }
    else cout << "-------------------\nInvalid Coach ID\n-------------------\n";
}

void globals::display_coach_courts_by_id(int id) {
    bool s = false;
    for (auto i : padels) {
        if (i.second.getCoachID() == id) {
            s = true;
            display_court_by_id(i.first);
        }
    }
    if (!s)
        cout << "-------------------\nYou Don't manage any courts yet\n-------------------\n";
    
}

void globals::display_court_by_id(int id) {
    cout << "-------------------\n";
    cout << "Court ID: " << padels[id].getCourtID() << "\n";
    cout << "Location: " << padels[id].getLocation() << "\n";
    cout << "Coach Name: " << padels[id].getCoachName() << "\n";
    cout << "Coach ID: " << padels[id].getCoachName() << "\n";
    cout << "Date & Time: " << padels[id].getDate() << " " << padels[id].getTime() << "\n";
    cout << "Status: " << (padels[id].getIsBooked() ? "Booked by " + padels[id].getBookedBy() : "Available") << "\n";
    cout << "-------------------\n";
}

void globals::display_padel_courts() {
    if (padels.size() > 0) {
        for (auto i : padels) {
            cout << "-------------------\n";
            cout << "Court ID: " << i.second.getCourtID() << "\n";
            cout << "Location: " << i.second.getLocation() << "\n";
            cout << "Coach Name: " << i.second.getCoachName() << "\n";
            cout << "Coach ID: " << i.second.getCoachID() << "\n";
            cout << "Date & Time: " << i.second.getDate() << " " << i.second.getTime() << "\n";
            cout << "Status: " << (i.second.getIsBooked() ? "Booked by " + i.second.getBookedBy() : "Available") << "\n";
            cout << "-------------------\n";
        }
    }
    else cout << "-------------------\nNo Courts Exist Yet\n-------------------\n";
}

bool globals::is_court_exist(int id) {
    return padels.find(id) != padels.end();
}

bool globals::is_court_booked(int id) {
    return (padels[id].getBookedBy() == "" ? true : false);
}

void globals::book_padel_court(int mem_id , int p_id) {
    padels[p_id].setBookedBy(members[mem_id].getName());
    padels[p_id].setIsBooked(true);
    cout << "-------------------\nBooked Succsessfully\n-------------------\n";
}

void globals::display_closest_time_court(string date, string time, string location , int mem_id) {
    bool found = false;
    int id;
    int c;
    for (auto& court : padels) {
        if (court.second.getLocation() == location &&
            court.second.getDate() == date &&
            court.second.getTime() > time ) {
            cout << "there is closest available court\n";
            cout << "-------------------\n";
            cout << "Court ID: " << court.second.getCourtID() << "\n";
            cout << "Location: " << court.second.getLocation() << "\n";
            cout << "Coach Name: " << court.second.getCoachName() << "\n";
            cout << "Coach ID: " << court.second.getCoachID() << "\n";
            cout << "Date & Time: " << court.second.getDate() << " " << court.second.getTime() << "\n";
            cout << "-------------------\n";
            id = court.first;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "-------------------\nNo available courts found\n-------------------\n";
    }
    else {
        cout << "Book It ?\n1 - yes\n2 - no\n";
        cin >> c;
        if (c == 1)
            book_padel_court(mem_id, id);
    }
}


void globals::display_court_by_date_time_loc(int mem_id) {
    bool found = false;
    int c, id;
    string date, time, loc;
    cout << "Enter Date:\n";
    cin >> date;
    cout << "Enter Time:\n";
    cin >> time;
    cout << "Enter Location\n";
    cin >> loc;
    for (auto& court : padels) {
        if (court.second.getLocation() == loc &&
            court.second.getDate() == date &&
            court.second.getTime() == time &&
            court.second.getIsBooked() == false) {
            found = true;
            id = court.second.getCourtID();
            cout << "-------------------\n";
            cout << "Court ID: " << court.second.getCourtID() << "\n";
            cout << "Location: " << court.second.getLocation() << "\n";
            cout << "Coach Name: " << court.second.getCoachName() << "\n";
            cout << "Coach ID: " << court.second.getCoachID() << "\n";
            cout << "Date & Time: " << court.second.getDate() << " " << court.second.getTime() << "\n";
            cout << "-------------------\n";
        }
    }
    if (!found) {
        cout << "-------------------\nThere is no available court\n-------------------\n";
    }
    else {
        cout << "Book It ?\n1 - yes\n2 - no\n";
        cin >> c;
        if (c == 1) {
            book_padel_court(mem_id, id);
        }
    }
}

void globals::remove_court() {
    int temp;
    if (padels.size() > 0) {
        display_padel_courts(); 
        cout << "Enter Court ID\n";
        cin >> temp;
        if (is_court_exist(temp)) {
            padels.erase(temp);
            Padel::decrementPadelCount();
            cout << "-------------------\nCourt Removed Successfully\n-------------------\n";
        }
        else cout << "-------------------\nNo Court Exist With This ID\n-------------------\n";
    }
    else cout << "-------------------\nNo Courts Exist Yet\n-------------------\n";
}

int globals::daysBetweenDates(const string& date1, const string& date2) {
    tm tm1 = {}, tm2 = {};
    istringstream ss1(date1), ss2(date2);
    ss1 >> std::get_time(&tm1, "%Y-%m-%d");
    ss2 >> std::get_time(&tm2, "%Y-%m-%d");

    if (ss1.fail() || ss2.fail()) return -1;

    tm1.tm_hour = tm2.tm_hour = 0;
    tm1.tm_min = tm2.tm_min = 0;
    tm1.tm_sec = tm2.tm_sec = 0;
    tm1.tm_isdst = tm2.tm_isdst = -1;

    time_t time1 = mktime(&tm1);
    time_t time2 = mktime(&tm2);

    if (time1 == -1 || time2 == -1) return -1;

    double difference = difftime(time2, time1) / (60 * 60 * 24);
    return static_cast<int>(difference);
}

void globals::checkAllSubscriptions() {
    string today = getCurrentDate();

    for (auto& member_pair : members) {
        member_pair.second.checkSubscriptionExpiry(today);

        while (member_pair.second.hasNotifications()) { // TO SEND NOTIFICATIONS 
            string msg = member_pair.second.getNextNotification();
            member_pair.second.inbox.push_back(msg);
        }
    }
}

void globals::sendEarlyRenewalOffers() {
    string today = getCurrentDate();

    for (auto& member_pair : members) {
        for (const auto& sub : member_pair.second.getSubscriptions()) {
            int class_id = sub.first;
            string expiry_date = sub.second.second;

            int days_remaining = daysBetweenDates(today, expiry_date);

            if (days_remaining >= 7 && days_remaining <= 14) {
                string offer_msg = "Special Offer: Renew your subscription for class '" +
                    classess[class_id].getTitle() +
                    "' now and get 10% discount!";
                member_pair.second.inbox.push_back(offer_msg);
            }
        }
    }
}

void globals::applyDiscount(int member_id, int class_id, int months) {
    if (!is_member_exist(member_id) || !is_class_exist(class_id)) return;

    if (members[member_id].classes_id.find(class_id) == members[member_id].classes_id.end()) {
        return;
    }

    string today = getCurrentDate();
    string expiry_date = members[member_id].classes_id[class_id].second;
    int days_remaining = daysBetweenDates(today, expiry_date);

    if (days_remaining >= 7) {
        string discount_msg = "10% discount applied to your renewal for class '" +
            classess[class_id].getTitle() + "'!";
        members[member_id].inbox.push_back(discount_msg);
    }

    renew_subscription(member_id, class_id, months);
}

void member::checkSubscriptionExpiry(const std::string& current_date) {
    for (const auto& sub : subscriptions) {
        int days_remaining = globals::daysBetweenDates(current_date, sub.second.second);

        if (days_remaining == 0) {
            addNotification("URGENT: Your subscription for class ID " +
                std::to_string(sub.first) + " expires today!");
        }
        else if (days_remaining <= 3) {
            addNotification("Reminder: Your subscription for class ID " +
                std::to_string(sub.first) + " expires in " +
                std::to_string(days_remaining) + " days.");
        }
        else if (days_remaining <= 7) {
            addNotification("Notice: Your subscription for class ID " +
                std::to_string(sub.first) + " will expire soon.");
        }
    }
}