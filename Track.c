#include "Track.h"


//Estas Funciones Son de prueba NO FUNCIONAN
/*
Track* Track_New()
{
    Track* song = malloc( sizeof(Track) );

    if( song ){
        Track_ChangeTitle(     song );
        Track_ChangePerformer( song );
        Track_ChangeGenre(     song );
        Track_ChangeYear(      song );
        Track_ChangeDuration(  song );
    } else{
        free( song );
        song = NULL;
        exit(1);
    }

    return song;
}


void Track_Delete( Track** this )
{
    assert( *this );

    free( *this );
    *this = NULL;

}

void Track_ChangeTitle( Track* this )
{
    printf("Nombre de la cancion: ");
    scanf("%s", this->title );
    printf("Nuevo nombre: %s \n", this->title );
}

void Track_ChangePerformer( Track* this )
{
    printf("Artista: ");
    scanf("%s", this->performer );
    printf("Nombre del artista: %s \n", this->performer );
}

void Track_ChangeGenre( Track* this )
{
    printf("Genero: ");
    scanf("%s", this->genre );
    printf("Nombre del genero: %s \n", this->genre );
}

void Track_ChangeYear( Track* this )
{
    printf("Año: ");
    scanf("%d", this->year );
    printf("Año de salida: %d \n", this->year );
}

void Track_ChangeDuration( Track* this )
{
    printf("Duración: ");
    scanf("%lf", this->duration );
    printf("Tiempo de duración: %lf \n", this->duration );
}


void Print_DataTrack( Track* this )
{
    printf("\n\Datos de la canción:\n");
    printf("Nombre de la canción: %s\n", this->title );
    printf("Artista: %s\n", this->performer );
}


*/


//Funciones de Erandi
Track New_Track()
{
        Track New_Track;
        printf("\nNombre de la cancion:");
        fflush(stdin);
        gets(New_Track.title);

        printf("\nNombre del artista: ");
        fflush(stdin);
        gets(New_Track.performer);

        printf("\nGenero de la cancion: ");
        fflush(stdin);
        gets(New_Track.genre);

        printf("\nIngrese el año: ");
        fflush(stdin);
        scanf("%d",&New_Track.year);

        printf("\nIngrese la duracion: ");
        fflush(stdin);
        scanf("%f",&New_Track.duration);

        return New_Track;
}


void imprimir_cancion(Track mostrar_cancion)
{
    printf("Cancion:%s\n",mostrar_cancion.title);
    printf("Artista:%s\n",mostrar_cancion.performer);
    printf("Genero musical:%s\n",mostrar_cancion.genre);
    printf("Año:%d\n",mostrar_cancion.year);
    printf("Duracion:%f\n",mostrar_cancion.duration);

}
