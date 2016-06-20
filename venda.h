#ifndef VENDA_H
#define VENDA_H

#include <string>
#include <vector>
#include "arquivo.h"
#include "itemvenda.h"
#include "modopgto.h"
#include "datahora.h"

using namespace std;

class Venda{

private:
	int mId;	
	DataHora mDataHora;
	vector<ItemVenda> mItensVenda;
	vector<ModoPgto> mModosPgto;
	
public:
	Venda(){
		mDataHora.setNow();
	};
	
	void addItemVenda(Livro livro, int qtd){
		mItensVenda.push_back(ItemVenda(livro, qtd));
	}
	
	void addItemVenda(int isbn, int qtd){
		mItensVenda.push_back(ItemVenda(isbn, qtd));
	}
	
	void addModoPgto(string modoPgto, float valor){
		mModosPgto.push_back(ModoPgto(modoPgto, valor));
	}
	
	void salvar(){

		Arquivo arquivo(getFile());

		arquivo.salvar(mId);
		mDataHora.salvar(arquivo);

		arquivo.close();

		vector<ItemVenda>::iterator itemVenda;
		vector<ModoPgto>::iterator modoPgto;

		for (itemVenda = mItensVenda.begin(); itemVenda != mItensVenda.end(); itemVenda++)
			(*itemVenda).salvar(mId);

		for (modoPgto = mModosPgto.begin(); modoPgto != mModosPgto.end(); modoPgto++)
			(*modoPgto).salvar(mId);

	}

	void ler(Arquivo& arquivo){

		arquivo.ler(&mId);
		mDataHora.ler(arquivo);

		arquivo.close();

		mItensVenda.clear();
		mModosPgto.clear();

		ItemVenda itemVenda;
		ModoPgto modoPgto;

		mItensVenda = itemVenda.buscar(mId);
		mModosPgto = modoPgto.buscar(mId);

	}

	vector<ItemVenda> getItensVenda(){return mItensVenda;}

	vector<ModoPgto> getModosPgto(){return mModosPgto;}
	
	void setId(int id){mId = id;}
	int getId(){return mId;}

	float getSaldo(){
		float saldo;
		return saldo;
	}
	
	void setDataHora(DataHora dataHora){mDataHora = dataHora;}
	DataHora getDataHora(){return mDataHora;}

	char * getFile(){return (char *)"db/venda.flan";}	
	
};

#endif