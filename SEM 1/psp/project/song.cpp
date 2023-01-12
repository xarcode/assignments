#include "song.hpp"
#include <algorithm>

using namespace std;

song::song(string _creator, string _name, int _duration, string _genre, string _album, string _date) : media(_creator, _name, _duration, _genre)
{
    album = _album;
    date = _date;
}

void song::set_album(std::string _album){ album = _album; }
void song::set_date(std::string _date){ date = _date; }

string song::get_album(){ return album; }
string song::get_date(){ return date; }

void song::display()
{
    cout << name << " by " << creator << " | " << duration << " mins" << endl;
    cout << "Album - " << album << " | Date of release - " << date << endl;
    cout << "--------------------------------------------------------\n";
}

void song::display_short()
{
    cout << "[s] " << name << " - " << creator << " | " << duration << " mins" << endl;
}

bool song::operator==(song obj)
{
    string curr_creator, curr_name, obj_creator, obj_name;

    curr_creator = creator;
    curr_name = name;
    obj_creator = obj.get_creator();
    obj_name = obj.get_name();

    transform(curr_creator.begin(), curr_creator.end(), curr_creator.begin(), ::tolower);
    transform(curr_name.begin(), curr_name.end(), curr_name.begin(), ::tolower);
    transform(obj_creator.begin(), obj_creator.end(), obj_creator.begin(), ::tolower);
    transform(obj_name.begin(), obj_name.end(), obj_name.begin(), ::tolower);

    return(obj_creator == curr_creator && obj_name == curr_name);
}