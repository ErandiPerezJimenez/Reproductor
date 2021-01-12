#ifndef  PLAYLIST_INC
#define  PLAYLIST_INC

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Track{
	char title[50];
	char performer[50];
	char genre[50];
	int year;
	
	struct Track* next;
	struct Track* prev;
} Track;

typedef struct Playlist{
	Track* first;
	Track* last;
	TracK* cursor;
	
	size_t len;
}Playlist;


