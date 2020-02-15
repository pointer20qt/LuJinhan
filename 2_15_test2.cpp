#include<iostream>
#include<vector>
using namespace std;

//template<class... args>
//void Lprintf(args... d)
//{
//	
//}
void Lprintf()
{
}
template <class T,class... args> 
void Lprintf(T a,args... d)
{
	cout << a << endl;
	Lprintf(d...);
}
template<class T>
class stack
{
private:
	vector<T> vec;
public:
	void push(T a)
	{
		vec.push_back();
	}
	void pop(T a)
	{
		vec.pop_back();
	}
	T top(T a)
	{
		return vec.back();
	}
};



int main()
{
	Lprintf(1,2,3,4,"asd");
}