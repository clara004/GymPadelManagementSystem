#include <iostream>
#include "staff.h"
#include "member.h"
#include "globals.h"
#include "classes.h"
using namespace std;

int main() {
    int choice, id, temp_id, temp_class_id;
    string password, temp;
    char role;
    globals g;

    g.add_staff_member('m');
    cout << "\n-------------------\nWelcome To Gym & Padel System :)\n-------------------\n";

    while (true) {
        static string last_checked_date = "";
        string current_date = g.getCurrentDate();

        if (current_date != last_checked_date) {
            g.checkAllSubscriptions();
            g.sendEarlyRenewalOffers();
            last_checked_date = current_date;
        }

        cout << "1 - login\n2 - sign-up\n3 - exit\n";
        cin >> choice;
        if (choice == 1) {
            cout << "login as:\n1 - member\n2 - staff\n0 - return back\n";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter Your ID:\n";
                cin >> id;
                if (g.is_member_exist(id)) {
                    cout << "Enter Your Password\n";
                    cin >> password;
                    temp = g.get_member_pass_by_id(id);
                    if (password == temp) {
                        cout << "-------------------\nWelcome " << g.members[id].getName() << endl;
                        member m = g.get_member_by_id(id);
                        while (true) {
                            cout << "1 - join class\n2 - cancel class\n3 - show all classes\n4 - show my classes\n5 - book padel court\n6 - search for available padel court\n7 - view my profile\n8 - view my workout history\n9 - view my messages\n10 - add work to my history\n11 - logout\n";
                            cin >> choice;
                            if (choice == 1) {
                                g.join_class(id);
                            }
                            else if (choice == 2) {
                                g.cancel_class(id);
                            }
                            else if (choice == 3) {
                                g.display_classes();
                            }
                            else if (choice == 4) {
                                g.display_member_classes_by_id(id);
                            }
                            else if (choice == 5) {
                                if (g.padels.size() > 0) {
                                    g.display_padel_courts();
                                    cout << "Enter ID of court to book it\n";
                                    cin >> temp_id;
                                    if (g.is_court_exist(temp_id)) {
                                        if (g.is_court_booked(temp_id)) {
                                            g.book_padel_court(id, temp_id);
                                        }
                                        else {
                                            cout << "-------------------\nThis is unavailable court\n-------------------\n";
                                            g.display_closest_time_court(g.padels[temp_id].getDate(), g.padels[temp_id].getTime(), g.padels[temp_id].getLocation(), id);
                                        }
                                    }
                                    else {
                                        cout << "-------------------\nThis court ID doesn't exist\n-------------------\n";
                                    }
                                }
                                else cout << "-------------------\nThere are no padel courts yet\n-------------------\n";
                            }
                            else if (choice == 6) {
                                g.display_court_by_date_time_loc(id);
                            }
                            else if (choice == 7) {
                                g.display_member_by_id(id);
                            }
                            else if (choice == 8) {
                                g.view_workout(id);
                            }
                            else if (choice == 9) {
                                g.display_member_inbox_by_id(id);
                            }
                            else if (choice == 10) {
                                string n;
                                cout << "enter your new work\n";
                                cin >> n;
                                g.add_work(id, n);
                            }
                            else if (choice == 11)
                                break;
                        }
                    }
                }
                else cout << "-------------------\nMember ID Not Found\n-------------------\n";
            }
            else if (choice == 2) {
                cout << "Enter Your ID:\n";
                cin >> id;

                if (g.is_staff_exist(id)) {
                    cout << "Enter Your Password:\n";
                    temp = g.get_staff_pass_by_id(id);
                    cin >> password;

                    if (temp == password) {
                        staff s = g.get_staff_by_id(id);
                        role = s.getrole();

                        if (role == 'm') {
                            cout << "\nWelcome Manager ";
                            cout << g.staffs[id].getname() << " :)\n";
                            while (true) {
                                cout << "1 - manage staff\n2 - manage members\n3 - manage classes\n4 - manage Courts\n5 - show my profile\n6 - logout\n";
                                cin >> choice;

                                if (choice == 1) {
                                    cout << "1 - add new staff member\n2 - search staff member by id\n0 - return back\n";
                                    cin >> choice;

                                    if (choice == 1) {
                                        cout << "1 - add manager\n2 - add coach\n3 - add receptionist\n0 - return back\n";
                                        cin >> choice;

                                        if (choice == 1) {
                                            g.add_staff_member('m');
                                            cout << "-------------------\nadded Successfully\n-------------------\n";
                                        }
                                        else if (choice == 2) {
                                            g.add_staff_member('c');
                                            cout << "-------------------\nadded Successfully\n-------------------\n";
                                        }
                                        else if (choice == 3) {
                                            g.add_staff_member('r');
                                            cout << "-------------------\nadded Successfully\n-------------------\n";
                                        }
                                        else if (choice == 0) {
                                            continue;
                                        }
                                        else {
                                            cout << "invalid choice\n";
                                        }
                                    }
                                    else if (choice == 2) {
                                        cout << "Enter ID\n";
                                        cin >> temp_id;
                                        if (g.is_staff_exist(temp_id)) {
                                            g.display_staff_member(temp_id);
                                        }
                                        else {
                                            cout << "-------------------\nNo member exist with this id\n-------------------\n";
                                        }
                                    }
                                    else if (choice == 0) {
                                        continue;
                                    }
                                }
                                else if (choice == 2) {
                                    cout << "1 - add new member\n2 - search member by id\n3 - remove member\n4 - Update subscription\n5 - show all members\n0 - return back\n";
                                    cin >> choice;

                                    if (choice == 1) {
                                        g.add_member();
                                        cout << "added Successfully\n";
                                    }
                                    else if (choice == 2) {
                                        cout << "Enter ID:\n";
                                        cin >> temp_id;
                                        if (g.is_member_exist(temp_id)) {
                                            g.display_member_by_id(temp_id);
                                        }
                                        else {
                                            cout << "-------------------\nNO member exist with this id\n-------------------\n";
                                        }
                                    }
                                    else if (choice == 3) {
                                        g.remove_member();
                                    }
                                    else if (choice == 4) {
                                        cout << "1 - Renew subscription\n2 - Cancel subscription\n0 - return back\n";
                                        cin >> choice;
                                        if (choice == 1) {
                                            g.display_all_members();
                                            cout << "Enter Member ID\n";
                                            cin >> temp_id;
                                            if (g.is_member_exist(temp_id)) {
                                                if (g.members[temp_id].classes_id.size() > 0) {
                                                    g.display_member_classes_by_id(temp_id);
                                                    cout << "Enter Class ID\n";
                                                    cin >> temp_class_id;
                                                    if (g.search_class_by_id(temp_id, temp_class_id)) {
                                                        cout << "Renew Subscription: \n1 - monthly\n2 - 3 months\n3 - 6 months\n4 - yearly\n";
                                                        cin >> choice;
                                                        if (choice == 1) {
                                                            g.renew_subscription(temp_id, temp_class_id, 1);
                                                            cout << "-------------------\nRenewed Successfully\n-------------------\n";
                                                        }
                                                        else if (choice == 2) {
                                                            g.renew_subscription(temp_id, temp_class_id, 3);
                                                            cout << "-------------------\nRenewed Successfully\n-------------------\n";
                                                        }
                                                        else if (choice == 3) {
                                                            g.renew_subscription(temp_id, temp_class_id, 6);
                                                            cout << "-------------------\nRenewed Successfully\n-------------------\n";
                                                        }
                                                        else if (choice == 4) {
                                                            g.renew_subscription(temp_id, temp_class_id, 12);
                                                            cout << "-------------------\nRenewed Successfully\n-------------------\n";
                                                        }
                                                        else cout << "-------------------\nInvalid Choice\n-------------------\n";
                                                    }
                                                    else cout << "-------------------\nInvalid Class ID\n-------------------\n";
                                                }
                                                else cout << "-------------------\nThis Member Doesn't joined to classes yet\n-------------------\n";
                                            }
                                            else cout << "-------------------\nNo member exist with this id\n-------------------\n";
                                        }
                                        else if (choice == 2) {
                                            g.display_all_members();
                                            cout << "Enter Member ID\n";
                                            cin >> temp_id;
                                            if (g.is_member_exist(temp_id)) {
                                                if (g.members[temp_id].classes_id.size() > 0) {
                                                    g.display_member_classes_by_id(temp_id);
                                                    cout << "Enter Class ID\n";
                                                    cin >> temp_class_id;
                                                    if (g.search_class_by_id(temp_id, temp_class_id)) {
                                                        g.cancel_subscription(temp_id, temp_class_id);
                                                    }
                                                    else cout << "-------------------\nInvalid Class ID\n-------------------\n";
                                                }
                                                else cout << "-------------------\nThis Member hasn't joined any classes yet\n-------------------\n";
                                            }
                                            else cout << "-------------------\nNo member exists with this id\n-------------------\n";
                                        }
                                        else if (choice == 0) {
                                            continue;
                                        }
                                    }
                                    else if (choice == 5) {
                                        g.display_all_members();
                                    }
                                    else if (choice == 0)
                                        continue;
                                }
                                else if (choice == 3) {

                                    cout << "1 - add Class\n2 - remove Class\n3 - show all classes\n0 - return back\n";
                                    cin >> choice;
                                    if (choice == 1) {
                                        g.add_class();
                                    }
                                    else if (choice == 2) {
                                        g.display_classes();
                                        cout << "Enter ID of class to remove\n";
                                        cin >> temp_class_id;
                                        if (g.is_class_exist(temp_class_id)) {
                                            g.delete_class_by_id(temp_class_id);
                                            cout << "-------------------\nDeleted Succsessfully\n-------------------\n";
                                        }
                                        else cout << "-------------------\nNo Class Exist With This ID\n-------------------\n";
                                    }
                                    else if (choice == 3) {
                                        g.display_classes();
                                    }
                                    else if (choice == 0)
                                        continue;
                                    else
                                        cout << "Invalid choice\n";
                                }
                                else if (choice == 4) {
                                    cout << "1 - add Court\n2 - remove Court\n3 - show all courts\n0 - return back\n";
                                    cin >> choice;
                                    if (choice == 1) {
                                        g.add_court();
                                    }
                                    else if (choice == 2) {
                                        g.remove_court();
                                    }
                                    else if (choice == 3) {
                                        g.display_padel_courts();
                                    }
                                    else if (choice == 0)
                                        continue;
                                }
                                else if (choice == 5) {
                                    g.display_staff_member(id);
                                }
                                else if (choice == 6)
                                    break;
                            }
                        }
                        else if (role == 'c') {
                            cout << "\nWelcome Coach ";
                            cout << g.staffs[id].getname() << " :)\n";
                            while (true) {
                                cout << "1 - manage member\n2 - manage classes\n3 - manage Courts\n4 - show my profile\n5 - logout\n";
                                cin >> choice;

                                if (choice == 1) {
                                    cout << "1 - add new member\n2 - search member by id\n3 - remove member by id\n4 - renewal subscription\n0 - return back\n";
                                    cin >> choice;

                                    if (choice == 1) {
                                        g.add_member();
                                        cout << "-------------------\nadded Successfully\n-------------------\n";
                                    }
                                    else if (choice == 2) {
                                        cout << "Enter ID:\n";
                                        cin >> temp_id;
                                        if (g.is_member_exist(temp_id)) {
                                            g.display_member_by_id(temp_id);
                                        }
                                        else {
                                            cout << "-------------------\nNo member exist with this id\n-------------------\n";
                                        }
                                    }
                                    else if (choice == 3) {
                                        g.remove_member();
                                    }
                                    else if (choice == 4) {
                                        cout << "1 - Renew subscription\n2 - Cancel subscription\n0 - return back\n";
                                        cin >> choice;
                                        if (choice == 1) {
                                            g.display_all_members();
                                            cout << "Enter Member ID\n";
                                            cin >> temp_id;
                                            if (g.is_member_exist(temp_id)) {
                                                if (g.members[temp_id].classes_id.size() > 0) {
                                                    g.display_member_classes_by_id(temp_id);
                                                    cout << "Enter Class ID\n";
                                                    cin >> temp_class_id;
                                                    if (g.search_class_by_id(temp_id, temp_class_id)) {
                                                        cout << "Renew Subscription: \n1 - monthly\n2 - 3 months\n3 - 6 months\n4 - yearly\n";
                                                        cin >> choice;
                                                        if (choice == 1) {
                                                            g.renew_subscription(temp_id, temp_class_id, 1);
                                                            cout << "-------------------\nRenewed Successfully\n-------------------\n";
                                                        }
                                                        else if (choice == 2) {
                                                            g.renew_subscription(temp_id, temp_class_id, 3);
                                                            cout << "-------------------\nRenewed Successfully\n-------------------\n";
                                                        }
                                                        else if (choice == 3) {
                                                            g.renew_subscription(temp_id, temp_class_id, 6);
                                                            cout << "-------------------\nRenewed Successfully\n-------------------\n";
                                                        }
                                                        else if (choice == 4) {
                                                            g.renew_subscription(temp_id, temp_class_id, 12);
                                                            cout << "-------------------\nRenewed Successfully\n-------------------\n";
                                                        }
                                                        else cout << "-------------------\nInvalid Choice\n-------------------\n";
                                                    }
                                                    else cout << "-------------------\nInvalid Class ID\n-------------------\n";
                                                }
                                                else cout << "-------------------\nThis Member Doesn't joined to classes yet\n-------------------\n";
                                            }
                                            else cout << "-------------------\nNo member exist with this id\n-------------------\n";
                                        }
                                        else if (choice == 2) {
                                            g.display_all_members();
                                            cout << "Enter Member ID\n";
                                            cin >> temp_id;
                                            if (g.is_member_exist(temp_id)) {
                                                if (g.members[temp_id].classes_id.size() > 0) {
                                                    g.display_member_classes_by_id(temp_id);
                                                    cout << "Enter Class ID\n";
                                                    cin >> temp_class_id;
                                                    if (g.search_class_by_id(temp_id, temp_class_id)) {
                                                        g.cancel_subscription(temp_id, temp_class_id);
                                                    }
                                                    else cout << "-------------------\nInvalid Class ID\n-------------------\n";
                                                }
                                                else cout << "-------------------\nThis Member Doesn't joined to classes yet\n-------------------\n";
                                            }
                                            else cout << "-------------------\nNo member exist with this id\n-------------------\n";
                                        }
                                        else if (choice == 0) {
                                            continue;
                                        }
                                    }
                                    else if (choice == 0)
                                        continue;
                                }
                                else if (choice == 2) {
                                    cout << "1 - add Class\n2 - remove Class\n3 - show all calsses\n4 - show my classes\n0 - return back\n";
                                    cin >> choice;
                                    if (choice == 1) {
                                        g.add_class();
                                    }
                                    else if (choice == 2) {
                                        g.display_classes();
                                        cout << "Enter ID of class to remove\n";
                                        cin >> temp_class_id;
                                        if (g.is_class_exist(temp_class_id)) {
                                            g.delete_class_by_id(temp_class_id);
                                            cout << "-------------------\nDeleted Succsessfully\n-------------------\n";
                                        }
                                        else cout << "-------------------\nNo Class Exist With This ID\n-------------------\n";
                                    }
                                    else if (choice == 3)
                                        g.display_classes();
                                    else if (choice == 4) {
                                        g.display_coach_classes_by_id(id);
                                    }
                                    else if (choice == 0)
                                        continue;
                                    else
                                        cout << "-------------------\nInvalid choice\n-------------------\n";
                                }
                                else if (choice == 3) {
                                    cout << "1 - add Court\n2 - remove Court\n3 - show all courts\n4 - show my courts\n0 - return back\n";
                                    cin >> choice;
                                    if (choice == 1) {
                                        g.add_court();
                                    }
                                    else if (choice == 2) {
                                        g.remove_court();
                                    }
                                    else if (choice == 3) {
                                        g.display_padel_courts();
                                    }
                                    else if (choice == 4) {
                                        g.display_coach_courts_by_id(id);
                                    }
                                    else if (choice == 0)
                                        continue;
                                }
                                else if (choice == 4) {
                                    g.display_staff_member(id);
                                }
                                else if (choice == 5)
                                    break;
                            }
                        }
                        else if (role == 'r') {
                            cout << "\nWelcome Reception ";
                            cout << g.staffs[id].getname() << " :)\n";
                            while (true) {
                                cout << "1 - manage staff\n2 - manage member\n3 - manage classes\n4 - manage Courts\n5 - show my profile\n6 - logout\n";
                                cin >> choice;

                                if (choice == 1) {
                                    cout << "1 - add new staff member\n2 - search staff member by id\n0 - return back\n";
                                    cin >> choice;

                                    if (choice == 1) {
                                        cout << "1 - add coach\n2 - add receptionist\n0 - return back\n";
                                        cin >> choice;

                                        if (choice == 1) {
                                            g.add_staff_member('c');
                                            cout << "-------------------\nadded Successfully\n-------------------\n";
                                        }
                                        else if (choice == 2) {
                                            g.add_staff_member('r');
                                            cout << "-------------------\nadded Successfully\n-------------------\n";
                                        }
                                        else if (choice == 0) {
                                            continue;
                                        }
                                        else {
                                            cout << "-------------------\ninvalid choice\n-------------------\n";
                                        }
                                    }
                                    else if (choice == 2) {
                                        cout << "Enter ID\n";
                                        cin >> temp_id;
                                        if (g.is_staff_exist(temp_id)) {
                                            g.display_staff_member(temp_id);
                                        }
                                        else {
                                            cout << "-------------------\nNo member exist with this id\n-------------------\n";
                                        }
                                    }
                                    else if (choice == 0) {
                                        continue;
                                    }
                                }
                                else if (choice == 2) {
                                    cout << "1 - add new member\n2 - search member by id\n3 - renewal subscription\n0 - return back\n";
                                    cin >> choice;

                                    if (choice == 1) {
                                        g.add_member();
                                        cout << "-------------------\nadded Successfully\n-------------------\n";
                                    }
                                    else if (choice == 2) {
                                        cout << "Enter ID:\n";
                                        cin >> temp_id;
                                        if (g.is_member_exist(temp_id))
                                            g.display_member_by_id(temp_id);
                                        else
                                            cout << "-------------------\nNo member exist with this id\n-------------------\n";
                                    }
                                    else if (choice == 3) {
                                        cout << "1 - Renew subscription\n2 - Cancel subscription\n0 - return back\n";
                                        cin >> choice;
                                        if (choice == 1) {
                                            g.display_all_members();
                                            cout << "Enter Member ID\n";
                                            cin >> temp_id;
                                            if (g.is_member_exist(temp_id)) {
                                                if (g.members[temp_id].classes_id.size() > 0) {
                                                    g.display_member_classes_by_id(temp_id);
                                                    cout << "Enter Class ID\n";
                                                    cin >> temp_class_id;
                                                    if (g.search_class_by_id(temp_id, temp_class_id)) {
                                                        cout << "Renew Subscription: \n1 - monthly\n2 - 3 months\n3 - 6 months\n4 - yearly\n";
                                                        cin >> choice;
                                                        if (choice == 1) {
                                                            g.renew_subscription(temp_id, temp_class_id, 1);
                                                            cout << "-------------------\nRenewed Successfully\n-------------------\n";
                                                        }
                                                        else if (choice == 2) {
                                                            g.renew_subscription(temp_id, temp_class_id, 3);
                                                            cout << "-------------------\nRenewed Successfully\n-------------------\n";
                                                        }
                                                        else if (choice == 3) {
                                                            g.renew_subscription(temp_id, temp_class_id, 6);
                                                            cout << "-------------------\nRenewed Successfully\n-------------------\n";
                                                        }
                                                        else if (choice == 4) {
                                                            g.renew_subscription(temp_id, temp_class_id, 12);
                                                            cout << "-------------------\nRenewed Successfully\n-------------------\n";
                                                        }
                                                        else cout << "-------------------\nInvalid Choice\n-------------------\n";
                                                    }
                                                    else cout << "-------------------\nInvalid Class ID\n-------------------\n";
                                                }
                                                else cout << "-------------------\nThis Member Doesn't joined to classes yet\n-------------------\n";
                                            }
                                            else cout << "-------------------\nNo member exist with this id\n-------------------\n";
                                        }
                                        else if (choice == 2) {
                                            g.display_all_members();
                                            cout << "Enter Member ID\n";
                                            cin >> temp_id;
                                            if (g.is_member_exist(temp_id)) {
                                                if (g.members[temp_id].classes_id.size() > 0) {
                                                    g.display_member_classes_by_id(temp_id);
                                                    cout << "Enter Class ID\n";
                                                    cin >> temp_class_id;
                                                    if (g.search_class_by_id(temp_id, temp_class_id)) {
                                                        g.cancel_subscription(temp_id, temp_class_id);
                                                    }
                                                    else cout << "-------------------\nInvalid Class ID\n-------------------\n";
                                                }
                                                else cout << "-------------------\nThis Member Doesn't joined to classes yet\n-------------------\n";
                                            }
                                            else cout << "-------------------\nNo member exist with this id\n-------------------\n";
                                        }
                                        else if (choice == 0) {
                                            continue;
                                        }
                                    }
                                    else if (choice == 0) {
                                        continue;
                                    }
                                }
                                else if (choice == 3) {
                                    cout << "1 - add Class\n2 - remove Class\n3 - show all classes\n0 - return back\n";
                                    cin >> choice;
                                    if (choice == 1) {
                                        g.add_class();
                                    }
                                    else if (choice == 2) {
                                        g.display_classes();
                                        cout << "Enter ID of class to remove\n";
                                        cin >> temp_class_id;
                                        if (g.is_class_exist(temp_class_id)) {
                                            g.delete_class_by_id(temp_class_id);
                                            cout << "-------------------\nDeleted Successfully\n-------------------\n";
                                        }
                                        else cout << "-------------------\nNo Class Exist With This ID\n-------------------\n";
                                    }
                                    else if (choice == 3)
                                        g.display_classes();
                                    else if (choice == 0)
                                        continue;
                                    else
                                        cout << "-------------------\nInvalid choice\n-------------------\n";
                                }
                                else if (choice == 4) {
                                    cout << "1 - add Court\n2 - remove Court\n3 - show all courts\n0 - return back\n";
                                    cin >> choice;
                                    if (choice == 1) {
                                        g.add_court();
                                    }
                                    else if (choice == 2) {
                                        g.remove_court();
                                    }
                                    else if (choice == 3) {
                                        g.display_padel_courts();
                                    }
                                    else if (choice == 0)
                                        continue;
                                }
                                else if (choice == 5) {
                                    g.display_staff_member(id);
                                }
                                else if (choice == 6) {
                                    break;
                                }
                            }
                        }
                    }
                    else {
                        cout << "-------------------\nWrong Password\n-------------------\n";
                    }
                }
                else {
                    cout << "-------------------\nStaff ID not found\n-------------------\n";
                }
            }
            else if (choice == 0) {
                continue;
            }
            else {
                cout << "-------------------\nInvalid choice\n-------------------\n";
            }
        }
        else if (choice == 2) {
            cout << "-------------------\nYou are now signing up as a member\n-------------------\n";
            g.add_member();
        }
        else if (choice == 3) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "-------------------\nInvalid choice\n-------------------\n";
        }
    }

    return 0;
}
