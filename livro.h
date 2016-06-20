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
	int mTipo;

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
	
	void salvar(int tipo = 1){

		Arquivo arquivo(getFile());

		arquivo.salvar(mIsbn);
		arquivo.salvar(mTitulo);
		arquivo.salvar(mEditora);
		arquivo.salvar(mAno);
		arquivo.salvar(mPreco);

		arquivo.salvar(tipo);

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
		arquivo.ler(&mTipo);

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
				aux.buscar(id);
				mAutores.push_back(aux);
			}

		}

	}
	
	bool buscar(int isbn){

		Arquivo arquivo(getFile());
		ifstream& iFile = arquivo.getIFile();
		iFile.seekg(0);

		while(iFile.good()){

			ler(arquivo);

			if (!iFile.good()) {
				arquivo.close();
				return false;
			}

			if (getIsbn() == isbn) break;

		}

		arquivo.close();

		return true;

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

	string getTipo(){

		if(mTipo == 1)
			return "Outro";
		else if(mTipo == 2)
			return "Escolar";
		else
			return "Literario";

	}
	
};

class Escolar : public Livro{

private:
	int mAnoEscolar;
	
public:
	Escolar(){};

	Escolar(int isbn, string titulo, string editora, int ano, float preco, int anoEscolar)
		:Livro(isbn, titulo, editora, ano, preco), mAnoEscolar(anoEscolar){};
	
	void salvar(){

		Arquivo arquivo(getFile());
		Livro::salvar(2);

		arquivo.salvar(mIsbn);
		arquivo.salvar(mAnoEscolar);

		arquivo.close();

	}

	void ler(Arquivo& arquivo){

		Livro::ler(arquivo);

		Arquivo escolar(getFile());

		ifstream& iFile = escolar.getIFile();
		iFile.seekg(0);

		while(iFile.good()){
			int isbn;
			int anoEscolar;

			escolar.ler(&isbn);
			if (!iFile.good()) break; 
			escolar.ler(&anoEscolar);

			if(isbn == mIsbn){
				mAnoEscolar = anoEscolar;
				break;
			}

		}

		escolar.close();

	}
	
	void buscar(int isbn){

		Livro::buscar(isbn);

		Arquivo arquivo(getFile());
		ifstream& iFile = arquivo.getIFile();

		while(iFile.good()){

			arquivo.ler(&isbn);
			if (!iFile.good()) break;
			arquivo.ler(&mAnoEscolar);

			if (getIsbn() == isbn) break;

		}

		arquivo.close();

	}
	
	void setAnoEscolar(int anoEscolar){mAnoEscolar = anoEscolar;}
	int getAnoEscolar(){return mAnoEscolar;}

	char * getFile(){return (char *)"db/escolar.flan";}

	string getTipo(){return "Escolar";}
	
};

class Literario : public Livro{

private:
	vector<Categoria> mCategorias;
		
public:
	Literario(){};

	Literario(int isbn, string titulo, string editora, int ano, float preco)
		:Livro(isbn, titulo, editora, ano, preco){};

	void addCategoria(string categoria){
		mCategorias.push_back(Categoria(categoria));
	}
	
	void salvar(){

		Livro::salvar(3);

		vector<Categoria>::iterator pos;

		for (pos = mCategorias.begin(); pos != mCategorias.end(); pos++){
			int id = (*pos).salvar();

			Arquivo categoriaLiterario((char *)"db/categorialiterario.flan");

			categoriaLiterario.salvar(id);
			categoriaLiterario.salvar(mIsbn);

			categoriaLiterario.close();
		}

	}

	void ler(Arquivo& arquivo){

		Livro::ler(arquivo);

		mCategorias.clear();

		Arquivo categoriaLiterario((char *)"db/categorialiterario.flan");
		ifstream& iFile = categoriaLiterario.getIFile();
		iFile.seekg(0);

		while(iFile.good()){
			int id;
			int isbn;

			categoriaLiterario.ler(&id);
			if (!iFile.good()) break; 
			categoriaLiterario.ler(&isbn);

			if(isbn == mIsbn){
				Categoria aux;
				aux.buscar(id);
				mCategorias.push_back(aux);
			}

		}

		categoriaLiterario.close();

	}
	
	void buscar(int isbn){

		Livro::buscar(isbn);

		mCategorias.clear();

		Arquivo categoriaLiterario((char *)"db/categorialiterario.flan");
		ifstream& iFile = categoriaLiterario.getIFile();
		iFile.seekg(0);

		while(iFile.good()){
			int id;
			int isbn;

			categoriaLiterario.ler(&id);
			if (!iFile.good()) break; 
			categoriaLiterario.ler(&isbn);

			if(isbn == mIsbn){
				Categoria aux;
				aux.buscar(id);
				mCategorias.push_back(aux);
			}

		}

		categoriaLiterario.close();


	}

	vector<Categoria> getCategorias(){return mCategorias;}

	string getTipo(){return "Ficcao";}
	
};

#endif