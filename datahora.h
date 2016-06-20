#ifndef DATAHORA_H
#define DATAHORA_H

#include <stdlib.h>
#include <string>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "arquivo.h"

using namespace std;

class DataHora{

private:
	int mDia;
	int mMes;
	int mAno;
	int mHora;
	int mMinuto;			
	
public:
	DataHora(){};
	
	DataHora(int dia, int mes, int ano){
		mDia = dia;
		mMes = mes;
		mAno = ano;		
	}
	
	DataHora(int dia, int mes, int ano, int hora, int minuto){
		mDia = dia;
		mMes = mes;
		mAno = ano;	
		mHora = hora;
		mMinuto = minuto;				
	}

	void setNow(){
		time_t now = time(0);
		string dt = ctime(&now);

		string dia = dt.substr(8, 2);
		string mes = dt.substr(4, 3);
		string ano = dt.substr(20, 4);

		mDia = atoi(dia.c_str());
		mMes = getMesFromStr(mes);
		mAno = atoi(ano.c_str());

		string hora = dt.substr(11, 2);
		string minuto = dt.substr(14, 2);

		mHora = atoi(hora.c_str());
		mMinuto = atoi(minuto.c_str());

	}
	
	void salvar(Arquivo& arquivo){

		arquivo.salvar(mDia);
		arquivo.salvar(mMes);
		arquivo.salvar(mAno);
		arquivo.salvar(mHora);
		arquivo.salvar(mMinuto);
		
	}
	
	void ler(Arquivo& arquivo){

		arquivo.ler(&mDia);
		arquivo.ler(&mMes);
		arquivo.ler(&mAno);
		arquivo.ler(&mHora);
		arquivo.ler(&mMinuto);
		
	}
	
	void setDia(int dia){mDia = dia;}
	int getDia(){return mDia;}
	
	void setMes(int mes){mMes = mes;}
	int getMes(){return mMes;}
	
	void setAno(int ano){mAno = ano;}
	int getAno(){return mAno;}
		
	void setHora(int hora){mHora = hora;}
	int getHora(){return mHora;}
	
	void setMinuto(int minuto){mMinuto = minuto;}
	int getMinuto(){return mMinuto;}

	int getMesFromStr(string mes){

		if(mes == "Jan")
			return 1;
		else if(mes == "Feb")
			return 2;
		else if(mes == "Mar")
			return 3;
		else if(mes == "Apr")
			return 4;
		else if(mes == "May")
			return 5;
		else if(mes == "Jun")
			return 6;
		else if(mes == "Jul")
			return 7;
		else if(mes == "Aug")
			return 8;
		else if(mes == "Sep")
			return 9;
		else if(mes == "Oct")
			return 10;
		else if(mes == "Nov")
			return 11;
		else if(mes == "Dec")
			return 12;

		return 0;

	};

	string getDateFormat(){

		string data;

	    ostringstream dia, mes, ano;

	    dia << std::setfill('0') << std::setw(2) << getDia();
	    mes << std::setfill('0') << std::setw(2) << getMes();
	    ano << std::setfill('0') << std::setw(4) << getAno();

	    data = dia.str() + "/" + mes.str() + "/" + ano.str();

		return data;
	}

	string getTimeFormat(){

		string time;

	    ostringstream hora, minuto;

	    hora << std::setfill('0') << std::setw(2) << getHora();
	    minuto << std::setfill('0') << std::setw(2) << getMinuto();

	    time = hora.str() + ":" + minuto.str();

		return time;
	}	
	
};

#endif