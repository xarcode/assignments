#include <iostream>
#include <string>

using namespace std;

struct student
{
    int roll;
    string name;
    int marks[4];
};

void getData(student &s, int i = 0)
{
    string show_student_number = "";
    if(i > 0) show_student_number = " " + to_string(i);
    getchar();
    cout << "Enter name of student" << show_student_number << ": "; getline(cin, s.name);
    cout << "Enter the roll number of student: "; cin >> s.roll;

    for(int i = 0; i < 4; i++)
    {
        cout << "Enter marks in subject " << i + 1 << ": "; cin >> s.marks[i];
    }
}

void showData(student s, int i = 0)
{
    string show_student_number = "";
    if(i > 0) show_student_number = " " + to_string(i);
    cout << "Name of student" << show_student_number << ": " << s.name << endl;
    cout << "Roll of student" << show_student_number << ": " << s.roll << endl;
    for(int i = 0; i < 4; i++)
    {
        cout << "Marks in subject " << i + 1 << ": " << s.marks[i] << endl;
    }
}

float getAvg(int a[], int n = 4)
{
    float sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];

    return sum / n;
}

int getTotal(int a[], int n = 4)
{
    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];

    return sum;
}

int main()
{
    int n;
     
    cout << "Enter number of students: "; cin >> n;

    student students[n];

    for(int i = 0; i < n; i++) getData(students[i], i + 1);

    cout << endl << "Average of each student as follows: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Roll Number: " << students[i].roll << "; Average: " << getAvg(students[i].marks) << endl;
        cout << "---------------------------------------" << endl; 
    }

    cout << endl << "Sorting the student array based on total marks..." << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(getTotal(students[j - 1].marks) > getTotal(students[j].marks))
            {
                student t = students[j - 1];
                students[j - 1] = students[j];
                students[j] = t;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Roll Number: " << students[i].roll << "; Total: " << getTotal(students[i].marks) << endl;
        cout << "---------------------------------------" << endl; 
    }

    return 0;
}