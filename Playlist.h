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
	float duration;
}Track;

typedef struct Node{
	
	Track datos;
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

bool Playlist_Insert_front( Playlist* this, Track x );
bool Playlist_Insert_back( Playlist* this, Track x );
bool Playlist_Insert( Playlist* this, Track x );

void Playlist_Remove_front( Playlist* this );
void Playlist_Remove_back( Playlist* this );
void Playlist_Remove( Playlist* this );

int Playlist_Get( Playlist* this );

void Playlist_Cursor_front( Playlist* this );
void Playlist_Cursor_back( Playlist* this );
void Playlist_Cursor_next( Playlist* this );
void Playlist_Cursor_prev( Playlist* this );

bool Playlist_IsEmpty( Playlist* this );
size_t Playlist_Len( Playlist* this );

void Playlist_MakeEmpty( Playlist* this );
void Playlist_Traverse( Playlist* this, void (*fn)( int item  ) );

#endif
