#pragma once
#include "media.hpp"

using namespace std;

class song : public media
{
private:
    string album;
    string date;
public:
    song(){}
    song(string _creator, string _name, int _duration, string album, string genre, string date);

    void set_album(std::string);
    void set_date(std::string);

    std::string get_album();
    std::string get_date();
    
    void display();
    void display_short();

    bool operator == (song);
};
