#pragma once
#include <iostream>
#include <string>
using namespace std;

class Padel {
private:
    int courtID;
    int coachID;
    string location;
    string coachName;
    string date;
    string time;
    bool isBooked;
    string bookedBy;
    static int padel_count;

public:

    Padel();
    Padel(int id, string loc, string coach, int coachID, string d, string t);

    int getCourtID() const;
    static int getPadelCount();
    string getLocation() const;
    string getCoachName() const;
    string getDate() const;
    string getTime() const;
    bool getIsBooked() const;
    string getBookedBy() const;
    int getCoachID() const;

    static void decrementPadelCount();
    void setCoachID(int id);
    void setPadelCount(int id);
    void setCourtID(int id);
    void setLocation(const string& loc);
    void setCoachName(const string& coach);
    void setDate(const string& d);
    void setTime(const string& t);
    void setIsBooked(bool booked);
    void setBookedBy(const string& name);
};
