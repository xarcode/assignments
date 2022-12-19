#pragma once
#include "media.hpp"
#include "song.hpp"
#include "podcast.hpp"

class playlist
{
private:
    string name;
    string creator;
    bool is_public;
    media *m[100];
    int playlist_size;

public:
    playlist() {}
    playlist(string, string, bool);

    // getters
    string get_name();
    string get_creator();
    bool get_is_public();

    // setters
    void set_name(string);
    void set_creator(string);
    void set_is_public(bool);

    void add_song(song *);
    void add_podcast(podcast *);

    void display();

    friend ostream &operator<<(ostream &out, playlist &p);
};

// ostream &operator<<(ostream &out, playlist &p)
// {
//     out << p.name << " by " << p.creator << " [Playlist]" << endl
//         << endl;

//     if (p.playlist_size > 0)
//     {
//         for (int i = 0; i < p.playlist_size; i++)
//             p.m[i]->display_short();
//     }
//     else
//         out << "[] Empty Playlist" << endl;
//     out << "-------------------------------------------------------------\n";

//     return out;
// }