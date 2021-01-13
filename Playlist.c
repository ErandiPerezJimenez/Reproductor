#include<Playlist.h>

static Node* newNode( Track x )
{
	Node* n = (Node*)malloc(sizeof(Node));
	if(n){
		n->datos=x; //Verificar si funciona
		n->next=NULL;
		n->prev=NULL;
	}
	return n;
}

Playlist* Playlist_New()
{
	Playlist* lista=(Playlist*)malloc(sizeof(Playlist));
	if(lista){
		lista->cursor=NULL;
		lista->first=NULL;
		lista->last=NULL;
		lista->len=0;
	}
	return lista;
}	

void Playlist_Delete( Playlist** this )
{
	for(size_t i=0;i<(*this)->len;++i){
		Node* tmp=(*this)->first->next;
		free((*this)->first);
		(*this)->first=tmp;
	}
	free(*this);
	*this=NULL;
}	

bool Playlist_Insert( Playlist* this, Track x )
{
	Node* n= newNode(x);
	if(Playlist_IsEmpty(this)){
		this->first=this->last=this->cursor=n;
		this->last->next=this->first;
		this->first->prev=this->last;
	} else{
		Node* tmp=this->cursor->next;
		n->next=tmp;
		tmp->prev=n;
		if(this->cursor==this->last){
			this->last=n;
		}
		this->cursor->next=n;
		n->prev=this->cursor;
		this->cursor=n;
	}
	++this->len;
	return n!=NULL;
}
