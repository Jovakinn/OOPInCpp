#include <iostream>

class CVector
{
public:
	int x, y;
	CVector() {};
	CVector(int a, int b) : x(a), y(b) {}
};

class Dummy
{
public:
	bool isitme(Dummy& param);
};

bool Dummy::isitme(Dummy& param)
{
	if (&param == this)
	{
		return true;
	}
	else
	{
		return false;
	}
}


CVector operator+ (const CVector& lhs, const CVector& rhs)
{
	CVector temp;
	temp.x = lhs.x + rhs.x;
	temp.y = lhs.y + rhs.y;

	return temp;
}

class MyClass
{
public:
	int x;
	MyClass(int val) : x(val) {}

	const int& get() const
	{
		return x;
	}


	int& get()
	{
		return x;
	}
};

template <class T>
class mypair
{
	T a, b;
public:
	mypair(T first, T second)
	{
		a = first;
		b = second;
	}
	T getmax();
};

template <class T>
T mypair<T>::getmax()
{
	T retval;

	retval = a > b ? a : b;
	return retval;
}


// template specialization
// class template
// 
template <class T>
class myContainer
{
	T element;

public:
	myContainer(T arg)
	{
		element = arg;
	}
	T increase()
	{
		return ++element;
	}
};

// class specialization

template <>
class myContainer<char>
{
	char element;

public:
	myContainer(char arg)
	{
		element = arg;
	}

	char upperCase()
	{
		if ((element >= 'a') && (element <= 'z'))
		{
			element += 'A' - 'a';
			return element;
		}
	}
};

int main()
{
	CVector foo(3, 1);
	CVector bar(1, 2);
	CVector result;

	result = foo + bar;
	std::cout << result.x << "," << result.y << '\n';


	Dummy a;
	Dummy* b = &a;

	if (b->isitme(a))
	{
		std::cout << "Yes" << '\n';
	}
	else
	{
		std::cout << "No" << '\n';
	}

	MyClass good(5);
	const MyClass bad(7);

	good.get() = 15;

	std::cout << good.get() << '\n';
	std::cout << bad.get() << '\n';

	std::cout << "Template in class:" << '\n';

	mypair<int> myobject(100, 59);
	std::cout << myobject.getmax() << '\n';

	std::cout << "Template specialization test:" << '\n';
	myContainer<int> myInt(69);
	myContainer<char> myChar('m');

	std::cout << myInt.increase() << '\n';
	std::cout << myChar.upperCase() << '\n';


	return 0;
}

