#include<iostream>
#include<vector>
using namespace std;

class People
{
	int age;
	string name;
	char* address;
public:
	People()
	{
		cout << "走了午餐构造函数" << endl;
	}
	People(int age,string name,char address[20])
	{
		this->age = age;
		this->name = name;
		this->address = new char[20];
		strcpy(this->address,address);
		cout << "走了构造函数" << endl;
	}
	People(const People& p) :age(p.age), name(p.name)
	{
		this->address = new char[20];
		strcpy(this->address,p.address);
		cout << "走了拷贝构造函数" << endl;
	}
	People(People && p) :age(p.age), name(p.name)
	{

		cout << "走了移动构造函数" << endl;
	}
	~People()
	{
		delete [20] this->address;
		cout << "走了析构函数" << endl;
	}
	void getAdress()
	{
		cout << this->address;
	}
};


int main()
{
	vector<int>a{1,2,3,4,5,6};
		try
		{
			for (int i = 0; i < 7; i++)
			{
				cout << a.at(i) << " ";
			}
		}
		catch (out_of_range)
		{
			cout << "数组越界了" << endl;
		}
	/*People a(30,"李白","天水");*/
	return 0;
}