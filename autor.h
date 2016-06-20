#ifndef AUTOR_H
#define AUTOR_H

#include <string>
#include "arquivo.h"

using namespace std;

class Autor{

private:
	int mId;
	string mNome;
	string mSobrenome;

public:
	Autor(){};

	Autor(string nome, string sobrenome){
		mNome = nome;
		mSobrenome = sobrenome;
	}

	void set(string nome, string sobrenome){
		mNome = nome;
		mSobrenome = sobrenome;
	}

	bool operator== (Autor aux){
		return (mNome == aux.mNome && mSobrenome == aux.mSobrenome);
	}

	int salvar(){

		Arquivo arquivo(getFile());
		mId = 0;

		ifstream& iFile = arquivo.getIFile();

		iFile.seekg(0);

		Autor aux;

		while(iFile.good()){
			aux.ler(arquivo);
			if (!iFile.good()) break; 
			mId = aux.getId();
			if (*this == aux) return mId;
		}
		
		arquivo.salvar(mId + 1);
		arquivo.salvar(mNome);
		arquivo.salvar(mSobrenome);

		arquivo.close();

		return (mId + 1);

	}

	void ler(Arquivo& arquivo){

		arquivo.ler(&mId);
		arquivo.ler(&mNome);
		arquivo.ler(&mSobrenome);

	}

	Autor buscarAutor(int id){

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
	
	void setNome(string nome){mNome = nome;}	
	string getNome(){return mNome;}
	
	void setSobrenome(string sobrenome){mSobrenome = sobrenome;}
	string getSobrenome(){return mSobrenome;}

	char * getFile(){return (char *)"db/autor.flan";}	
	
};


#endif