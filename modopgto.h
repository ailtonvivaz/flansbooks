#ifndef MODOPGTO_H
#define MODOPGTO_H

#include <string>
#include <vector>
#include "arquivo.h"
#include "tipopgto.h"

using namespace std;

class ModoPgto{

private:
	int mId;	
	TipoPgto mTipoPgto;
	float mValor;
	
public:
	ModoPgto(){};
	
	ModoPgto(string tipoPgto, float valor){
		mTipoPgto = TipoPgto(tipoPgto);
		mValor = valor;
	}

	int salvar(int idVenda){

		mId = 0;

		Arquivo arquivo(getFile());
		ifstream& iFile = arquivo.getIFile();

		ModoPgto aux;

		while(iFile.good()){
			aux.ler(arquivo);
			if (!iFile.good()) break; 
			mId = aux.getId();
		}
		
		arquivo.salvar(mId + 1);
		arquivo.salvar(idVenda);
		arquivo.salvar(mTipoPgto.getId());
		arquivo.salvar(mValor);

		arquivo.close();

	}

	void ler(Arquivo& arquivo){

		int idVenda, idTipoPgto;

		arquivo.ler(&mId);
		arquivo.ler(&idVenda);
		arquivo.ler(&idTipoPgto);
		arquivo.ler(&mValor);

		mTipoPgto.buscar(idTipoPgto);

	}

	vector<ModoPgto> buscar(int id){

		Arquivo arquivo(getFile());
		ifstream& iFile = arquivo.getIFile();

		vector<ModoPgto> modosPgto;

		while(iFile.good()){
			ler(arquivo);
			if (!iFile.good()) break;
			if (getId() == id)
				modosPgto.push_back(*this);
		}

		arquivo.close();

		return modosPgto;

	}
	
	void setId(int id){mId = id;}
	int getId(){return mId;}
	
	void setTipoPgto(TipoPgto tipoPgto){mTipoPgto = tipoPgto;}
	TipoPgto getTipoPgto(){return mTipoPgto;}
	
	void setValor(float valor){mValor = valor;}
	float getValor(){return mValor;}

	char * getFile(){return (char *)"db/modopgto.flan";}	
	
};

#endif