#include "Padel.h"
using namespace std;

int Padel::padel_count = 0;

Padel::Padel() : courtID(0), isBooked(false), bookedBy("") {}

Padel::Padel(int id, string loc, string coach, int coachID, string d, string t)
    : courtID(id), location(loc), coachName(coach), date(d), time(t), isBooked(false), bookedBy(""), coachID(coachID) {
    padel_count++;
}


int Padel::getPadelCount() { return padel_count; }
int Padel::getCoachID()const { return coachID; }
int Padel::getCourtID() const { return courtID; }
string Padel::getLocation() const { return location; }
string Padel::getCoachName() const { return coachName; }
string Padel::getDate() const { return date; }
string Padel::getTime() const { return time; }
bool Padel::getIsBooked() const { return isBooked; }
string Padel::getBookedBy() const { return bookedBy; }

void Padel::decrementPadelCount() {
    padel_count--;
}
void Padel::setPadelCount(int id) { padel_count = id; }
void Padel::setCoachID(int id) { coachID = id; }
void Padel::setCourtID(int id) { courtID = id; }
void Padel::setLocation(const string& loc) { location = loc; }
void Padel::setCoachName(const string& coach) { coachName = coach; }
void Padel::setDate(const string& d) { date = d; }
void Padel::setTime(const string& t) { time = t; }
void Padel::setIsBooked(bool booked) { isBooked = booked; }
void Padel::setBookedBy(const string& name) { bookedBy = name; }
