#include <string>
#include <stdlib.h>
#include <iostream>
#include "cadlivro.cpp"
#include "vendalivro.cpp"

using namespace std;

int op_selecionada(char op){

	if(op == 's' || op == 'S')
		exit(0);

	system("clear");

	switch(op){
		case '1':
			venda_livro();
			return 1;
		case '2':
			break;
	}

}

int main(){

	char op;
	int opValida = true;

	cad_livro();

	system("clear");

	do{

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

	}while(!opValida);

	cout<<endl;
	return 0;

}