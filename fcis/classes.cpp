#include "classes.h"
#include <iostream>
using namespace std;

int classes::classes_count = 0;

classes::classes() {}

classes::classes(int id,int coach_id, string title, string coach, string datetime, int cap) {
    this->id = id;
    this->coach_id = coach_id;
    this->title = title;
    this->coachName = coach;
    dateAndTime = datetime;
    capacity = cap;
    setSize(0);
    classes_count++;
}


int classes::getclasscount() {
    return classes_count;
}

int classes::getId() const {
    return id;
}

string classes::getTitle() const {
    return title;
}

string classes::getCoachName() const {
    return coachName;
}

int classes::getCoachID() const {
    return coach_id;
}

string classes::getDateAndTime() const {
    return dateAndTime;
}

int classes::getCapacity() const {
    return capacity;
}

int classes::getSize() const {
    return size;
}

void classes::setId(int _id) {
    id = _id;
}

void classes::setTitle(string title) {
    this->title = title;
}

void classes::setCoachName(string coach) {
    coachName = coach;
}

void classes::setDateAndTime(string datetime) {
    dateAndTime = datetime;
}

void classes::setCapacity(int cap) {
    capacity = cap;
}

void classes::decrementClassCount() {
    classes_count--;
}

void classes::setSize(int size) {
    this->size = size;
}
