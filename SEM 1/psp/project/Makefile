music_manager: main.o media.o music_manager.o song.o podcast.o playlist.o
	g++ main.o media.o music_manager.o song.o podcast.o playlist.o -o music_manager

main.o: main.cpp
	g++ -c main.cpp

media.o: media.cpp media.hpp
	g++ -c media.cpp

music_manager.o: music_manager.cpp music_manager.hpp
	g++ -c music_manager.cpp

song.o: song.cpp song.hpp
	g++ -c song.cpp

podcast.o: podcast.cpp podcast.hpp
	g++ -c podcast.cpp

playlist.o: playlist.cpp playlist.hpp
	g++ -c playlist.cpp

clean:
	rm *.o music_manager