#ifndef TIPOPGTO_H
#define TIPOPGTO_H

#include <string>
#include "gravavel.h"

using namespace std;

class TipoPgto : Gravavel{

private:
	string mTipo;
	
public:
	TipoPgto(){};

	TipoPgto(string tipo){
		mTipo = tipo;
	}

	void salvar(){

	}
	
	void setTipo(string tipo){mTipo = tipo;}
	string getTipo(){return mTipo;}

	char * getFile(){return (char *)"db/tipopgto.flan";}	
	
};

#endif