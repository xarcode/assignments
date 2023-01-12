#pragma once
#include "media.hpp"
#include "song.hpp"
#include "podcast.hpp"
#include "playlist.hpp"

class music_manager
{
private:
    song songs[500];
    podcast podcasts[500];
    playlist playslists[100];
    int song_counter, podcast_counter, playlist_counter;
public:
    music_manager();

    void add_song();
    void add_podcast();
    void create_playlist();

    void display_songs();
    void display_songs_short();
    void display_podcasts();
    void display_podcasts_short();
    void display_public_playlists();

    void display_song_by_artist();
    void display_song_by_genre();
    int search_song_by_artist_and_name();

    void display_podcast_by_name();
    void display_podcast_by_genre();
    int search_podcast_by_name_and_episode();
    
    ~music_manager();
};