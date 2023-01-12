#pragma once
#include "media.hpp"

using namespace std;

class podcast : public media
{
private:
    string episode, guests;
public:
    podcast(){}
    podcast(string _creator, string _name, int _duration, string _genre, string _episode, string _guest);

    void set_episode(string);
    void set_guests(string);

    string get_episode();
    string get_guests();

    void display();
    void display_short();

    bool operator==(podcast);
};