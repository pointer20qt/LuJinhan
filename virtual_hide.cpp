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
		cout << "�Ͽ���" << endl;
	}
	teacher()
	{
		cout << "teacher������" << endl;
	}
	 virtual ~teacher()
	{
		cout << "teacher����" << endl;
	}
};

class mathTeacher :public teacher
{
public:
	void talk()
	{
		cout << "��ѧ���Ͽ���" << endl;
	}
	mathTeacher()
	{
		cout << "mathTeacher������" << endl;
	}
	~mathTeacher()
	{
		cout << "mathTeacher������" << endl;
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
