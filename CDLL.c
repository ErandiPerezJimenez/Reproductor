#include "CDLL.h"

static Node* newNode( Track x )
{
	Node* n = (Node*)malloc(sizeof(Node));
	if(n){
		n->datos=x; //  Verificar si funciona
		n->next=NULL;
		n->prev=NULL;
	}
	return n;
}

CDLL* CDLL_New()
{
	CDLL* lista=(CDLL*)malloc(sizeof(CDLL));
	if(lista){
		lista->cursor=NULL;
		lista->first=NULL;
		lista->last=NULL;
		lista->len=0;
	} else{
		printf("No se creo la lista");
	}
	return lista;
}	

void CDLL_Delete( CDLL** this )
{
	for(size_t i=0;i<(*this)->len;++i){
		Node* tmp=(*this)->first->next;
		free((*this)->first);
		(*this)->first=tmp;
	}
	free(*this);
	*this=NULL;
}	

void CDLL_Insert( CDLL* this, Track x )
{
	Node* n= newNode(x);
	if(CDLL_IsEmpty(this)){
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
}

void CDLL_Insert_front( CDLL* this, Track x )
{
	Node* n= newNode(x);
	if(CDLL_IsEmpty(this)){
		this->first=this->last=this->cursor=n;
	} else{
		n->next=this->first;
		this->first->prev=n;
		this->first=n;
	}
	this->last->next=this->first;
	this->first->prev=this->last;
	
	++this->len;
	
}

void CDLL_Insert_back( CDLL* this, Track x )
{
	Node* n = newNode(x);
	if(CDLL_IsEmpty(this)){
		this->first=this->last=this->cursor=n;
	} else{
		this->last->next=n;
		n->prev=this->last;
		this->last=n;
	}
	this->last->next=this->first;
	this->first->prev=this->last;
	
	++this->len;
	
}

void CDLL_Remove( CDLL* this )
{
	assert(this->len);
	
	if(this->len==1){
		free(this->first);
		this->first=this->last=this->cursor=NULL;
		--this->len;
	} else if(this->cursor==this->first){
		CDLL_Remove_front(this);
		this->cursor=this->first;
	} else if(this->cursor==this->first){
		CDLL_Remove_back(this);
		this->cursor=this->last;
	} else{
		Node* tmp1 = this->cursor->prev;
		Node* tmp2 = this->cursor->next;
		free(this->cursor);
		tmp1->next=tmp2;
		tmp2->prev=tmp1;
		this->cursor=tmp2;
		--this->len;
	}
}

void CDLL_Remove_front( CDLL* this )
{
	assert(this->len);
	
	if(this->len==1){
		free(this->first);
		this->first=this->last=this->cursor=NULL;
	} else{
		Node* tmp=this->first->next;
		free(this->first);
		this->first=tmp;
		tmp->prev=this->last;
		this->last->next=tmp;
	}
	--this->len;
}

void CDLL_Remove_back( CDLL* this )
{
	assert(this->len);
	
	if(this->len==1){
		free(this->last);
		this->first=this->last=this->cursor=NULL;
	}else{
		Node* tmp=this->last->prev;
		free(this->last);
		this->last=tmp;
		tmp->next=this->first;
		this->first->prev=tmp;
	}
	--this->len;
}


Track CDLL_Get( CDLL* this ) // se tiene que modificar
{
	return this->cursor->datos;
}


void CDLL_Cursor_front( CDLL* this )
{
	this->cursor=this->first;
}

void CDLL_Cursor_back( CDLL* this )
{
	this->cursor=this->last;
}

void CDLL_Cursor_next( CDLL* this )
{
	assert(this->cursor);
	this->cursor=this->cursor->next;
}

void CDLL_Cursor_prev( CDLL* this )
{
	assert(this->cursor);
	this->cursor=this->cursor->prev;
}

bool CDLL_IsEmpty( CDLL* this )
{
	return this->len==0;
}

size_t CDLL_Len( CDLL* this )
{
	return this->len;
}

void CDLL_MakeEmpty( CDLL* this )
{
	for(size_t i=0; i<this->len;++i){
		CDLL_Remove_front(this);
	}
}


void CDLL_Traverse( CDLL* this, void (*fn)( Track item ) ) // se tiene que modificar
{
	if( NULL == this ){ return; }

	Node* t = this->first;
   
   
   do{
		fn( t->datos );
		t = t->next;
		
   } while( t != this->first );
   
}

