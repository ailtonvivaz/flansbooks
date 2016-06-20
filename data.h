#ifndef DATA_H
#define DATA_H

#include <string>

using namespace std;

class Data{

private:
	int mDia;
	int mMes;
	int mAno;	
	
public:
	Data(int dia, int mes, int ano){
		mDia = dia;
		mMes = mes;
		mAno = ano;		
	}
	
	void setDia(int dia){mDia = dia;}
	int getDia(){return mDia;}
	
	void setMes(int mes){mMes = mes;}
	int getMes(){return mMes;}
	
	void setAno(int ano){mAno = ano;}
	int getAno(){return mAno;}
	
};
#endif