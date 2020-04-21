#include "MySet.h"

ostream& operator<<(ostream& out, MySet& s)
{
	for (int i = 0; i < s.size; i++)
	{
		out << s.pdata[i];
		out << endl;
	}
	return out;
}

bool MySet::operator == (MySet& s)
{
	for (int i = 0; i <= size; i++)
	{
		if (strcmp(this->pdata[i], s.pdata[i]) != 0)
		{
			cout << " Данные массивы строк не равны"<<endl;
			return false;
		}
	}
	return true;
}

bool MySet::is_element(const char* el)
{
	char* temp = new char [strlen(el)+1 ];
	for (int i = 0; i < strlen(el) + 1; i++)
	{
		temp[i] = el[i];
	}
	for (int i = 0; i <= size; i++)
	{
		if (strcmp(this->pdata[i], temp) == 0)
		{
			cout << "Элемент входит в множество";
			return true;
		}
	}
	return false;
}

void MySet::delete_element( int n)
{
	if (n<0 || n > size) { return; }
	for (int i = 0; i < size; i++)
	{
		this->pdata[n] = this->pdata[n+1];
	}
	size--;
}

MySet operator+(MySet& s1, MySet& s2)
{
	MySet temp(s1);
	for (int i = 0; i <= s2.size; i++)
	{
		if (temp.find(s2.pdata[i]) == -1)
		{
			temp.add_element(s2.pdata[i]);
		}
	}
	return MySet(temp);
}

MySet operator-( MySet& s1,  MySet& s2)
{
	MySet temp(s1);
	for (int i = 0; i <= s2.size; i++)
	{
		
		int n;
		n = temp.find(s2.pdata[i]);
		if (n != -1)
		{
			temp.delete_element(n);
		}
	}
	return MySet(temp);
   
}

MySet operator*(MySet& s1, MySet& s2)
{
	for (int i = 0; i <= s2.size; i++)
	{
		int n;
		n = s1.find(s2.pdata[i]);
		if (n == -1)
		{
			s1.delete_element(n);
		}
	}
	return s1;
}

MySet& MySet::operator+=(MySet& s)
{
	for (int i = 0; i <= s.size; i++)
	{
		if (this->find(s.pdata[i]) == -1)
		{
			this->add_element(s.pdata[i]);
		}
	}
	return *this;

}

MySet& MySet::operator-=(MySet& s)
{
	for (int i = 0; i <= s.size; i++)
	{
		int n;
		n = this->find(s.pdata[i]);
		if (n != -1)
		{
		    this->delete_element(n);
		}
	}
	return *this;
}

MySet& MySet::operator*=(MySet& s)
{
	for (int i = 0; i <= s.size; i++)
	{
		int n;
		n = this->find(s.pdata[i]);
		if (n == -1)
		{
			this->delete_element(n);
		}
	}
	return *this;
}

MySet& MySet::operator = (MySet& v)
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

