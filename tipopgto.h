#ifndef TIPOPGTO_H
#define TIPOPGTO_H

#include <string>
#include "arquivo.h"

using namespace std;

class TipoPgto{

private:
	int mId;	
	string mTipo;
	
public:
	TipoPgto(){};

	TipoPgto(string tipo){
		mTipo = tipo;
	}

	bool operator== (TipoPgto aux){
		return (mTipo == aux.mTipo);
	}

	int salvar(){

		mId = 0;

		Arquivo arquivo(getFile());
		ifstream& iFile = arquivo.getIFile();

		TipoPgto aux;

		while(iFile.good()){
			aux.ler(arquivo);
			if (!iFile.good()) break; 
			mId = aux.getId();
			if (*this == aux) return mId;
		}
		
		arquivo.salvar(mId + 1);
		arquivo.salvar(mTipo);

		arquivo.close();

		return (mId + 1);

	}

	void ler(Arquivo& arquivo){

		arquivo.ler(&mId);
		arquivo.ler(&mTipo);

	}

	void buscar(int id){

		Arquivo arquivo(getFile());

		ifstream& iFile = arquivo.getIFile();

		iFile.seekg(0);

		while(iFile.good()){
			arquivo.ler(&mId);
			if (!iFile.good()) break;
			arquivo.ler(&mTipo);
			if (getId() == id) break;
		}

		arquivo.close();

	}
	
	void setId(int id){mId = id;}
	int getId(){return mId;}
	
	void setTipo(string tipo){mTipo = tipo;}
	string getTipo(){return mTipo;}

	char * getFile(){return (char *)"db/tipopgto.flan";}	
	
};

#endif