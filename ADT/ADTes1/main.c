/*
Sviluppare un nuovo operatore di Playlist che dato in input una playlist la ordini dalla canzone più
gradita alla meno gradita. Sviluppare un algoritmo di ordinamento a scelta del candidato. Non
modificare l’ADT list.
Completare ed estendere quando necessario il codice fornito, in particolare per gestire per ogni
canzone anche il gradimento. Si ricorda che l'ADT Playlist è in grado di gestire una lista di canzoni
rappresentate tramite l’ADT Song.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "playlist.h"
#include "item.h"

int main() {
    Playlist p;
    int gradimento[3];

    Song s[3];

    p = createPlaylist("Rock");

    s[0] = initSong("a", "1", 3);
    gradimento[0] = 4;
    addSong(p, s[0]);

    s[1] = initSong("b", "2", 6);
    gradimento[1] = 1;
    addSong(p, s[1]);

    printPlaylist(p);




    return 0;

}