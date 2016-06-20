#ifndef CADLIVRO_CPP
#define CADLIVRO_CPP

#include <vector>
#include "livro.h"
#include "outtable.h"

void imprimir_livros(){

	Livro livro;
	Arquivo arquivoLivro(livro.getFile());

	vector<Autor> autores;
	vector<Autor>::iterator pos;

	ifstream& iFile = arquivoLivro.getIFile();

	OutTable tabela;

	tabela.addstr("ISBN");
	tabela.addstr("TITULO");
	//tabela.addstr("EDITORA");
	tabela.addstr("ANO");
	tabela.addstr("PRECO");
	tabela.addstr("TIPO");
	//tabela.addstr("AUTORES");

	while(iFile.good()){

		livro.ler(arquivoLivro);
		if(!iFile.good()) break;

		tabela.addstr(livro.getIsbn());
		tabela.addstr(livro.getTitulo());
		//tabela.addstr(livro.getEditora());
		tabela.addstr(livro.getAno());
		tabela.addstr(livro.getPreco());
		tabela.addstr(livro.getTipo());

		bool linha = false;

		/*autores = livro.getAutores();

		for (pos = autores.begin(); pos != autores.end(); pos++){

			if(linha){
				for (int i = 0; i < 5; i++){
					tabela.addstr("");
				}
			}

			string autor = (*pos).getNome() + " " + (*pos).getSobrenome();
			tabela.addstr(autor);
			linha = true;

		}*/

	}

	cout<<tabela.getOutTable(5);

	arquivoLivro.close();

}

void cad_livro(){

	Livro livro;
	vector<Livro> vLivro;
	vector<Livro>::iterator pos;

	remove("db/livro.flan");
	remove("db/autor.flan");
	remove("db/autorlivro.flan");
	remove("db/categoria.flan");
	remove("db/escolar.flan");
	remove("db/categorialiterario.flan");

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

	Literario literario(5, "A Flan que roubava livros", "Editora 3", 2007, 100.);
	literario.addAutor("David", "Halliday");
	literario.addAutor("Robert", "Resnick");
	literario.addCategoria("Romance");
	literario.addCategoria("Comedia");
	literario.salvar();

	//imprimir_livros();

}

#endif