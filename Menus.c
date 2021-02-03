#include "Menus.h"
#define WIN

void Clear()
{
    #ifdef WIN
        system( "cls" ); //Limpia la pantalla en windows
    #endif

    #ifdef LIN
        system( "clear ");
    #endif // LIN
}

void  PrintMenuPrincipal()
{
    printf("\n\tMenú principal\n");
    printf("A) Lista de canciones completa\n");    //Mostraria todas las canciones de la lista principal
    printf("N) Nueva Playlist\n");                 //Crearia una nueva playlist y la almacenaria en la lista secundaria
    printf("D) Eliminar Playlist\n");              //Eliminaria una playlist contenida en la lista secundaria
    printf("R) Reproducir Playlist\n");            //Mostraria un menu con opciones para una playlist
    printf("E) Salir\n");                          //Salimos del programa de manera defenitiva
    printf("H) Mostrar menu\n ");                  //Vuelve a mostrar este mensaje

}

void PrintMenuPlaylist()
{
    printf("A) Agregar canción\n");
    printf("X) Remover canción\n");
    printf("P) Reproducir canción\n");
    printf("H) Mostrar ayuda\n");
    printf("S) Salir\n");
}

// Activación de segundo menú
void TestMenuPlaylist( Playlist* this ) //Deberia de pasarse una playlist en la que se guardara o modificaran canciones
{
    Clear();
    char cmd;
    char str[80];

    PrintMenuPlaylist();

    do{
        printf("cmd > > >: ");
        scanf( "%s", &str );
        cmd = str[0];

        switch( cmd )
        {
            case 'S': case 's':   break;
            case 'H': case 'h': PrintMenuPlaylist(); break;

            case 'A': case 'a':;
                //Playlist_Cursor_back( this );
                //Track *v1 = Track_New();
                //{
                    //Playlist_Cursor_back( this );
                    Track *v1 = Track_New();
                    Playlist_Insert_back( this, v1 ); printf("\n\nInsertando cancion en playlist...");
                    Print_DataTrack( v1 );
                    Track_Delete( &v1 );  /*Es interesante y valido borrar la cancion despues de crearla puesto
                                            que utilizamos a la funcion Playlist_Insert, insertandola en la playlist
                                            que se paso por direccion, por lo tanto ya queda guardada y se cumplen
                                            esos dos propositos, guardarla en una playlist y no dejar memory leaks */
                 //Print_DataTrack( v1 );

                //}
            break;

            case 'X': case 'x':

                printf("\n\t Eliga la canción que sera removida\n");
                Playlist_Cursor_front( this );
                for( size_t i = 0; i<Playlist_Len( this ); ++i ){
                        printf("%d.- ",i+1); puts( this->cursor->datos.title ); //puts( this->cursor->datos.genre);  //Mostramos la lista de canciones en la playlist
                        Playlist_Cursor_next( this );
                }
                printf("cmd > > >: ");

                //Faltaria escoger una cancion, y nosotros la eliminamos ya sea agregando un indice
                //o recorriendo la lista desde el primer nodo hasta el "numero" escogido por el usuario

            break;

            case 'P': case 'p':
                Playlist_Cursor_front( this );
                for( size_t i = 0; i<Playlist_Len( this ); ++i ){
                        printf("%d.- ",i+1); puts( this->cursor->datos.title );  //Mostramos la lista de canciones en la playlist
                        Playlist_Cursor_next( this );
                }

                //Faltaria escoger una cancion, y nosotros simulamos la reproducción, ya sea agregando un indice
                //o recorriendo la lista desde el primer nodo hasta el "numero" escogido por el usuario

            break;

            default:
                printf("Opción invalida!\n");
                PrintMenuPlaylist();
            break;

        }

    } while( cmd != 'S' && cmd != 's');
}

void TestPrincipal()
{
    char cmd;
    char str[80];
    /*  Se pueden crear dos listas doblemente enlazadas
        la primera para guardar las canciones favoritas sin necesidad
        de estar almacenadas en una playlist y la segunda serviria como
        contenedor de varias playlist's
    */

	Player* player=Player_New();

    PrintMenuPrincipal();


    do{
        printf("cmd > > >: ");
        scanf("%s", &str );
        cmd = str[ 0 ];

        switch( cmd )
        {
            case 'E': case 'e': break;
            case 'H': case 'h': PrintMenuPrincipal(); break;

            case 'A': case 'a':
                //en progreso
            break;

            case 'N': case 'n':
                printf("\nNombre del Playlist: ");
                char name[MAX];
                
                fflush( stdin );
                gets(name);
                
                //scanf("%s", name);
                Playlist* p1 = Playlist_New( name );
                printf("%s", p1->name);
                
                Player_Insert_back(player,pl);
                
                Playlist_Delete(&p1);
            break;

            case 'D': case 'd':
                //Funcion mostrar playlist's

            break;

            case 'R': case 'r':
                 //PrintMenuPlaylist();
                 {
                    Playlist* this = Playlist_New();
                    TestMenuPlaylist(this);
                    Playlist_Delete( &this );
                    PrintMenuPrincipal();
                 }

            break;

            default:
                printf("Comando inválido\n");
                PrintMenuPrincipal();
            break;


        }


    } while( cmd != 'E' && cmd != 'e');

    /* Una vez llegados a este punto es posible que el usuario ya
       ya haya elegido salir del programa, por lo tanto deberiamos
       devolver la memoria pedida por las primeras dos listas; con la
       primera no habria demasiado problema, con la segunda deberia
       devolverse la memoria de cada nodo, pero cada nodo es una
       playlist independiente y una vez que no existan nodos, devolver
       la del objeto en si mismo*/
       
       Player_Delete(&player);

}
