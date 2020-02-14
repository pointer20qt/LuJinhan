#include<iostream>
#include<initializer_list>
#define NDEBUG
#include<assert.h>
using namespace std;

class vec
{
	int* v;
public:
	vec(initializer_list<int> a)
	{
		v = new int[a.size()];
		for (int i = 0; i<a.size(); i++)
		{
			v[i] = *(a.begin() + i);
			assert(v[i]<=6&&v[i]>=0);
		}
		
	}
	~vec()
	{
		cout << "a";
		delete[]v;
	}
	int& operator[](int b)
	{
		return v[b];
	}
};
int main()
{
	vec a{ 1, 2, 3, 4, 5, 6 };
	a[2] = 10;
	cout << a[2];
}