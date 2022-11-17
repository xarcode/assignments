#include <iostream>

using namespace std;

class Average;

class Student
{
    private:
        string name;
        int marks[3];

    public:
        Student()
        {
            name = "";
            marks[0] = marks[1] = marks[2] = 0;
        }

        void get_data()
        {
            cout << "Enter the name of student: ";
            cin >> name;
            cout << "Enter the marks in subject 1: "; 
            cin >> marks[0];
            cout << "Enter the marks in subject 2: "; 
            cin >> marks[1];
            cout << "Enter the marks in subject 3: "; 
            cin >> marks[2];
        }

        friend class Average;
};

class Average
{
    public:
        float show_average(Student s)
        {
            return (s.marks[0] + s.marks[1] + s.marks[2]) / 3.0;
        }
};

int main()
{
    Student s;
    s.get_data();
    Average a;
    cout << "Average marks is " << a.show_average(s);
    return 0;
}