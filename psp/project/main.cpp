#include "music_manager.hpp"
#include <cstdlib>

int main()
{
    music_manager mm;
    while (true)
    {
        system("cls");
        cout << " ==============================================" << endl;
        cout << "|         MUSIC MANAGER by Ayush Nandi         |" << endl;
        cout << " ==============================================" << endl;
        cout << "| 1. Display All Available Songs               |" << endl;
        cout << "| 2. Display Songs by Artist                   |" << endl;
        cout << "| 3. Display Songs by Genre                    |" << endl;
        cout << "| -------------------------------------------  |" << endl;
        cout << "| 4. Display All Available Podcasts            |" << endl;
        cout << "| 5. Display Podcasts by Name                  |" << endl;
        cout << "| 6. Display Podcasts by Genre                 |" << endl;
        cout << "| -------------------------------------------  |" << endl;
        cout << "| 7. Display All Publicly Available Playlists  |" << endl;
        cout << "| 8. Add a Song to database                    |" << endl;
        cout << "| 9. Add a Podcast to database                 |" << endl;
        cout << "| -------------------------------------------  |" << endl;
        cout << "| 10. Create a Playlist                        |" << endl;
        cout << "| 11. Exit                                     |" << endl;
        cout << "|                                              |" << endl;
        cout << " ==============================================" << endl;
        cout << endl
             << "Enter your choice: ";
        string s_choice;
        getline(cin, s_choice);
        int choice = stoi(s_choice);

        system("cls");
        switch (choice)
        {
        case 1:
            mm.display_songs();
            cout << endl
                 << "Press Enter to continue...";
            getchar();
            break;
        case 2:
            mm.display_song_by_artist();
            cout << endl
                 << "Press Enter to continue...";
            getchar();
            break;
        case 3:
            mm.display_song_by_genre();
            cout << endl
                 << "Press Enter to continue...";
            getchar();
            break;
        case 4:
            mm.display_podcasts();
            cout << endl
                 << "Press Enter to continue...";
            getchar();
            break;
        case 5:
            mm.display_podcast_by_name();
            cout << endl
                 << "Press Enter to continue...";
            getchar();
            break;
        case 6:
            mm.display_podcast_by_genre();
            cout << endl
                 << "Press Enter to continue...";
            getchar();
            break;
        case 7:
            mm.display_public_playlists();
            cout << endl
                 << "Press Enter to continue...";
            getchar();
            break;
        case 8:
            mm.add_song();
            cout << endl
                 << "Press Enter to continue...";
            getchar();
            break;
        case 9:
            mm.add_podcast();
            cout << endl
                 << "Press Enter to continue...";
            getchar();
            break;
        case 10:
            mm.create_playlist();
            cout << endl
                 << "Press Enter to continue...";
            getchar();
            break;
        case 11:
            cout << "[Updated data file data/songs.txt]" << endl;
            cout << "[Updated data file data/podcasts.txt]" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            cout << endl
                 << "Press Enter to continue...";
            getchar();
            break;
        }

        if (choice == 11)
            break;
    }

    return 0;
}