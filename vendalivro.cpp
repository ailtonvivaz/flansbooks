#ifndef VENDALIVRO_CPP
#define VENDALIVRO_CPP

#include <vector>
#include <iostream>
#include <string>
#include "arquivo.h"
#include "livro.h"
#include "venda.h"
#include "datahora.h"
#include "outtable.h"

void print_itensVenda(Venda& venda){

	OutTable tabela;
	vector<ItemVenda> itensVenda;
	vector<ItemVenda>::iterator itemVenda;
	float totalVenda;
	
	itensVenda = venda.getItensVenda();

	//tabela.addstr("ISBN");
	tabela.addstr("TITULO");
	//tabela.addstr("EDITORA");
	//tabela.addstr("ANO");
	tabela.addstr("AUTORES");
	tabela.addstr("QTD");
	tabela.addstr("P.UNIT");
	tabela.addstr("TOTAL");

	for(itemVenda = itensVenda.begin(); itemVenda != itensVenda.end(); itemVenda++){

		Livro livro = (*itemVenda).getLivro();
		vector<Autor> autores;
		vector<Autor>::iterator pos;

		//tabela.addstr(livro.getIsbn());
		tabela.addstr(livro.getTitulo());
		//tabela.addstr(livro.getEditora());
		//tabela.addstr(livro.getAno());

		bool linha = false;

		autores = livro.getAutores();

		for (pos = autores.begin(); pos != autores.end(); pos++){

			if(linha){
				for (int i = 0; i < 1; i++){
					tabela.addstr("");
				}
			}

			string autor = (*pos).getNome() + " " + (*pos).getSobrenome();
			tabela.addstr(autor);

			if(!linha){

				tabela.addstr((*itemVenda).getQtd());
				tabela.addstr(livro.getPreco());
				float total = (*itemVenda).getQtd() * (livro.getPreco());
				tabela.addstr(total);
				totalVenda += total;

			}

			linha = true;

		}

	}

	for (int i = 0; i < 4; i++)
		tabela.addstr("-");

	tabela.addstr(totalVenda);

	cout<<tabela.getOutTable(5)<<endl;

}

void venda_livro(){

	Venda venda;
	DataHora dataHora;
	int op;
	Livro livro, l;
	int isbn = 0, qtd = 1;

	dataHora.setNow();

	bool comIsbn = false;

	do{

		system("clear");

		cout<<"Flan's Books"<<endl;
		cout<<"Venda de Livro"<<endl;
		cout<<dataHora.getDateFormat()<<endl<<endl;

		if(comIsbn)
			print_itensVenda(venda);

		cout<<"1 - adicionar item"<<endl;
		cout<<"2 - adicionar pagamento"<<endl<<endl;

		cout<<"Digite a opcao: ";
		cin>>op;

		if(op == 1){

			cout<<"ISBN do livro: ";
			cin>>isbn;
			if(comIsbn = livro.buscar(isbn)){

				cout<<livro.getTitulo()<<endl;

				cout<<"*Para sair, digite -1"<<endl;
				cout<<"*Para salvar os itens, digite 0"<<endl<<endl;

				cout<<"Quantidade: ";
				cin>>qtd;

				venda.addItemVenda(livro, qtd);

			}

		}


	}while(comIsbn);

	/*venda.addItemVenda(4, 1);
	venda.addItemVenda(5, 2);
	venda.addModoPgto("Dinheiro", 12.);
	venda.addModoPgto("Cartao", 12.);
	venda.salvar();

	cout<<venda.getSaldo()<<endl;
	DataHora data;
	data = venda.getDataHora();
	cout<<data.getDateFormat()<<endl;
	cout<<data.getTimeFormat()<<endl;

	cout<<endl;

	Venda a;
	DataHora d;
	Arquivo arquivoVenda(a.getFile());
	a.ler(arquivoVenda);
	d = a.getDataHora();
	cout<<d.getDateFormat()<<endl;*/

}

#endif