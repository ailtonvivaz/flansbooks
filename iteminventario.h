#ifndef ITEMINVENTARIO_H
#define ITEMINVENTARIO_H

#include <string>

using namespace std;

class ItemInventario{

private:
	string mIsbn;
	string mTituloLivro;
	float mPreco;
	int mQtdVendidos;	
	
public:
	ItemInventario(string isbn, string tituloLivro, float preco, int qtdVendidos){
		mIsbn = isbn;
		mTituloLivro = mTituloLivro;
		mPreco = mPreco;
		mQtdVendidos = mQtdVendidos;		
	}
	
	void setIsbn(string isbn){mIsbn = isbn;}
	string getIsbn(){return mIsbn;}
	
	void setTituloLivro(string tituloLivro){mTituloLivro = tituloLivro;}
	string getTituloLivro(){return mTituloLivro;}
	
	void setPreco(float preco){mPreco = preco;}
	float getPreco(){return mPreco;}
	
	void setQtdVendidos(int qtdVendidos){mQtdVendidos = qtdVendidos;}
	int getQtdVendidos(){return mQtdVendidos;}
	
};

#endif