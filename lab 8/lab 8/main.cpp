#include "Playlist.h"
#include "Song.h"
#include<iostream>
using namespace std;
int main()
{
	Playlist<String> playlist;
	Song<String> s("Song 1", "c:\\fun");
	Song<String> t("Song 2", "c:\\fun");
	playlist.addSong(s);
	playlist.addSong(t);
	playlist.showPlaylist();

}