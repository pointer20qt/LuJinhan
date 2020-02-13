#include<iostream>
#include<string>
using namespace std;

class teacher
{
private:
	string tname;
	int age;
	int val;
public:
	virtual void talk()
	{
		cout << "上课了" << endl;
	}
	teacher()
	{
		cout << "teacher创建了" << endl;
	}
	 virtual ~teacher()
	{
		cout << "teacher析构" << endl;
	}
};

class mathTeacher :public teacher
{
public:
	void talk()
	{
		cout << "数学课上课了" << endl;
	}
	mathTeacher()
	{
		cout << "mathTeacher创建了" << endl;
	}
	~mathTeacher()
	{
		cout << "mathTeacher析构了" << endl;
	}
};

void test(teacher* t)
{
	t->talk();
}

int main()
{
	teacher* t = new mathTeacher();
	delete t;
	return 0;
}
