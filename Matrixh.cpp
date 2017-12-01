#include "Matrixh.h"




Matrixh::Matrixh(int width,int lenght)
{
	this->setwidth(width);
	this->setlenght(lenght);
	this->matrix=new int* [this->lenght];
		for (int i=0;i<this->lenght;i++)
		{
			this->matrix[i]=new int [this->width];
			for(int j=0;j<this->width;j++)
			{
				matrix[i][j]=0;
			}

		}

}


Matrixh::~Matrixh(void)
{
	for (int i=0;i<this->lenght;i++)
		{
				delete this->matrix[i];

		}
	delete this-> matrix;
	
}

//-------------------------------------
//seters

void Matrixh::setlenght(int lenght)
{
	if(lenght<=0)
	{
		while(lenght>0)
			{
				cout<<"leght can't be neg or zero try another"<<endl;
				cin>>lenght;
			}
	}

	this->lenght=lenght;
}

void Matrixh::setwidth(int width)
{
	if(width<=0)
	{
		while(width<=0)
			{
				cout<<"width can't be neg or zero try another"<<endl;
				cin>>width;
			}
	}
	this->width=width;

}
int*& Matrixh::operator[](const int x)const
{
	if(x>-1 && x<lenght)
	{
	 return matrix[x];
	}
	else
	{
		cout<<"illegall= you try change location that not alocated the program will close "<<endl;
		system("pause");
		exit(1);
	}
}
	


//int*& Matrixh::operator[](const int x)const
//{
//	if(x>0&&x<lenght)
//	{
//	return matrix[x];
//	}
//	else
//	{
//		cout<<"illegal active"<<endl;
//		//return NULL
//		//return;
//	}
//
//}

//int* Matrixh::operator[](const long y)const
//{
//	if(y>0&&y<lenght)
//	{
//	return matrix[y];
//	}
//	else
//	{
//		cout<<"illegal active"<<endl;
//		//return NULL
//		//return;
//	}
//
//}
//





Matrixh&  Matrixh:: operator + (const Matrixh& add)const
{
	Matrixh *temp=new Matrixh(this->width,this->lenght);
	//Matrixh temp(add.width,add.lenght);
	for (int i=0;i<this->lenght;i++)
		{
			for(int j=0;j<this->width;j++)
			{
				temp->matrix[i][j]=this->matrix[i][j]+add.matrix[i][j];
			}

		}
	
	return *temp;
}

Matrixh& Matrixh:: operator - (const Matrixh& sub)const
{
	Matrixh *temp=new Matrixh(this->width,this->lenght);
	for (int i=0;i<this->lenght;i++)
		{
			for(int j=0;j<this->width;j++)
			{
				temp->matrix[i][j]=this->matrix[i][j]-sub.matrix[i][j];
			}

		}
	
	return *temp;
	
}

Matrixh& Matrixh::operator * (const Matrixh& B)const
{
	int sum=0;
	if(this->width!=B.lenght)
	{
		cout<<"it's iilegal "<<endl;
		exit(1) ;
	}
	Matrixh *temp=new Matrixh (B.width,this->lenght);
	
	for(int i=0;i<this->lenght;i++)
	{
		for(int k=0;k<B.width;k++)
		{
			for(int j=0;j<this->width;j++)
			{
				sum=sum+(this->matrix[i][j]*B.matrix[j][k]);
			}
			temp->matrix[i][k]=sum;
			sum=0;
		}
	
	}
	return *temp;

}

Matrixh& Matrixh::operator * (const int& B)const
{
	Matrixh *temp=new Matrixh (this->width,this->lenght);
	for(int i=0;i<this->lenght;i++)
	{
		for(int j=0;j<this->width;j++)
		{
			temp->matrix[i][j]=B*this->matrix[i][j];
		}
	}
	return (*temp);
}
void Matrixh::operator=(const Matrixh&  put)
{
	if(this->lenght==put.lenght)
	
	{
		if (width!=put.width)
		{
			
	     this->width=put.width;            //כדכן רק את הרוחב ותקצה מחדש כל שורה כי מספר השורות שווה ורק הרוחב שונה 

			for (int i=0;i<lenght;i++)
			{
				delete matrix[i];
				matrix[i]=new int [width];
			}
		}
	}
	else 
	{
		for(int i=0;i<lenght;i++)      //שחרר כל מה שהיה 
		{
			delete matrix[i];
		}
		delete matrix;

		this->lenght=put.lenght;    //תעדכן אורך ורוחב 
	    this->width=put.width;

		matrix=new int*[lenght];     //תקצה מחדש את המקום למטריצה 
		for(int i=0;i<lenght;i++)
		{
			matrix[i]=new int [width];
		}
	}
	


	
   for(int i=0;i<lenght;i++)         //השמת כל המטריצה בכל מקרה  
   {
      for (int j=0;j<width;j++)
	  {
		  matrix[i][j]=put.matrix[i][j];
	  }
   }
}


Matrixh& operator * (const int B,const Matrixh & mul)
{
	return mul*B;
}

Matrixh& operator - (const Matrixh & neg)
{
	return neg*(-1);
}


ostream& operator << (ostream &out,const Matrixh& toprint)
{
	for(int i=0;i<toprint.lenght;i++)
	{
		for(int j=0;j<toprint.width;j++)
		{
			out<<toprint.matrix[i][j]<<"     ";
		}
		out<<endl;
	}
	return out;
}
