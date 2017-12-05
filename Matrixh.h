#pragma once
#include <iostream>
using namespace std;
//

class Matrixh
{
private :
	int ** matrix;
	int width;
	int lenght;


public:
	Matrixh();                      //defult constractor
	Matrixh(int  ,int );
	Matrixh(const Matrixh&);        //copy constractor
	~Matrixh(void);

	//----getrs             not exist seters because after the matrix exist i can't change the size 

	int getwidth()const{return width;}
	int getlenght()const{return lenght;}

	//----operators

	Matrixh operator + (const Matrixh&)const;
	Matrixh operator - (const Matrixh&)const;
	Matrixh operator * (const Matrixh&)const;
	Matrixh operator * (const int&)const;
	Matrixh& operator =(const Matrixh&);
	int* operator [](const int&)const;

	//----friends

	friend ostream& operator << (ostream &out,const Matrixh&);
	friend Matrixh operator * (const int & B,const Matrixh & mul);
	friend Matrixh operator - (const Matrixh & neg);




};

