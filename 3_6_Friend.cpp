#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString {
	char * p;
public:
	MyString(const char * s) {
		if (s) {
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else
			p = nullptr;
	}

	~MyString() { if (p) delete[] p; }

	// copy constructor -- deep copy
	MyString(const MyString& MyStr)
	{
		if (MyStr.p)
		{
			p = new char[strlen(MyStr.p) + 1];
			strcpy(p, MyStr.p);
		}
		else
			p = nullptr;
	}

	MyString& operator=(const MyString& MyStr)
	{
		// check for self-assignment
		if (this == &MyStr)
			return *this;
		delete p;

		if (MyStr.p)
		{
			p = new char[strlen(MyStr.p) + 1];
			strcpy(p, MyStr.p);
		}
		else
			p = nullptr;

		return *this;
	}

	MyString& Copy(const char* ctr) 
	{
		if (ctr) {
			p = new char[strlen(ctr) + 1];
			strcpy(p,ctr);
		}
		else
			p = nullptr;
		return *this;
	}

	friend ostream& operator<<(ostream &out, MyString& MyStr);
	friend istream& operator>>(istream &in, MyString& MyStr);
};

ostream& operator<< (ostream &out, MyString& MyStr)
{
	// Since operator<< is a friend of the MyString class, we can access
	// Point's members directly.
	out << (MyStr.p);
	return out;
}

istream& operator>> (istream &in, MyString& MyStr)
{
	in >> (MyStr.p);
	return in;
}
int main()
{
	char w1[200], w2[100];
	while (cin>>w1>>w2) {
		MyString s1(w1), s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout<<s1 << ","<<s2 <<","<<s3<<endl;
		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout<<s1<<","<<s2 <<","<<s3<<endl;
	}
	system("pause");
	return 0;
}