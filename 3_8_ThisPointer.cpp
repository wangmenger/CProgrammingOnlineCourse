#include<iostream>
using namespace std;
class A {
public:
	int val;

	A() { val = 123; }

	A(int x):val(x) {}

	A& GetObj() {
		return *this;
	}

	A(const A& a)
	{
		val = a.val;
	}

	A& operator=(const A& a)
	{
		val = a.val;
		return *this;
	}

	~A() {}
		
};
int main()
{
	int m, n;
	A a;
	cout<< a.val<<endl;
	while (cin >> m >> n) {
		a.GetObj() = m;
		cout <<a.val << endl;
		a.GetObj() = A(n);
		cout<<a.val<< endl;
	}
	return 0;
}