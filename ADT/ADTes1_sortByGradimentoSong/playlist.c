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

Playlist insertionSort(Playlist p){

    int n = getCanzoniSize(p);

    Item now;
    Item key;
    int j = 0;

    for (int i = 1; i < n; i++) {
        key = getListItemPos(p->songs, i);
        j = i;
        while (j > 0 && getGradimento(getListItemPos(p->songs, j - 1)) < getGradimento(getListItemPos(p->songs, j))){
            swapSongs(p, j-1  ,j  );
            j--;
        }

    }
    return p;

}

void swapSongs(Playlist p, int s1Pos, int s2Pos){

    Item s1Tmp = getListItemPos(p->songs,s1Pos);
    Item s2 = getListItemPos(p->songs,s2Pos);

    setListItemPos(p->songs, s1Pos ,s2 );
    setListItemPos(p->songs, s2Pos, s1Tmp );

}
