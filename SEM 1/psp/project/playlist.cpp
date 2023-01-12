#include "playlist.hpp"

playlist::playlist(string _name, string _creator, bool _is_public)
{
    name = _name;
    creator = _creator;
    is_public = _is_public;
    playlist_size = 0;
}

// getters
string playlist::get_name() { return name; }
string playlist::get_creator() { return creator; }
bool playlist::get_is_public() { return is_public; }

// setters
void playlist::set_name(string _name) { name = _name; }
void playlist::set_creator(string _creator) { creator = _creator; }
void playlist::set_is_public(bool _is_public) { is_public = _is_public; }

void playlist::add_song(song *s) { m[playlist_size++] = s; }
void playlist::add_podcast(podcast *p) { m[playlist_size++] = p; }

void playlist::display()
{
    cout << name << " by " << creator << " [Playlist]" << endl
         << endl;

    if (playlist_size > 0)
    {
        for (int i = 0; i < playlist_size; i++)
            m[i]->display_short();
    }
    else
        cout << "[] Empty Playlist" << endl;
    cout << "-------------------------------------------------------------\n";
}

ostream &operator<<(ostream &out, playlist &p)
{
    out << p.name << " by " << p.creator << " [Playlist]" << endl
        << endl;

    if (p.playlist_size > 0)
    {
        for (int i = 0; i < p.playlist_size; i++)
            p.m[i]->display_short();
    }
    else
        out << "[] Empty Playlist" << endl;
    out << "-------------------------------------------------------------\n";

    return out;
}