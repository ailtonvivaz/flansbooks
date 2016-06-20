#ifndef MODOPGTO_H
#define MODOPGTO_H

#include <string>
#include "gravavel.h"
#include "tipopgto.h"

using namespace std;

class ModoPgto : public Gravavel{

private:
	TipoPgto mTipoPgto;
	float mValor;
	
public:
	ModoPgto(){};
	
	ModoPgto(string tipoPgto, float valor){
		mTipoPgto = TipoPgto(tipoPgto);
		mValor = valor;
	}

	void salvar(){
		
	}
	
	void setTipoPgto(TipoPgto tipoPgto){mTipoPgto = tipoPgto;}
	TipoPgto getTipoPgto(){return mTipoPgto;}
	
	void setValor(float valor){mValor = valor;}
	float getValor(){return mValor;}

	char * getFile(){return (char *)"db/modopgto.flan";}	
	
};

#endif