#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <vector>
#include <fstream>
#include "gravavel.h"
#include "autor.h"
#include "categoria.h"
#include "arquivo.h"

using namespace std;

class Livro{

protected:
	int mIsbn;
	string mTitulo;
	string mEditora;
	int mAno;
	float mPreco;
	vector<Autor> mAutores;	

public:
	Livro(){};

	Livro(int isbn, string titulo, string editora, int ano, float preco){
		mIsbn = isbn;
		mTitulo = titulo;
		mEditora = editora;
		mAno = ano;
		mPreco = preco;						
	}

	void set(int isbn, string titulo, string editora, int ano, float preco){
		mIsbn = isbn;
		mTitulo = titulo;
		mEditora = editora;
		mAno = ano;
		mPreco = preco;						
	}

	void addAutor(string nome, string sobrenome){
		mAutores.push_back(Autor(nome, sobrenome));
	}

	vector<Autor> getAutores(){return mAutores;}
	
	void salvar(int tipo = 1, int anoEscolar = 0){

		Arquivo arquivo(getFile());

		arquivo.salvar(mIsbn);
		arquivo.salvar(mTitulo);
		arquivo.salvar(mEditora);
		arquivo.salvar(mAno);
		arquivo.salvar(mPreco);

		arquivo.salvar(tipo);
		arquivo.salvar(anoEscolar);

		arquivo.close();

		vector<Autor>::iterator pos;

		for (pos = mAutores.begin(); pos != mAutores.end(); pos++){
			int id = (*pos).salvar();

			Arquivo autorLivro((char *)"db/autorlivro.flan");

			autorLivro.salvar(id);
			autorLivro.salvar(mIsbn);

			autorLivro.close();
		}

	}

	void ler(Arquivo& arquivo){

		arquivo.ler(&mIsbn);
		arquivo.ler(&mTitulo);
		arquivo.ler(&mEditora);
		arquivo.ler(&mAno);
		arquivo.ler(&mPreco);

		int tipo, anoEscolar;		
		arquivo.ler(&tipo);

		if(tipo == 1 || tipo == 3)
			arquivo.ler(&anoEscolar);

		mAutores.clear();

		Arquivo autorLivro((char *)"db/autorlivro.flan");
		ifstream& iFile = autorLivro.getIFile();
		iFile.seekg(0);

		while(iFile.good()){
			int id;
			int isbn;

			autorLivro.ler(&id);
			if (!iFile.good()) break; 
			autorLivro.ler(&isbn);

			if(isbn == mIsbn){
				Autor aux;
				aux.buscarAutor(id);
				mAutores.push_back(aux);
			}

		}

	}
	
	void setIsbn(int isbn){mIsbn = isbn;}
	int getIsbn(){return mIsbn;}
	
	void setTitulo(string titulo){mTitulo = titulo;}
	string getTitulo(){return mTitulo;}
	
	void setEditora(string editora){mEditora = editora;}
	string getEditora(){return mEditora;}
	
	void setAno(int ano){mAno = ano;}
	int getAno(){return mAno;}
	
	void setPreco(float preco){mPreco = preco;}
	float getPreco(){return mPreco;}

	char * getFile(){return (char *)"db/livro.flan";}
	
};

class Escolar : public Livro{

private:
	int mAnoEscolar;
	
public:
	Escolar(int isbn, string titulo, string editora, int ano, float preco, int anoEscolar)
		:Livro(isbn, titulo, editora, ano, preco), mAnoEscolar(anoEscolar){};
	
	void salvar(){

		Livro::salvar(2, mAnoEscolar);

	}

	void ler(Arquivo& arquivo){

		Livro::ler(arquivo);

		arquivo.ler(&mAnoEscolar);

	}
	
	void setAnoEscolar(int anoEscolar){mAnoEscolar = anoEscolar;}
	int getAnoEscolar(){return mAnoEscolar;}


	char * getFile(){return (char *)"db/escolar.flan";}
	
};

class Ficcao : public Livro{

private:
	vector<Categoria> mCategorias;
		
public:
	Ficcao(int isbn, string titulo, string editora, int ano, float preco)
		:Livro(isbn, titulo, editora, ano, preco){};

	void addCategoria(string categoria){
		mCategorias.push_back(Categoria(categoria));
	}
	
	void salvar(){

		Livro::salvar(3);

		cout<<"teste"<<endl;

		/*vector<Categoria>::iterator pos;

		for (pos = mCategorias.begin(); pos != mCategorias.end(); pos++){
			int id = (*pos).salvar();

			Arquivo categoriaFiccao((char *)"db/categoriaFiccao.flan");

			categoriaFiccao.salvar(id);
			categoriaFiccao.salvar(mIsbn);

			categoriaFiccao.close();
		}*/

	}

	void ler(Arquivo& arquivo){

		Livro::ler(arquivo);

		//mAutores.clear();

		/*Arquivo categoriaFiccao((char *)"db/categoriaFiccao.flan");
		ifstream& iFile = categoriaFiccao.getIFile();
		iFile.seekg(0);

		while(iFile.good()){
			int id;
			int isbn;

			categoriaFiccao.ler(&id);
			if (!iFile.good()) break; 
			categoriaFiccao.ler(&isbn);

			if(isbn == mIsbn){
				Categoria aux;
				aux.buscarCategoria(id);
				mCategorias.push_back(aux);
			}

		}*/

	}

	vector<Categoria> getCategorias(){return mCategorias;}

	char * getFile(){return (char *)"db/livro.flan";}
	
};

#endif