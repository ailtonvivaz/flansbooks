#ifndef ITEMVENDA_H
#define ITEMVENDA_H

#include <string>
#include "gravavel.h"
#include "livro.h"

using namespace std;

class ItemVenda : public Gravavel{

private:
	Livro mLivro;
	int mQtd;
	float mValorUnit;	

	Livro buscaLivro(int isbn){
		Livro livro;
		return livro;
	}

public:
	ItemVenda(int isbn, int qtd){
		mLivro = buscaLivro;
		mQtd = qtd;
		mValorUnit = mLivro.getPreco();
	}

	void salvar(){

	}
	
	void setLivro(Livro livro){mLivro = livro;}
	Livro getLivro(){return mLivro;}
	
	void setQtd(int qtd){mQtd = qtd;}
	int getQtd(){return mQtd;}
	
	void setValorUnit(float valorUnit){mValorUnit = valorUnit;}
	float getValorUnit(){return mValorUnit;}

	char * getFile(){return (char *)"db/itemvenda.flan";}	
	
};

#endif