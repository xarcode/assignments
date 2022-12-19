#pragma once
#include <iostream>

class media
{
protected:
    std::string creator;
    std::string name;
    int duration;
    std::string genre;

public:
    media(){}
    media(std::string _creator, std::string _name, int _duration, std::string _genre);
    void set_creator(std::string _creator) { creator = _creator; }
    void set_name(std::string _name) { name = _name; }
    void set_duration(int _duration) { duration = _duration; }
    void set_genre(std::string _genre) { genre = _genre; }

    std::string get_creator() { return creator; }
    std::string get_name() { return name; }
    int get_duration() { return duration; }
    std::string get_genre() { return genre; }
    virtual void display() = 0;
    virtual void display_short() = 0;
};