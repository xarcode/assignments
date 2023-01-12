#include <iostream>

using namespace std;

class Counter
{
private:
    int count;

public:
    Counter();
    Counter operator++(int)
    {
        Counter c = *this;
        count++;
        return c;
    }
    Counter operator--(int)
    {
        Counter c = *this;
        count--;
        return c;
    }
    void show() { cout << "Number of persons: " << count << endl; }
};

Counter::Counter()
{
    int count = 0;
}

int main()
{
    Counter c;
    while (1)
    {
        cout << "1. Person Entering Bank" << endl;
        cout << "2. Person Leaving Bank" << endl;
        cout << "3. Show Number of People in Bank" << endl;
        cout << "0. Exit Program" << endl;
        cout << "\nEnter choice" << endl;
        int choice;
        cin >> choice;

        if (!choice)
            break;

        switch (choice)
        {
        case 1:
            c++;
            break;
        case 2:
            c--;
            break;
        case 3:
            c.show();
            break;
        default:
            cout << "Wrong choice..." << endl;
            break;
        }
    }
    return 0;
}