#include "Matrixh.h"


Matrixh::Matrixh()         //defult constractor
{
	this->lenght=0;
	this->width=0;
	this->matrix=NULL;
}

Matrixh::Matrixh(int lenght,int width)
{
	bool skip = false;
	if( (lenght<=0) || (width<=0))          //check if value of lenght and width are above 0
	{
		this->lenght=0;
		this->width=0;
		this->matrix=NULL;
		skip = true;
		cout<<"one of value was wrongful so matrix not allocation"<<endl;
	}

	if(!skip)
	{
		this->lenght=lenght;
        this->width=width;


		this->matrix=new int* [this->lenght];     

		if(matrix==NULL)        //check if allocation  succeeded 
		{
			cout<<"the allocation failed, the program will close"<<endl;
			system("pause");
			exit(1);

		}
		else
		{
			for (int i=0;i < (this->lenght) ;i++)
			{
				this->matrix[i]=new int [this->width];

				if(matrix[i]==NULL)     //check if allocation  succeeded for every  row
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
}
Matrixh::Matrixh(const Matrixh & copy)      // copy constractor
{
	this->lenght=copy.lenght;
	this->width=copy.width;

	this->matrix=new int* [this->lenght];

	if(matrix==NULL)            //check if allocation  succeeded
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

			if(matrix[i]==NULL)     //check if allocation  succeeded for every row 
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

Matrixh::~Matrixh()
{
	for (int i=0;i<this->lenght;i++)
	{
		delete[] this->matrix[i];

	}
	delete[] this-> matrix;

}





//-----operators

int* Matrixh::operator[](const int & x)const
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







Matrixh  Matrixh:: operator + (const Matrixh& add)const
{
	if( (this->lenght!= add.lenght) ||  (this->width!=add.width)  )
	{
		cout<<"the matrix are not compatiable, the first matrix was returnd "<< endl;
		return (*this);

	}

	Matrixh temp(this->width,this->lenght);

	for (int i=0;i <  this->lenght  ;i++)
	{
		for(int j=0;j <  this->width ;j++)
		{
			temp[i][j]=this->matrix[i][j]+add[i][j];
		}

	}

	return temp;
}



Matrixh Matrixh:: operator - (const Matrixh& sub)const
{

	return (*this)+(-sub);

}


Matrixh Matrixh::operator * (const Matrixh& B)const
{
	
	if(this->width!=B.lenght)
	{
		cout<<"it's invalid operation ,the first matrix was returnd "<< endl; 
		return (*this);
		
	}

	int sum=0;
	Matrixh temp (B.width,this->lenght);

	for(int i=0;i < this->lenght ;i++)
	{
		for(int k=0;k<B.width;k++)
		{
			for(int j=0;j < this->width ;j++)
			{
				sum=sum+(this->matrix[i][j]*B[j][k]);
			}
			temp.matrix[i][k]=sum;
			sum=0;
		}

	}
	return temp;

}



Matrixh Matrixh::operator * (const int& B)const
{
	Matrixh temp (this->width,this->lenght);
	for(int i=0; i < this->lenght;i++)
	{
		for(int j=0;j < this->width;j++)
		{
			temp.matrix[i][j]=B*this->matrix[i][j];
		}
	}
	return temp;
}


Matrixh& Matrixh::operator=(const Matrixh&  put)
{
	if(this->lenght==put.lenght)   //if the lenght equal so there is no need to do new allocation for row 
	{
		if (width!=put.width)      //but if width not equal have need to do new allocation for evrey row in size of new whidth 
		{

			this->width=put.width;           

			for (int i=0;i<lenght;i++)
			{
				delete matrix[i];     //  deletion of the old allocation for every row

				matrix[i]=new int [width];  //and new allocation in new width
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
		for(int i=0;i<lenght;i++)      //this happen whene the lenght not equal so need to reallocate everything  
		{
			delete matrix[i];
		}
		delete matrix;

		this->lenght=put.lenght;    // update the lenght and width to new value 
		this->width=put.width;

		matrix=new int*[lenght];  //and do reallocate for new matrix 

		if(matrix==NULL)    //check if allocation succeeded
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
				if(matrix[i]==NULL)   // check if allocation of every row succeeded
				{
					cout<<"the allocation failed ,the program will close"<<endl;
					system("pause");
					exit(1);
				}
			}
		}
	}




	for(int i=0;i<lenght;i++)         //posting all value in new matrix  
	{
		for (int j=0;j<width;j++)
		{
			matrix[i][j]=put[i][j];
		}
	}
	return (*this);
}

//----friends 



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


//-------function

Matrixh operator * (const int &B,const Matrixh & mul)
{
	return mul*B;
}

Matrixh operator - (const Matrixh & neg)
{
	return neg*(-1);
}