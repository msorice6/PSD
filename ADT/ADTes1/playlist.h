#include "song.h"

typedef struct playlist *Playlist;

Playlist createPlaylist(char* name);
void addSong(Playlist, Song);
void removeSong(Playlist, char*);
void printPlaylist(Playlist);

// METODI CREATI DA ME
void testaAlContrario(Playlist p, Song *s);
int getCanzoniSize(Playlist p);
Playlist insertionSort(Playlist p);
void swapSongs(Playlist p, int s1Pos, int s2Pos);