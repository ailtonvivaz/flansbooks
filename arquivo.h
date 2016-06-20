#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <sstream>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

class Arquivo{

private:
	ifstream mIFile;
	ofstream mOFile;

public:
	Arquivo(char * file){
		mIFile.open(file, ios::binary | ios::in | ios::ate);
		mOFile.open(file, ios::binary | ios::out | ios::app);
		mIFile.seekg(0);
	}

	void salvar(string dado){

		int tam = dado.size();

		mOFile.write((char *)&tam, sizeof(tam));
		mOFile.write((char *)dado.c_str(), tam);

	}

	void salvar(int dado){

		mOFile.write((char *)&dado, sizeof(dado));

	}

	void salvar(float dado){

		mOFile.write((char *)&dado, sizeof(dado));

	}

	void ler(string * dado){

		int tam;
		mIFile.read((char *)&tam, sizeof(tam));

		char texto[tam+1];
		mIFile.read((char *)texto, tam);
		texto[tam] = '\0';

		*dado = string(texto);

	}

	void ler(int * dado){

		int temp;
		mIFile.read((char *)&temp, sizeof(temp));
		*dado = temp;

	}

	void ler(float * dado){

		float temp;
		mIFile.read((char *)&temp, sizeof(temp));
		*dado = temp;

	}

	int size(char * str){

		int i = 0;
		for (; *str != '\0'; str++) i++;
		return i;

	}

	void close(){
		mIFile.close();
		mOFile.close();
	}
	
	ofstream& getOFile(){return mOFile;}
	
	ifstream& getIFile(){return mIFile;}
	
	
	
};

#endif