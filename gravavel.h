#ifndef GRAVAVEL_H
#define GRAVAVEL_H

#include <string>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

class Gravavel{

protected:
	ifstream mIFile;
	ofstream mOFile;

public:
	Gravavel(){};

	void salvarArquivo(string dado){

		cout<<"aqui"<<endl;

		int tam = dado.size();
		mOFile.write((char *)&tam, sizeof(tam));
		//mOFile.write((char *)dado.c_str(), tam);

	}

	void salvarArquivo(int dado){

		mOFile.write((char *)&dado, sizeof(dado));

	}

	void salvarArquivo(float dado, ofstream& file){

		mOFile.write((char *)&dado, sizeof(dado));

	}

	string lerArquivo(string dado){

		int tam;
		mIFile.read((char *)&tam, sizeof(tam));

		char texto[tam+1];
		mIFile.read((char *)&texto, tam);
		texto[tam] = '\0';

		return texto;

	}

	int lerArquivo(int dado){

		mIFile.read((char *)&dado, sizeof(dado));
		return dado;

	}

	float lerArquivo(float dado){

		mIFile.read((char *)&dado, sizeof(dado));
		return dado;

	}

	int size(char * str){

		int i = 0;
		for (; *str != '\0'; str++) i++;
		return i;

	}

	virtual char * getFile()=0;

	/*void setOFile(){
		cout<<mOFile<<endl;
		//cout<<*mOFile<<endl;
		mOFile = (ofstream *)malloc(sizeof(ofstream&));
		cout<<mOFile<<endl;
		//cout<<*mOFile<<endl;

		ofstream a;
		a.open(getFile(), ios::binary | ios::out | ios::app);
		mOFile.swap(a);
	}

	void setIFile(){
		mIFile = (ifstream *)malloc(sizeof(ifstream));
		mIFile.open(getFile(), ios::binary | ios::in | ios::ate);
	}*/
	
};

#endif