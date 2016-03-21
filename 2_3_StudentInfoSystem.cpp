#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include <sstream>
#include<cstdlib>
using namespace std;

// Use cin>> to initialize our class
// use cin.getline(ch,20,',') to separate the in stream
// use stoi() to convert each separated char array to int
class Student {
	// 在此处补充你的代码
private:
	char stuName[20];
	int age;
	int stuID;
	int gradesFirst;
	int gradesSecond;
	int gradesThird;
	int gradesFourth;
	double gradesAvg;
public:
	void input() 
	{
		char Name[20];
		cin.getline(Name, 20, ',');
		strcpy(stuName, Name);
		char input[20];
		int inputAge, ID, grade1, grade2, grade3, grade4;
		cin.getline(input, 20, ',');
		inputAge = atoi(input);
		age = inputAge;
		cin.getline(input, 20, ',');
		ID = atoi(input);
		stuID = ID;
		cin.getline(input, 20, ',');
		grade1 = atoi(input);
		gradesFirst = grade1;
		cin.getline(input, 20, ',');
		grade2 = atoi(input);
		gradesSecond = grade2;
		cin.getline(input, 20, ',');
		grade3 = atoi(input);
		gradesThird = grade3;
		cin.getline(input,20);
		grade4 = atoi(input);
		gradesFourth = grade4;
	}

	void output()
	{
		cout << stuName << "," << age << "," << stuID << "," << gradesAvg<<endl;
	}
	void calculate()
	{
		gradesAvg = (gradesFirst + gradesSecond + gradesThird + gradesFourth) / 4.0;
	}
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
	system("pause");
	return 0;
}
