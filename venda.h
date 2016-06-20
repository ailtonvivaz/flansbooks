#ifndef VENDA_H
#define VENDA_H

#include <string>
#include <vector>
#include "gravavel.h"
#include "itemvenda.h"
#include "modopgto.h"
#include "data.h"

using namespace std;

class Venda : Gravavel{

private:
	Data mData;
	vector<ItemVenda> mItensVenda;
	vector<ModoPgto> mModosPgto;
	
public:
	Venda(){};
	
	void addItemVenda(string isbn, int qtd){
		mItensVenda.push_back(ItemVenda(isbn, qtd));
	}
	
	void addModoPgto(string modoPgto, float valor){
		mModosPgto.push_back(ModoPgto(modoPgto, valor));
	}

	vector<ItemVenda> getItensVenda(){return mItensVenda;}

	vector<ModoPgto> getModosPgto(){return mModosPgto;}

	void salvar(){

	}

	float getSaldo(){
		float saldo;
		return saldo;
	}
	
	void setData(Data data){mData = data;}
	Data getData(){return mData;}

	char * getFile(){return (char *)"db/venda.flan";}	
	
};

#endif