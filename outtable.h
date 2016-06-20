#ifndef OUTTABLE_H
#define OUTTABLE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

class OutTable{

	private:
		vector<string> vLegenda;
		vector<int> vMaior;
		vector<string>::iterator pos;
		vector<int>::iterator pMaior;

		void addDots(int colunas){

			string legenda, dots;

			for (int i = 0; i < colunas; i++){

				int maior = 0;

				for(pos = (vLegenda.begin() + i); pos < vLegenda.end(); pos += colunas){

					legenda = *pos;

					if(legenda.size() > maior)
						maior = legenda.size();

				}

				vMaior.push_back(maior);

			}

			for (int i = 0; i < colunas; i++){

				int maior = *(vMaior.begin() + i);

				for(pos = (vLegenda.begin() + i); pos < vLegenda.end(); pos += colunas){

					legenda = *pos;

					dots = "";

					for(int j = 0;j < (maior - legenda.size()); j++)
						dots = dots + " ";

					*pos = " " + legenda + dots + " |";

				}

			}

		}

	public:
		OutTable(){};

		void addstr(string leg){

			vLegenda.push_back(leg);

		}

		void addstr(int leg){
		
			stringstream lege;		
			lege << leg;

			addstr(lege.str());

		}

		void addstr(float leg, int precisao = 2){
		
			stringstream lege;		
			lege << fixed << setprecision(precisao) << leg;

			addstr(lege.str());

		}

		void clear(){vLegenda.clear();}

		string getOutTable(int colunas){

			string texto, linha, legenda;

			addDots(colunas);

			for(pos = vLegenda.begin(); pos < vLegenda.end(); pos += colunas){

				texto = texto + "|";

				for (int i = 0; i < colunas; i++)
					texto = texto + *(pos + i);

				texto = texto + "\n";

			}


			return texto;

		}

};

#endif