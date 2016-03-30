#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s)
{
	int i = 0;
	for (; s[i]; ++i);
	return i;
}
void strcpy(char * d, const char * s)
{
	int i = 0;
	for (i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;

}
int strcmp(const char * s1, const char * s2)
{
	for (int i = 0; s1[i] && s2[i]; ++i) {
		if (s1[i] < s2[i])
			return -1;
		else if (s1[i] > s2[i])
			return 1;
	}
	return 0;
}

void strcat(char * d, const char * s)
{
	int len = strlen(d);
	strcpy(d + len, s);
}

class MyString
{
private:
	char* MyStr;
public:
	MyString() 
	{
		MyStr = new char[1];
		MyStr[0] = '\0';
	}

	MyString(const char* chr) 
	{
		MyStr = new char[strlen(chr)+1];
		strcpy(MyStr,chr);
		MyStr[strlen(chr)] = '\0';
	}

	MyString(const MyString& str) 
	{
		if (str.MyStr)
		{
			MyStr = new char[strlen(str.MyStr)+1];
			strcpy(MyStr, str.MyStr);
		}
		else
			MyStr = 0;
	}

	int operator< (const MyString& str) 
	{
		if (MyStr[0]<str.MyStr[0])
			return 1;
		else
			return 0;
	}
	int operator> (const MyString& str) 
	{
		if (MyStr[0]>str.MyStr[0])
			return 1;
		else
			return 0;
	}
	int operator==(const MyString& str)
	{
		if (MyStr[0]==str.MyStr[0])
			return 1;
		else
			return 0;
	}

	friend MyString operator+ (const MyString& str1, const MyString& str2);

	// Overloading = operator
	MyString& operator=(const MyString& str)
	{
		if (this == &str)
			return *this;
		delete[] MyStr;
		if (str.MyStr)
		{
			MyStr = new char[strlen(str.MyStr)];
			strcpy(MyStr, str.MyStr);
		}
		else
			MyStr = 0;
		return *this;
	}

	MyString& operator+=(const char* chr)
	{
		strcat(MyStr, chr);
		return *this;
	}

	char* operator()(int i, int j)
	{
		char* res = new char[j];
		for (int m = 0; m < j; m++)
		{
			res[m] = MyStr[i + m];
		}
		return res;
	}

	char& operator[](int i)
	{
		return MyStr[i];
	}

	friend ostream& operator<<(ostream& out, MyString& str);

};

ostream& operator<<(ostream& out, MyString& str)
{
	out << str.MyStr;
	return out;
}

MyString operator+ (const MyString& str1, const MyString& str2)
{
	char* temp = new char[strlen(str1.MyStr)];
	strcpy(temp, str1.MyStr);
	strcat(temp, str2.MyStr);
	return MyString(temp);
}

int CompareString(const void * e1, const void * e2)
{
	MyString * s1 = (MyString *)e1;
	MyString * s2 = (MyString *)e2;
	if (*s1 < *s2)
		return -1;
	else if (*s1 == *s2)
		return 0;
	else if (*s1 > *s2)
		return 1;
}
int main()
{
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big","me","about","take" };
	cout << "1. " << s1 << s2 << s3 << s4 << endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; i++)
		cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0, 4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5, 10) << endl;
	return 0;
}
