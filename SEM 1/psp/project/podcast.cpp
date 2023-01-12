#include "podcast.hpp"
#include <algorithm>

podcast::podcast(string _creator, string _name, int _duration, string _genre, string _episode, string _guest) : media(_creator, _name, _duration, _genre)
{
    episode = _episode;
    guests = _guest;
}

void podcast::set_episode(string _episode) { episode = _episode; }
void podcast::set_guests(string _guests){ guests = _guests; }

string podcast::get_episode(){ return episode; }
string podcast::get_guests(){ return guests; }

void podcast::display()
{
    cout << name << " by " << creator << " | " << duration << " mins" << endl;
    cout << episode << " / " << guests << endl;
    cout << "--------------------------------------------------------\n";
}

void podcast::display_short()
{
    cout << "[p] " << name << " by " << creator << " | " << episode << " / " << guests << endl;
}

bool podcast::operator==(podcast obj)
{
    string curr_episode, curr_name, obj_episode, obj_name;

    curr_episode = episode;
    curr_name = name;
    obj_episode = obj.get_episode();
    obj_name = obj.get_name();

    transform(curr_episode.begin(), curr_episode.end(), curr_episode.begin(), ::tolower);
    transform(curr_name.begin(), curr_name.end(), curr_name.begin(), ::tolower);
    transform(obj_name.begin(), obj_name.end(), obj_name.begin(), ::tolower);
    transform(obj_name.begin(), obj_name.end(), obj_name.begin(), ::tolower);

    return(obj_episode == curr_episode && obj_name == curr_name);
}