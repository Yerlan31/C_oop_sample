
#include "MyVector.h"

MyVector::MyVector(const char* el, int maxsz)
{
	maxsize = MAX_SIZE;
	size = 0;
	pdata = new char* [maxsize];
	pdata[0] = new char[strlen(el) + 1];
	for (unsigned int i = 0; i < strlen(el) + 1; i++)
	{
		pdata[0][i] = el[i];
	}

}


MyVector::~MyVector()
{
	delete pdata;
}

MyVector::MyVector(const MyVector& v)
{
	this->pdata = new char* [v.maxsize];
	for (int i = 0; i <= v.size; i++)
	{
		this->pdata[i] = new char[strlen(v.pdata[i])+1];
		strcpy_s(this->pdata[i], strlen(v.pdata[i])+1,  v.pdata[i]);
	}
	this->size = v.size;
	this->maxsize = v.maxsize;

}


void MyVector::add_element(const char* el)
{
	if (size == maxsize - 1)
	{
		resize();
	}
	size++;
	pdata[size] = new char[strlen (el)+1];
	for (int i = 0; i < strlen(el)+1; i++)
	{

		pdata[size][i] = el[i];
	}
	//cout << pdata[size]<<endl;
}

bool MyVector::delete_element(int i)
{
	if (i<0 || i>maxsize-1)
	{
		cout << "Введенный номер для удаления некорректен" << endl;
		return false;
	}

	for (int j = i; j < maxsize - 1; j++)
	{
		pdata[j] = pdata[j + 1];
	}
	size--;
	return true;
}

int MyVector::find(char* el)
{
	for (int i=0; i < size; i ++)
	{
		if (strcmp(pdata[i], el) == 0)
			return i;
	}
	return -1;
}

void MyVector::resize()
{
	maxsize *= 2;
	char** temp = pdata;

	pdata = new char* [maxsize];

	for (int i = 0; i <= size; i++)
	{
		pdata[i] = new char[strlen(temp[i])+1];
		strcpy_s(pdata[i], strlen(temp[i]) + 1, temp[i]);
	}
}

MyVector& MyVector::operator=(MyVector& v)
{
	if (this == &v) return *this;
	this->pdata = new char* [v.maxsize];
	for (int i = 0; i < v.maxsize; i++)
	{
		this->pdata[i] = new char[strlen(v.pdata[i]) + 1];
		strcpy_s(this->pdata[i], strlen(v.pdata[i]) + 1, v.pdata[i]);
	}
	this->size = v.size;
	this->maxsize = v.maxsize;
	return *this;
}

char* MyVector :: operator[](int i)
{
	if (i<0 || i> maxsize) 
	{
		cout << "Введенный вами индекс массива неверен"<<endl; 
		return 0;
	}
	return pdata[i];
}

ostream& operator <<(ostream& out, MyVector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		out << v.pdata[i];
		out << endl;
	}
	return out;
}

void MyVector::sort()
{
	for (int i = 0; i<=size; i++)
	{
		for (int j=0; j<size-i; j++)
		{
			if (strcmp(pdata[i], pdata[i + 1]) == 1)
			{
				char* temp = pdata[i];
				pdata[i] = pdata[i + 1];
				pdata[i + 1] = temp;
			}
		}
	}
}
