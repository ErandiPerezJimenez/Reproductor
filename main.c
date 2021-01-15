#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
# include "Playlist.h"

#define MAX 50

Track Track_New(){
	Track t;
	int a;
	
	printf("Nombre de la pista: ");
	fgets(t.title,MAX,stdin);
	
	printf("Genero: ");
	fgets(t.genre,MAX,stdin);
	
	printf("Interprete: ");
	fgets(t.performer,MAX,stdin);
	
	printf("Año: ");
	scanf("%i",&t.year);
	
	printf("Duracion: ");
	scanf("%f",&t.duration);
	
	fflush(stdin);
	
	return t;
}



int main(){
	Playlist* Rock= Playlist_New();
	
	Track T1=Track_New();
	
	Track T2=Track_New();
	
	bool ins= Playlist_Insert(Rock, T1);
	bool ins2=Playlist_Insert(Rock, T2);
	
	printf("%s\n", Rock->cursor->prev->datos.title);	
	printf("%s\n", Rock->cursor->datos.title);
	
	
	
	Playlist_Delete(&Rock);
}
