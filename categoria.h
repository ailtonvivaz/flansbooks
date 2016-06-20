#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
#include "arquivo.h"

using namespace std;

class Categoria {

private:
	int mId;	
	string mCategoria;	

public:
	Categoria(){};
	
	Categoria(string categoria){
		mCategoria = categoria;
	}

	bool operator== (Categoria aux){
		return (mCategoria == aux.mCategoria);
	}

	int salvar(){

		Arquivo arquivo(getFile());
		mId = 0;

		ifstream& iFile = arquivo.getIFile();

		iFile.seekg(0);

		Categoria aux;

		while(iFile.good()){
			aux.ler(arquivo);
			if (!iFile.good()) break; 
			mId = aux.getId();
			if (*this == aux) return mId;
		}
		
		arquivo.salvar(mId + 1);
		arquivo.salvar(mCategoria);

		arquivo.close();

		return (mId + 1);

	}

	void ler(Arquivo& arquivo){

		arquivo.ler(&mId);
		arquivo.ler(&mCategoria);

	}

	Categoria buscarCategoria(int id){

		Arquivo arquivo(getFile());

		ifstream& iFile = arquivo.getIFile();

		iFile.seekg(0);

		while(iFile.good()){
			ler(arquivo);
			if (!iFile.good()) break;
			if (getId() == id){
				arquivo.close();
				return *this;
			}
		}

	}
	
	void setId(int id){mId = id;}
	int getId(){return mId;}
	
	void setCategoria(string categoria){mCategoria = categoria;}
	
	string getCategoria(){return mCategoria;}

	char * getFile(){return (char *)"db/categoria.flan";}	
	
};

#endif