#include<iostream>
using namespace std;
template<class T>

class Ref
{
	int R_count=0;
	T* obj=nullptr;
public:
	Ref(T* target) :obj(target)
	{
		++R_count;
	}
	inline void increase()
	{
		R_count++;
	}
	inline void reduce()
	{
		R_count--;
		if (R_count==0)
		{
			delete obj;
			delete this;
		}
	}
	T* get()
	{
		return obj;
	}
	int getCount()
	{

		return R_count;
	}
};

template<class T>
class H_sharePtr
{
	Ref<T>* ref=nullptr;
public:
	H_sharePtr()
	{
	}
	H_sharePtr(T* other)
	{
		ref = new Ref<T>(other);
	}
	H_sharePtr(const H_sharePtr& other)
	{
		ref = other.ref;
		if (ref)
		{
			ref->increase();
		}
	}
	H_sharePtr(H_sharePtr&& other)
	{
		ref = other.ref;
		other.ref = nullptr;
	}
	H_sharePtr operator=(const H_sharePtr& other)
	{
		if (ref)
		{
			ref->reduce();
		}
		ref = other.ref;
		if (ref)
		{
			ref->increase();
		}
		return *this;
	}
	H_sharePtr operator=(H_sharePtr&& other)
	{
		if (ref)
		{
			ref->reduce();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	void swap(H_sharePtr& other)
	{
		swap(ref,other.ref);
	}
	int getCount()
	{
		if (ref) return ref->getCount();
		return 0;
		
	}
	~H_sharePtr()
	{
		if (ref){
			ref->reduce();
		}
	}
};
class tool
{
public:
	tool()
	{
		cout << "无参构造函数" << endl;
	}
	~tool()
	{
		cout << "析构函数" << endl;
	}
	tool(const tool&)
	{
		cout << "拷贝构造函数" << endl;
	}
	tool(tool&&)
	{
		cout << "移动构造函数" << endl;
	}
};
