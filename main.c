#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
# include "Playlist.h"

int main(){
	Playlist* pl= Playlist_New();
	
	
	Playlist_Delete(&pl);
}
