#include <iostream> 
using namespace std;
class Point {
private:
	int x;
	int y;
public:
	Point(int m = 0, int n = 0) { x = m; y = n; }
	friend ostream& operator<<(ostream& out, const Point& p); //  const reference, cannot modify p
	friend istream& operator>>(istream& in, Point& p); // must be reference to p in order to change p.x and p.y through in>> 

};
ostream& operator<<(ostream& out, const Point& p)
{
	out << p.x<<" "<<p.y;
	return out;

}

istream& operator>>(istream& in, Point& p)
{
	in >> p.x;
	in >> p.y;
	return in;
}

int main()
{
	Point p;
	while (cin>> p) {
		cout<< p <<endl;
	}
	return 0;
}