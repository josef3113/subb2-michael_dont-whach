#include"Matrixh.h"
//
//
void main()
{
	Matrixh matrixA(2,3),matrixB(3,2),matrixC(1,1);
	matrixA[2][0]=9;
	matrixA[0][0]=4;
	//x=matrix[0][0];
	//cout<<"x"<<x<<endl;
	//matrixA=matrixA+matrixA;
	//cout<<matrix;
	//matrix=matrix-matrix;
    matrixC=matrixA*matrixB;
	cout<<matrixC;
	matrixA=matrixA*5;
	cout<<matrixA;
	matrixA=-matrixA;
	cout<<matrixA;
    //cin>>x;
	system("pause");
}

//void main(){
//Matrixh m(2, 2);
//m[0][0] = 2;
//m[1][1] = 2;
//cout << m << endl;
//m = m;
//const Matrixh s = -m;
//cout << m << endl << s << endl;
//m = s + 2 * -m * m * 2 - s;
//cout << m << endl << s << endl;
//cout << s[1][1] << endl;
//system ("pause");
//}