#include "music_manager.hpp"
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

template <typename T>
int _search(T arr[], int length, T target)
{
    int index = -1;
    for(int i = 0; i < length; i++)
        if(arr[i] == target)
            index = i;
    
    return index;
}

music_manager::music_manager()
{
    song_counter = 0;
    ifstream song_file("data/songs.txt");
    string line;
    while (getline(song_file, line))
    {
        stringstream ss(line);
        string creator, name, genre, album, date, s_duration;
        int duration;

        getline(ss, creator, ',');
        getline(ss, name, ',');
        getline(ss, s_duration, ',');
        getline(ss, genre, ',');
        getline(ss, album, ',');
        getline(ss, date, ',');
        duration = stoi(s_duration);

        songs[song_counter].set_creator(creator);
        songs[song_counter].set_name(name);
        songs[song_counter].set_duration(duration);
        songs[song_counter].set_genre(genre);
        songs[song_counter].set_album(album);
        songs[song_counter].set_date(date);

        song_counter++;
    }

    podcast_counter = 0;
    ifstream podcast_file("data/podcasts.txt");
    while (getline(podcast_file, line))
    {
        stringstream ss(line);
        string creator, name, genre, episode, guests, s_duration;
        int duration;

        getline(ss, creator, ',');
        getline(ss, name, ',');
        getline(ss, s_duration, ',');
        getline(ss, genre, ',');
        getline(ss, episode, ',');
        getline(ss, guests, ',');
        duration = stoi(s_duration);

        podcasts[podcast_counter].set_creator(creator);
        podcasts[podcast_counter].set_name(name);
        podcasts[podcast_counter].set_duration(duration);
        podcasts[podcast_counter].set_genre(genre);
        podcasts[podcast_counter].set_episode(episode);
        podcasts[podcast_counter].set_guests(guests);

        podcast_counter++;
    }

    playlist_counter = 0;
    song_file.close();
    podcast_file.close();
}

void music_manager::add_song()
{
    string creator, name, genre, s_duration, album, date;
    cout << "Enter song name - ";
    getline(cin, name);
    cout << "Enter song creator - ";
    getline(cin, creator);
    cout << "Enter song genre - ";
    getline(cin, genre);
    cout << "Enter song duration - ";
    getline(cin, s_duration);
    cout << "Enter song album - ";
    getline(cin, album);
    cout << "Enter song release date - ";
    getline(cin, date);

    song s(creator, name, stoi(s_duration), genre, album, date);
    songs[song_counter++] = s;
}

void music_manager::add_podcast()
{
    string creator, name, genre, s_duration, episode, guest;
    cout << "Enter podcast name - ";
    getline(cin, name);
    cout << "Enter podcast creator - ";
    getline(cin, creator);
    cout << "Enter podcast genre - ";
    getline(cin, genre);
    cout << "Enter podcast duration - ";
    getline(cin, s_duration);
    cout << "Enter podcast episode name - ";
    getline(cin, episode);
    cout << "Enter podcast guests - ";
    getline(cin, guest);

    podcast p(creator, name, stoi(s_duration), genre, episode, guest);
    podcasts[podcast_counter++] = p;
}

void music_manager::create_playlist()
{
    string name, creator;
    cout << "Enter your name: ";
    getline(cin, creator);
    cout << "Enter name of playlist: ";
    getline(cin, name);

    playslists[playlist_counter].set_creator(creator);
    playslists[playlist_counter].set_name(name);
    cout << "Is the playlist public? [1] yes | [2] no: ";
    string is_public;
    getline(cin, is_public);
    if (stoi(is_public) == 1)
        playslists[playlist_counter].set_is_public(true);
    else
        playslists[playlist_counter].set_is_public(false);

    while (1)
    {
        system("cls");
        cout << "[Playlist Creation Menu]" << endl;
        cout << "------------------------\n";
        cout << "1. Add song" << endl;
        cout << "2. Add podcast" << endl;
        cout << "3. Done" << endl;
        cout << "Enter choice: ";
        string choice;
        getline(cin, choice);

        system("cls");
        switch (stoi(choice))
        {
        case 1:
        {
            display_songs_short();
            int index = search_song_by_artist_and_name();
            if (index == -1)
                cout << "Song not found..." << endl;
            else
                playslists[playlist_counter].add_song(&songs[index]);
        }
        break;
        case 2:
        {
            display_podcasts_short();
            int index = search_podcast_by_name_and_episode();
            if (index == -1)
                cout << "Podcast not found..." << endl;
            else
                playslists[playlist_counter].add_podcast(&podcasts[index]);
        }
        break;
        case 3:
            cout << "[Playlist Created]" << endl
                 << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }

        if (stoi(choice) == 3)
            break;
    }

    playslists[playlist_counter].display();
    playlist_counter++;
}

void music_manager::display_songs()
{
    cout << "[Available Songs]" << endl;
    cout << "===================================================" << endl;
    for (int i = 0; i < song_counter; i++)
        songs[i].display();

    cout << endl;
}

