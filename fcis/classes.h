#pragma once
#include <string>
#include<queue>
#include<map>
#include<unordered_set>
using namespace std;

class classes {
private:
    int id;
    int coach_id;
    string coachName;
    string title;
    string dateAndTime;
    int capacity;
    int size;
    static int classes_count;


public:
    queue<int>wait_list;
    queue<int>wait_list_vip;
    map<int, string> listOfMembers;
    classes();
    classes(int id, int coach_id, string title, string coach, string datetime, int cap);


    static int getclasscount();
    int getId() const;
    string getTitle() const;
    int getCoachID() const;
    string getCoachName() const;
    string getDateAndTime() const;
    int getCapacity() const;
    int getSize() const;

    static void decrementClassCount();
    void setId(int _id);
    void setTitle(string title);
    void setCoachName(string coach);
    void setDateAndTime(string datetime);
    void setCapacity(int cap);
    void setSize(int size);
};
