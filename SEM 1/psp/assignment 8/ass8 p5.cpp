#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person();
    int get_age()
    {
        return age;
    }

    void set_data(string s, int n)
    {
        name = s;
        age = n;
    }

    void show_data()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

Person::Person()
{
    name = "";
    age = -1;
}

class Record
{
private:
    Person *arr;
    int n;
public:
    Record(int sz);
    void show_eldest();
};

Record::Record(int sz)
{
    n = sz;
    arr = new Person[n];
    for(int i = 0; i < n; i++)
    {
        string name;
        int age;

        cout << "Enter name of Person " << i + 1 << ": ";
        cin >> name;
        cout << "Enter age of Person " << i + 1 << ": ";
        cin >> age;

        arr[i].set_data(name, age);
    }
}

void Record::show_eldest()
{
    int max_idx = 0;
    for(int i = 1; i < n; i++)
        if(this->arr[i].get_age() > this->arr[max_idx].get_age())
            max_idx = i;

    cout << "Eldest person is " << endl;
    this->arr[max_idx].show_data();
}

int main()
{
    Record record(4);
    record.show_eldest();
    return 0;
}