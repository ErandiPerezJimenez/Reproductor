#include "Menus.h"
#define WIN

void Clear()
{
    #ifdef WIN
        system( "cls" ); //Limpia la pantalla en windows
    #endif

    #ifdef LIN
<<<<<<< HEAD
        system( "clear ");
    #endif // LIN
}

void  PrintMenuPrincipal()
=======
        system( "clear ");   //Limpia la pantalla en Linux
    #endif // LIN
}

void PrintMenuPrincipal()
>>>>>>> master
{
    printf("\n\tMenú principal\n");
    printf("A) Lista de canciones completa\n");    //Mostraria todas las canciones de la lista principal
    printf("N) Nueva Playlist\n");                 //Crearia una nueva playlist y la almacenaria en la lista secundaria
    printf("D) Eliminar Playlist\n");              //Eliminaria una playlist contenida en la lista secundaria
    printf("R) Reproducir Playlist\n");            //Mostraria un menu con opciones para una playlist
    printf("E) Salir\n");                          //Salimos del programa de manera defenitiva
<<<<<<< HEAD
    printf("H) Mostrar menu\n ");                  //Vuelve a mostrar este mensaje
=======
    printf("H) Mostrar ayuda\n ");                  //Vuelve a mostrar este mensaje
>>>>>>> master

}

void PrintMenuPlaylist()
{
<<<<<<< HEAD
    printf("A) Agregar canción\n");
    printf("X) Remover canción\n");
    printf("P) Reproducir canción\n");
    printf("H) Mostrar ayuda\n");
    printf("S) Salir\n");
}

// Activación de segundo menú
=======
    printf("\n\tMenú para Playlist\n");
    printf("A) Agregar canción\n");       //Agrega una canción a la playlist en la que se este trabajando
    printf("X) Remover canción\n");       //Quita una canción seleccionada por el usuario
    printf("P) Reproducir canción\n");    //Simula la reproducción de la canción ( aun falta un detalle)
    printf("H) Mostrar ayuda\n");         //Vuelve a mostrar este menú
    printf("S) Salir\n");                 //Salimos de este menú y regresamos al principal
}

// Función de activación de segundo menú
>>>>>>> master
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

<<<<<<< HEAD
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
=======
            case 'A': case 'a':;   //";" corrige el error de compilación

                /*if( Playlist_Len( this ) > 0 ){
                    Playlist_Cursor_back( this );  //Cambiado por un Insert_back
                }*/
                Track *v1 = Track_New();
                Playlist_Insert_back( this, v1 ); printf("\n\nInsertando cancion en playlist...\n");
                Print_DataTrack( v1 );
                Track_Delete( &v1 );  /*Es interesante y valido borrar la cancion despues de crearla puesto
                                            que utilizamos a la funcion Playlist_Insert, insertandola en la playlist
                                            que se paso por direccion, por lo tanto ya queda guardada y se cumplen
                                            esos dos propositos, guardarla en una playlist y no dejar memory leaks */
                PrintMenuPlaylist();

            break;


            case 'X': case 'x':
                if( Playlist_IsEmpty( this ) == true ){
                    printf("\n¡¡¡ Error !!! , la playlist esta vacia\n");
                    break;
                } else{
                    Clear();
                    printf("\n\t Eliga la canción que sera removida:\n");
                    Playlist_Cursor_front( this );

                    for( size_t i = 0; i<Playlist_Len( this ); ++i ){
                        printf("%d.- ",i+1); puts( this->cursor->datos.title ); //Mostramos la lista de canciones en la playlist
                        Playlist_Cursor_next( this );
                    }

                    size_t p = 0;
                    printf("cmd > > >: ");
                    scanf("%ld", &p );

                    Playlist_Cursor_front( this );

                    if( p == 1){
                        printf("Removiendo "); puts( this->cursor->datos.title); printf("...\n");
                        Playlist_Remove_front( this );

                    } else{

                        for( size_t i = 0; i< p-1; ++i ){
                            Playlist_Cursor_next( this );
                        }
                        printf("Removiendo "); puts( this->cursor->datos.title);
                        Playlist_Remove( this );

                    }

                }

                //Faltaria escoger una cancion, y nosotros la eliminamos ya sea agregando un indice
                //o recorriendo la lista desde el primer nodo hasta el "numero" escogido por el usuario:
                // !!!Actualización, ya QUEDO RESUELTO
>>>>>>> master

            break;

            case 'P': case 'p':
<<<<<<< HEAD
                Playlist_Cursor_front( this );
                for( size_t i = 0; i<Playlist_Len( this ); ++i ){
                        printf("%d.- ",i+1); puts( this->cursor->datos.title );  //Mostramos la lista de canciones en la playlist
                        Playlist_Cursor_next( this );
=======
                if( Playlist_IsEmpty( this ) == true ){
                    printf("\n¡¡¡ Error !!! , la playlist esta vacia\n");
                    break;
                } else{
                    Playlist_Cursor_front( this );
                    for( size_t i = 0; i<Playlist_Len( this ); ++i ){
                        printf("%d.- ",i+1); puts( this->cursor->datos.title );  //Mostramos la lista de canciones en la playlist
                        Playlist_Cursor_next( this );
                    }

                    size_t p = 0;
                    printf("cmd > > >: ");
                    scanf("%ld", &p );

                    Playlist_Cursor_front( this );

                    if( p == 1){
                        printf("Reproduciendo "); puts( this->cursor->datos.title); printf("...\n");
                        //Simulación de la reproducción, ¿Como hacer siguiente cancion, anterior y
                        //que haya un cierto tiempo antes de la siguiente instruccion?

                    } else{

                        for( size_t i = 0; i< p-1; ++i ){
                            Playlist_Cursor_next( this );
                        }
                        printf("Reproduciendo "); puts( this->cursor->datos.title);
                    }
>>>>>>> master
                }

                //Faltaria escoger una cancion, y nosotros simulamos la reproducción, ya sea agregando un indice
                //o recorriendo la lista desde el primer nodo hasta el "numero" escogido por el usuario
<<<<<<< HEAD
=======
                // !!!ACTUALIZACIÓN: El usuario ya puede escoger la canción, pero podria buscarse la forma
                // de hacer "mas detallada" la simulación de la reproducción
>>>>>>> master

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

<<<<<<< HEAD
	Player* player=Player_New();
=======
>>>>>>> master

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
<<<<<<< HEAD
                char name[MAX];
                
                fflush( stdin );
                gets(name);
                
                //scanf("%s", name);
                Playlist* p1 = Playlist_New( name );
                printf("%s", p1->name);
                
                Player_Insert_back(player,pl);
                
=======
                char name[50];
                scanf("%c", name);
                Playlist* p1 = Playlist_New( name );   //Aun esta en revisión
                printf("%c", p1->name);
>>>>>>> master
                Playlist_Delete(&p1);
            break;

            case 'D': case 'd':
                //Funcion mostrar playlist's

            break;

            case 'R': case 'r':
<<<<<<< HEAD
                 //PrintMenuPlaylist();
=======
>>>>>>> master
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
<<<<<<< HEAD
       
       Player_Delete(&player);
=======
>>>>>>> master

}
