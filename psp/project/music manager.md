# Music Manager
- Classes
    - Music Player
    - Media
    - Song (inherits media)
    - Podcast (inherits media)
    - Playlist
---
## Media Class (abstract)
- Data Members
    - creator
    - name
    - duration
    - genre
- Member Functions
    - [x] setters
    - [x] getters
    - [x] display function (virtual)
    - [x] display_short (virtual)

---
## Song Class (inherits media)
- Data Member
    - album
    - release date
- Member Function
    - [x] setters
    - [x] getters
    - [x] display
    - [x] display_short
    - [x] overload `==` operator

---
## Podcast (inherits media)
- Data members
    - episode
    - guests
- Member Function
    - [x] setters
    - [x] getters
    - [x] display
    - [x] display_short
    - [x] overload `==` operator

---
## Playlist 
- Data members
    - Name
    - Creator
    - Public
    - Media (array)
- Member Functions
    - [x] getters
    - [x] setters
    - [x] add song to playlist
    - [x] add podcast to playlist
    - [x] display playlist
    - [x] overload `<<` operator [friend function]
---
## Music Player
- Data Members
    - Songs (array)
    - Podcasts (array)
    - Playlists (array)
- Member Functions
    - [x] Constructor
        - read from a file of songs and podcasts
    - [x] Destructor
        - update file with new songs and podcasts
    - [x] Add Song
    - [x] Add Podcast
    - [x] Create playlist
    - [x] Display songs
    - [x] Display podcasts
    - [x] Display public playlists
    - [x] Display song by artist
    - [x] Display song by genre
    - [x] Search song by artist and name
    - [x] Display podcast by name
    - [x] Display podcast by genre
    - [x] Search podcast by name and episode