#pragma once
#include<iostream>

using namespace std;

template<class T>
class L_autoPtr
{
	T* obj=nullptr;
public:
	L_autoPtr() = default;
	L_autoPtr(T* ptr)
	{
		obj = ptr;
	}
	~L_autoPtr()
	{
		delete obj;
	}
	L_autoPtr(L_autoPtr<T> &ptr)
	{
		obj = ptr.obj;
		ptr.obj = nullptr;
	}
	L_autoPtr& operator=(L_autoPtr<T> &ptr)
	{
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	void reset(T* ptr)
	{
		delete obj;
		obj = ptr;
	}
	T* release(T* ptr)
	{
		auto temp = obj;
		obj = nullptr;
		return temp;
	}
	T& operator *()
	{
		return *obj;
	}
	T* operator->()
	{
		return obj;
	}
};
