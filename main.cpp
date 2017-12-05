#include"Matrixh.h"
//

//void main()
//{ 
//	Matrixh matrixA(2,2),matrixB(3,2),matrixC;
//	//matrixA[2][0]=9;
//	matrixA[0][0]=4;
//	matrixB[0][0]=8;
//	matrixB[0][1]=8;
//	matrixB[0][2]=6;
//	matrixB[1][1]=8;
//	matrixB[1][0]=7;
//	matrixB[0][0]=9;
//	matrixC=matrixA*matrixB;
//	cout<<matrixC;
//	//matrixA=matrixA-matrixA;
//	//cout<<matrixC;
//    matrixC=matrixA*5;
//	//cout<<matrixC<<endl;
//	//cout<<matrixC;
//	//matrixA=matrixA*5;
//	//cout<<matrixA;
//	//matrixA=-matrixA;
//	//cout<<matrixA;
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
//	system("pause");
//}

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
system ("pause");
}