#pragma once
#include <iostream>
using namespace std;


class Matrixh
{
private :
	int ** matrix;
	int width;
	int lenght;
public:

	Matrixh(int whidth=1 ,int lenght=1 );
	~Matrixh(void);

	//int getwidth();
	//int getlenght();

	void setwidth(int);
	void setlenght(int);

	Matrixh& operator + (const Matrixh&)const;
	Matrixh& operator - (const Matrixh&)const;
	Matrixh& operator * (const Matrixh&)const;
	Matrixh& operator * (const int&)const;
	void operator =(const Matrixh&);
	int*& operator [](const int)const;

	friend ostream& operator << (ostream &out,const Matrixh&);
	friend Matrixh& operator * (const int B,const Matrixh & mul);
	friend Matrixh& operator - (const Matrixh & neg);




};

