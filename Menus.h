#ifndef Menus_INC
#define Menus_INC

#include <stdlib.h>
#include <stdio.h>
#include "Track.h"
#include "Playlist.h"

void  Clear();  //Creamos esta función ya que se llamara continuamente pero funciona de forma diferente en windows y linux
void  PrintMenuPrincipal();
void  PrintMenuPlaylist();
void  TestMenuPlaylist( Playlist* this ); //Deberia de pasarse una playlist en la que se guardara o modificaran canciones
void  TestPrincipal();


#endif // Menus_INC
