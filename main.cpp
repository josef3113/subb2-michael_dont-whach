#include "Matrixh.h"   // in this #include<iostream> and using namespace std;


void main()
{
	Matrixh m(2, 2);
	m[0][0] = 2;
	m[1][1] = 2;
	cout << m << endl;
	m = m;
	const Matrixh s = -m;
	cout << m << endl << s << endl;
	m = s + 2 * -m * m * 2 - s;
	cout << m << endl << s << endl;
	cout << s[1][1] << endl;
	system("pause");
}

