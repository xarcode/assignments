#include<iostream>
using namespace std;

struct DOB {
    int day, month, year;
};

class Person {
    private:
        string firstName, lastName, address;
        string city, state, zip, phone;
        DOB d;
        Person() {
            d.day = 0;
            d.month = 0;
            d.year = 0;
        }
    public:
        static Person *PersonArray(int n) {
            return new Person[n];
        }
        void getPersonDetails() {
            cout << "Enter First Name: ";
            cin >> firstName;
            cout << "Enter Last Name: ";
            cin >> lastName;
            cout << "Enter Address: ";
            cin.ignore();
            getline(cin, address);
            cout << "Enter City: ";
            cin >> city;
            cout << "Enter State: ";
            cin >> state;
            cout << "Zip Code: ";
            cin >> zip;
            cout << "Enter Phone: ";
            cin >> phone;
            cout << "Enter DOB(dd mm yyyy): ";
            cin >> d.day >> d.month >> d.year;
        }
        const void displayPersonDetails() {
            cout << "Full Name       : " << firstName << " " << lastName << endl;
            cout << "DOB(dd/mm/yyyy) : " << d.day << "/" << d.month << "/" << d.year << endl;
            cout << "Full Address    : " << address << ", " << city;
            cout << ", " << state << " (" << zip << ")" << endl;
            cout << "Phone No        : " << phone << endl;
        }
};

int main() {
    int n = 2;
    Person *p = Person::PersonArray(n);
    int i = 0;
    while(i < n) {
        cout << "----- Person - " << i + 1 << " -----" << endl;
        p[i].getPersonDetails();
        i++;
    }
    i = 0;
    system("cls");
    cout << "----- Persons List -----" << endl;
    while(i < n) {
        p[i].displayPersonDetails();
        cout << endl;
        i++;
    }
    return 0;
}