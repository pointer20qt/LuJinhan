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
		cout << "������͹��캯��" << endl;
	}
	People(int age,string name,char address[20])
	{
		this->age = age;
		this->name = name;
		this->address = new char[20];
		strcpy(this->address,address);
		cout << "���˹��캯��" << endl;
	}
	People(const People& p) :age(p.age), name(p.name)
	{
		this->address = new char[20];
		strcpy(this->address,p.address);
		cout << "���˿������캯��" << endl;
	}
	People(People && p) :age(p.age), name(p.name)
	{

		cout << "�����ƶ����캯��" << endl;
	}
	~People()
	{
		delete [20] this->address;
		cout << "������������" << endl;
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
			cout << "����Խ����" << endl;
		}
	/*People a(30,"���","��ˮ");*/
	return 0;
}