#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <string>
#include "iteminventario.h"

using namespace std;

class Inventario{

private:
	vector<ItemInventario> itensInventario;

	void addItem(string isbn, string tituloLivro, float preco, int qtdVendidos){
		itensInventario.push_back(ItemInventario(string isbn, string tituloLivro, float preco, int qtdVendidos));
	}

public:
	Inventario(){

	}

	void ordenar(int tipoOrd){

	}

	void imprimir(){

	}
	
};

#endif