void music_manager::display_songs_short()
{
    cout << "[Available Songs]" << endl;
    cout << "===================================================" << endl;
    for (int i = 0; i < song_counter; i++)
        songs[i].display_short();

    cout << endl;
}

void music_manager::display_podcasts()
{
    cout << "[Available Podcasts]" << endl;
    cout << "===================================================" << endl;
    for (int i = 0; i < podcast_counter; i++)
        podcasts[i].display();

    cout << endl;
}

void music_manager::display_podcasts_short()
{
    cout << "[Available Podcasts]" << endl;
    cout << "===================================================" << endl;
    for (int i = 0; i < podcast_counter; i++)
        podcasts[i].display_short();

    cout << endl;
}

void music_manager::display_public_playlists()
{
    cout << "[Publicly Available Playlists]" << endl;
    cout << "===================================================" << endl;
    for (int i = 0; i < playlist_counter; i++)
        if (playslists[i].get_is_public())
            cout << playslists[i];
}

void music_manager::display_song_by_artist()
{
    string artist;
    cout << "Enter artist name: ";
    getline(cin, artist);
    transform(artist.begin(), artist.end(), artist.begin(), ::tolower);

    bool found = false;
    for (int i = 0; i < song_counter; i++)
    {
        string current_artist = songs[i].get_creator();
        transform(current_artist.begin(), current_artist.end(), current_artist.begin(), ::tolower);
        if (current_artist.find(artist) != string::npos)
        {
            songs[i].display_short();
            found = true;
        }
    }

    if (!found)
        cout << "No Results" << endl
             << endl;
}

void music_manager::display_song_by_genre()
{
    string genre;
    cout << "Enter genre: ";
    getline(cin, genre);
    transform(genre.begin(), genre.end(), genre.begin(), ::tolower);

    bool found = false;
    for (int i = 0; i < song_counter; i++)
    {
        string current_genre = songs[i].get_genre();

        transform(current_genre.begin(), current_genre.end(), current_genre.begin(), ::tolower);
        if (current_genre.find(genre) != string::npos)
        {
            songs[i].display_short();
            found = true;
        }
    }

    if (!found)
        cout << "No Results" << endl
             << endl;
}

int music_manager::search_song_by_artist_and_name()
{
    cout << "Enter artist name: ";
    string artist;
    getline(cin, artist);
    cout << "Enter song name: ";
    string name;
    getline(cin, name);

    song s;
    s.set_creator(artist);
    s.set_name(name);

    return _search<song>(songs, song_counter, s);
}

void music_manager::display_podcast_by_name()
{
    string name;
    cout << "Enter Podcast Name: ";
    getline(cin, name);
    transform(name.begin(), name.end(), name.begin(), ::tolower);

    bool found = false;
    for (int i = 0; i < podcast_counter; i++)
    {
        string current_name = podcasts[i].get_name();
        transform(current_name.begin(), current_name.end(), current_name.begin(), ::tolower);

        if (current_name.find(name) != string::npos)
        {
            podcasts[i].display_short();
            found = true;
        }
    }

    if (!found)
        cout << "No Results" << endl
             << endl;
}

void music_manager::display_podcast_by_genre()
{
    string genre;
    cout << "Enter genre: ";
    getline(cin, genre);
    transform(genre.begin(), genre.end(), genre.begin(), ::tolower);

    bool found = false;
    for (int i = 0; i < podcast_counter; i++)
    {
        string current_genre = podcasts[i].get_genre();
        transform(current_genre.begin(), current_genre.end(), current_genre.begin(), ::tolower);

        if (current_genre.find(genre) != string::npos)
        {
            podcasts[i].display_short();
            found = true;
        }
    }

    if (!found)
        cout << "No Results" << endl
             << endl;
}

int music_manager::search_podcast_by_name_and_episode()
{
    cout << "Enter podcast name: ";
    string name;
    getline(cin, name);
    cout << "Enter episode: ";
    string episode;
    getline(cin, episode);

    podcast p;
    p.set_name(name);
    p.set_episode(episode);

    return _search<podcast>(podcasts, podcast_counter, p);
}

music_manager::~music_manager()
{
    ofstream song_file("data/songs.txt");

    for (int i = 0; i < song_counter; i++)
    {
        string line = songs[i].get_creator() + "," + songs[i].get_name() + "," + to_string(songs[i].get_duration()) + "," + songs[i].get_genre() + "," + songs[i].get_album() + "," + songs[i].get_date() + "\n";

        song_file << line;
    }

    ofstream podcast_file("data/podcasts.txt");

    for (int i = 0; i < podcast_counter; i++)
    {
        string line = podcasts[i].get_creator() + "," + podcasts[i].get_name() + "," + to_string(podcasts[i].get_duration()) + "," + podcasts[i].get_genre() + "," + podcasts[i].get_episode() + "," + podcasts[i].get_guests() + "\n";

        podcast_file << line;
    }

    song_file.close();
    podcast_file.close();
}