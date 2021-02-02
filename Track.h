#ifndef Track_INC
#define Track_INC

#define MAX 80

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct Track
{
    char  title[ MAX ];
	char  performer[ MAX ];
	char  genre[ MAX ];
	int   year;
	float duration;

} Track;

Track*  Track_New();
void    Track_Delete(           Track** this );
void    Track_ChangeTitle(      Track* this );    //Funciones particulares
void    Track_ChangePerformer(  Track* this );
void    Track_ChangeGenre(      Track* this );
void    Track_ChangeYear(       Track* this );
void    Track_ChangeDuration(   Track* this );
void    Print_DataTrack(        Track* this );






#endif // Track_INC
