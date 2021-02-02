#ifndef  Playlist_INC
#define  Playlist_INC

#define MAX 50

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "Track.h"

/*
typedef struct Track{
	char title[MAX];
	char performer[MAX];
	char genre[MAX];
	int year;
	float duration;
}Track;
*/

typedef Track* Item;

typedef struct Node{
	
	Item datos;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct Playlist{
	
	Node* first;
	Node* last;
	Node* cursor;
	
	size_t len;
}Playlist;

Playlist* Playlist_New();
void Playlist_Delete(Playlist** this);

void Playlist_Insert_front( Playlist* this, Item x );
void Playlist_Insert_back( Playlist* this, Item x );
void Playlist_Insert( Playlist* this, Item x );

void Playlist_Remove_front( Playlist* this );
void Playlist_Remove_back( Playlist* this );
void Playlist_Remove( Playlist* this );

Item Playlist_Get( Playlist* this );

void Playlist_Cursor_front( Playlist* this );
void Playlist_Cursor_back( Playlist* this );
void Playlist_Cursor_next( Playlist* this );
void Playlist_Cursor_prev( Playlist* this );

bool Playlist_IsEmpty( Playlist* this );
size_t Playlist_Len( Playlist* this );

void Playlist_MakeEmpty( Playlist* this );
void Playlist_Traverse( Playlist* this, void (*fn)( Item item  ) );

#endif
