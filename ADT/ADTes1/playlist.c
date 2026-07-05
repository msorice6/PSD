#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "playlist.h"
#include "list.h"
#include "song.h"

struct playlist{
	char *name;
	List songs;
};

Playlist createPlaylist(char* name){
	Playlist p = malloc(sizeof(struct playlist));
	p->name = strdup(name);
	p->songs = newList();
	return p;
}

void addSong(Playlist p, Song s){
	addHead(p->songs, s);
}

void removeSong(Playlist p, char *title){
	Song s = initSong(title, "", 0,0);
	removeListItem(p->songs, s);
}

void printPlaylist(Playlist p){

	printf("Playlist: %s", p->name);
	printList(p->songs);
	printf("\n");

}

void testaAlContrario(Playlist p, Song *s){
    printf("sto in testaAlContrario\n");

    printf("\n%s\n",artist(s[0]));
}

int getCanzoniSize(Playlist p){
    return sizeList(p->songs);
}

