#include<iostream>
using namespace std;
class Apple {
public:
	static int nTotalNumber;
	static void PrintTotal() {
		cout<<nTotalNumber<<endl;
	}
	// constructor
	Apple() 
	{
		nTotalNumber++;
	}
	//// copy constructor
	//Apple(const Apple& apple)
	//{
	//	nTotalNumber++;
	//}
	// destructor
	~Apple() 
	{
		nTotalNumber--;
	}

};
int Apple::nTotalNumber = 0;

Apple Fun(const Apple & a) {
	a.PrintTotal();
	return a;
}
int main()
{
	Apple * p = new Apple[4];
	Fun(p[2]);
	Apple p1, p2;
	Apple::PrintTotal();
	delete[] p;
	p1.PrintTotal();
	system("pause");
	return 0;
}