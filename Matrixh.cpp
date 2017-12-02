#include "Matrixh.h"


Matrixh::Matrixh()
{
	this->lenght=0;
	this->width=0;
	this->matrix=NULL;
}

Matrixh::Matrixh(int width,int lenght)
{
	
	this->setwidth(width);
	this->setlenght(lenght);
	this->matrix=new int* [this->lenght];
	if(matrix==NULL)
	{
		cout<<"the allocation failed, the program will close"<<endl;
		system("pause");
		exit(1);

	}
	else
	{
		for (int i=0;i<this->lenght;i++)
		{
			this->matrix[i]=new int [this->width];
			if(matrix[i]==NULL)
				{
					cout<<"the allocation failed ,the program will close"<<endl;
					system("pause");
					exit(1);
				}
			else
				{
					for(int j=0;j<this->width;j++)
					{
						this->matrix[i][j]=0;
					}
				}

		}
	}

}
Matrixh::Matrixh(const Matrixh & copy)      //copy constractor
{
	this->lenght=copy.lenght;
	this->width=copy.width;

	this->matrix=new int* [this->lenght];
	if(matrix==NULL)
		{
			cout<<"the allocation failed, the program will close"<<endl;
			system("pause");
			exit(1);
		}
	else
		{
			for (int i=0;i<this->lenght;i++)
			{
				this->matrix[i]=new int [this->width];
				if(matrix[i]==NULL)
					{
						cout<<"the allocation failed ,the program will close"<<endl;
						system("pause");
						exit(1);
					}
				else
				{
					for(int j=0;j<this->width;j++)
					{
						this->matrix[i][j]=copy[i][j];
					}
				}

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
//
//-------------------------------------
//seters

void Matrixh::setlenght(int lenght)
{
	if(lenght<=0)
	{
		while(lenght<=0)
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
//------------------------
//operators

int*& Matrixh::operator[](const int x)const
{
	if(x>-1 && x<lenght)
	{
	 return matrix[x];
	}
	else
	{
		cout<<"invalid operation= you try change location that not allocated ,the program will close "<<endl;
		system("pause");
		exit(1);
	}
}
	






Matrixh&  Matrixh:: operator + (const Matrixh& add)const
{
	Matrixh *temp=new Matrixh(this->width,this->lenght);
	if(temp==NULL)
		{
			cout<<"the allocation failed ,the program will close"<<endl;
			system("pause");
			exit(1);
		}
	else
	{

		for (int i=0;i<this->lenght;i++)
			{
				for(int j=0;j<this->width;j++)
				{
					temp->matrix[i][j]=this->matrix[i][j]+add[i][j];
				}

			}
		}
	
	return *temp;
}

Matrixh& Matrixh:: operator - (const Matrixh& sub)const
{

	return (*this)+(-sub);
	
}

Matrixh& Matrixh::operator * (const Matrixh& B)const
{
	int sum=0;
	if(this->width!=B.lenght)
		{
			cout<<"it's invalid operation ,the program will close "<<endl;
			system("pause");
			exit(1) ;
		}
	Matrixh *temp=new Matrixh (B.width,this->lenght);
	if(temp==NULL)
		{
			cout<<"the allocation failed ,the program will close"<<endl;
			system("pause");
			exit(1);
		}
	else
	{
	
			for(int i=0;i<this->lenght;i++)
			{
				for(int k=0;k<B.width;k++)
				{
					for(int j=0;j<this->width;j++)
					{
						sum=sum+(this->matrix[i][j]*B[j][k]);
					}
					temp->matrix[i][k]=sum;
					sum=0;
				}
	
			}
			return *temp;
	}

}

Matrixh& Matrixh::operator * (const int& B)const
{
	Matrixh *temp=new Matrixh (this->width,this->lenght);
	if(temp==NULL)
		{
			cout<<"the allocation failed ,the program will close"<<endl;
			system("pause");
			exit(1);
		}
	else
		{
			for(int i=0;i<this->lenght;i++)
			{
				for(int j=0;j<this->width;j++)
				{
					temp->matrix[i][j]=B*this->matrix[i][j];
				}
			}
			return *temp;
		}
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
				if(matrix[i]==NULL)
				{
					cout<<"the allocation failed ,the program will close"<<endl;
		            system("pause");
		            exit(1);
				}
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

		matrix=new int*[lenght];  //תקצה מחדש את המקום למטריצה 
		if(matrix==NULL)
			{
				cout<<"the allocation failed ,the program will close"<<endl;
				system("pause");
				exit(1);
			}
		else
		{
				for(int i=0;i<lenght;i++)
				{
					matrix[i]=new int [width];
					if(matrix[i]==NULL)
					{
						cout<<"the allocation failed ,the program will close"<<endl;
		                system("pause");
		                exit(1);
					}
				}
		}
	}
	


	
   for(int i=0;i<lenght;i++)         //השמת כל המטריצה בכל מקרה  
   {
      for (int j=0;j<width;j++)
	  {
		  matrix[i][j]=put[i][j];
	  }
   }
}


Matrixh& operator * (const int &B,const Matrixh & mul)
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
			out<<toprint[i][j]<<"     ";
		}
		out<<endl;
	}
	return out;
}
