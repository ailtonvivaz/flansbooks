#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "livro.h"
#include "outtable.h"

using namespace std;

void imprimir_livros(){

	Livro livro;
	vector<Livro> vLivro;
	Arquivo arquivoLivro(livro.getFile());

	vector<Autor> autores;
	vector<Autor>::iterator pos;

	ifstream& iFile = arquivoLivro.getIFile();

	OutTable tabela;

	tabela.addstr("ISBN");
	tabela.addstr("TITULO");
	tabela.addstr("EDITORA");
	tabela.addstr("ANO");
	tabela.addstr("PRECO");
	tabela.addstr("AUTORES");

	while(iFile.good()){

		livro.ler(arquivoLivro);
		if(!iFile.good()) break;

		tabela.addstr(livro.getIsbn());
		tabela.addstr(livro.getTitulo());
		tabela.addstr(livro.getEditora());
		tabela.addstr(livro.getAno());
		tabela.addstr(livro.getPreco());

		bool linha = false;

		autores = livro.getAutores();

		for (pos = autores.begin(); pos != autores.end(); pos++){

			if(linha){
				for (int i = 0; i < 5; i++){
					tabela.addstr("");
				}
			}

			string autor = (*pos).getNome() + " " + (*pos).getSobrenome();
			tabela.addstr(autor);
			linha = true;

		}

		cout<<endl;

	}

	cout<<tabela.getOutTable(6);

}

void cad_livro(){

	Livro livro;
	vector<Livro> vLivro;
	vector<Livro>::iterator pos;

	remove("db/livro.flan");
	remove("db/autor.flan");
	remove("db/autorlivro.flan");

	livro = Livro(1, "Livro 1", "Editora 1", 2000, 22.5);
	livro.addAutor("Julio", "Fonseca");
	livro.addAutor("Pedro", "do Amaral");
	livro.salvar();

	livro = Livro(2, "Livro 2", "Editora 1", 2002, 32.5);
	livro.addAutor("Julio", "Fonseca");
	livro.addAutor("Joao", "Carvalho");
	livro.salvar();

	livro = Livro(3, "Livro 3", "Editora 2", 2002, 20.);
	livro.addAutor("Elton", "Venturi");
	livro.salvar();

	Escolar escolar(4, "Fisica II", "Editora 3", 2008, 66.3, 1996);
	escolar.addAutor("David", "Halliday");
	escolar.addAutor("Robert", "Resnick");
	escolar.salvar();

	Ficcao ficcao(5, "A Flan que roubava livros", "Editora 3", 2007, 100.);
	ficcao.addAutor("David", "Halliday");
	ficcao.addAutor("Robert", "Resnick");
	ficcao.salvar();

}

int op_selecionada(char op){

	if(op == 's' || op == 'S')
		exit(0);
		return 1;

	switch(op){
		case '1':
			cad_livro();
			return 1;
		default:
			return 0;
	}

}

int main(){

	char op;
	int opValida = true;

	cad_livro();
	imprimir_livros();

	/*do{

		system("clear");

		cout<<"Flan's Books\n\n";

		cout<<"1 - Realizar Venda"<<endl;
		cout<<"2 - Imprimir relatorio"<<endl;

		cout<<"\ns - Sair"<<endl;


		cout<<endl;

		if(!opValida)
			cout<<"A opcao \'"<<op<<"\' eh invalida. "<<endl;

		cout<<"Digite a opcao desejada: ";
		cin>>op;
		opValida = op_selecionada(op);

		cout<<endl;

	}while(!opValida);*/

	cout<<endl;
	return 0;

}