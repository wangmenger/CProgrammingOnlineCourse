#include<iostream>
using namespace std;

bool Greater2(int n1, int n2)
{
	return n1 > n2;
}
bool Greater1(int n1, int n2)
{
	return n1 < n2;
}
bool Greater3(double d1, double d2)
{
	return d1 < d2;
}

template<class T1,class T2>
int partition(T1* t1, T1* t2, bool(*f)(T2 t3, T2 t4)) {
	const int mid = (t2 - t1) / 2;
	const T1 pivot = *(t1 + mid);
	// move the mid point value to the front.
	std::swap(*t1, *(t1 + mid));
	int i = 1; // already swap the mid one to the 0 index
	int j = t2 - t1 - 1;
	while (i <= j) {
		while (i <= j && f( *(t1 + i),pivot)) {
			i++;
		}

		while (i <= j && f( pivot,*(t1 + j))) { // t1+j  t1+t2-t1-1 = t2-1
			j--;
		}

		if (i < j) {
			std::swap(*(t1 + i), *(t1 + j));
		}
	}
	std::swap(*(t1 + i - 1), *t1);
	return i - 1;
}

template<class T1,class T2>
void quicksort(T1* t1, T1* t2, bool(*f)(T2 t3, T2 t4)) {
	if (t1 >= t2) {
		return;
	}
	int part = partition(t1, t2,f);
	quicksort(t1, t1 + part,f);
	quicksort(t1 + part + 1, t2,f);
}

template <class T1, class T2>
void mysort(T1* t1, T1* t2, bool (*f)(T2 t3, T2 t4))
{
	// quick sort, basic idea:
	// find a 'pivot value'.
	//move all values less than(or equal to) the pivot value to 'the left'.
	//move all values larger than the pivot to 'the right'.
	//quick - sort the values less than(or equal)
	//quick - sort the values larger than.
	quicksort(t1, t2, f);
}



// 在此处补充你的代码
#define NUM 5

int main()
{
	int an[NUM] = { 8,123,11,10,4 };
	mysort(an, an + NUM, Greater1); //从小到大排序
	for (int i = 0; i < NUM; i++)
		cout << an[i] << ",";
	mysort(an, an + NUM, Greater2); //从大到小排序
	cout << endl;
	for (int i = 0; i < NUM; i++)
		cout << an[i] << ",";
	cout << endl;
	double d[6] = { 1.4,1.8,3.2,1.2,3.1,2.1 };
	mysort(d + 1, d + 5, Greater3); //将数组从下标1到下标4从小到大排序
	for (int i = 0; i < 6; i++)
		cout << d[i] << ", ";
	system("pause");
	return 0;
}