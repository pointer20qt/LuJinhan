#include<iostream>

using namespace std;

class A
{private:
	int val;
	char* address;
public:
	A(int a) :val(a),address(new char[100]){};
	A(const A &a)
	{
		val = a.val;
		address = new char[100];
		//strcpy(address,a.address);
	}
	int getval()
	{
		return val;
	}
	~A()
	{
		delete[] address;
	}
	A(A&& other)
	{
		val = other.val;
		other.address = NULL;
	}
	void operator= (A &a)
	{
		val = a.val;
		address = new char[100];
		//strcpy(address, a.address);
	}
};
template<class T>
void Swap(T& a,T& b)
{
	T tmp(a);
	a = b;
	b = tmp;
}

int main()
{
	A a(5);
	A b(6);
	double c = 1, d = 2;
	Swap(a,b);
	cout << a.getval();
}