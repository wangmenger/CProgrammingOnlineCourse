#include <iostream>
using namespace std;
class B {
private:
	int nBVal;
public:
	void Print()
	{
		cout << "nBVal=" << nBVal << endl;
	}
	void Fun()
	{
		cout << "B::Fun" << endl;
	}
	B(int n) { nBVal = n; }
};

// 在此处补充你的代码
class D :public B
{
private:
	int nDval;
public:
	D(int x) :B(3*x) { nDval = x; }
	void Fun() 
	{
		cout << "D::Fun" << endl;
	}
	void Print()
	{
		B::Print();
		cout << "nDVal=" <<nDval<<endl;
	}
};

int main() {
	B* pb; 
	D* pd;
	D d(4); 
	d.Fun();
	pb = new B(2); 
	pd = new D(8);
	pb -> Fun();
	pd ->Fun();
	pb ->Print(); 
	pd ->Print();

	pb = &d; // pd now point to another D object, so Fun() and Print() will both change
	pb ->Fun();
	pb ->Print();
	system("pause");
	return 0;
}