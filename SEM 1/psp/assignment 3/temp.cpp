#include <iostream>

void print(); 

int main()
{
    char a[] = "Good morning!";
    char *p = a;
    p += 5;
    std::cout << p;
    return 0;
}

// void print()
// {
//     std::cout << "prnt";
// }