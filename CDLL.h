#ifndef  CDLL_INC
#define  CDLL_INC

#define MAX 50

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


typedef struct Track{
	char title[MAX];
	char performer[MAX];
	char genre[MAX];
	int year;
	float duration;
}Track;

typedef Track Item;

typedef struct Node{
	
	Item datos;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct CDLL{
	
	Node* first;
	Node* last;
	Node* cursor;
	
	size_t len;
}CDLL;

CDLL* CDLL_New();
void CDLL_Delete(CDLL** this);

void CDLL_Insert_front( CDLL* this, Item x );
void CDLL_Insert_back( CDLL* this, Item x );
void CDLL_Insert( CDLL* this, Item x );

void CDLL_Remove_front( CDLL* this );
void CDLL_Remove_back( CDLL* this );
void CDLL_Remove( CDLL* this );

Item CDLL_Get( CDLL* this );

void CDLL_Cursor_front( CDLL* this );
void CDLL_Cursor_back( CDLL* this );
void CDLL_Cursor_next( CDLL* this );
void CDLL_Cursor_prev( CDLL* this );

bool CDLL_IsEmpty( CDLL* this );
size_t CDLL_Len( CDLL* this );

void CDLL_MakeEmpty( CDLL* this );
void CDLL_Traverse( CDLL* this, void (*fn)( Item item  ) );

#endif
