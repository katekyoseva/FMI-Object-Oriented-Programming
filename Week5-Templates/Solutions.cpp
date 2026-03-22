#include <iostream>

// Theory task
template <typename T>
void func(T a, T b)
{
	std::cout << a << b;
}

// Task 1
template<typename T>
T sum(T a, T b)
{
	return a + b;
}

// Task 2
template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// Task 3
template<typename T>
void print(const T* arr, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

template<>
void print(const char* arr, int length)
{
	std::cout << arr;
}

// Task 4
template<typename T1, typename T2, typename T3>
void printThree(const T1 a, const T2 b, const T3 c)
{
	std::cout << a << ' ' << b << ' ' << c;
}

// Task 5
template<typename T>
bool elem(const T& el, const T* arr, const int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (el == arr[i])
			return true;
	}

	return false;
}

// Task 6
int powerOf2(int& el)
{
	return el * el;
}

template<typename T>
void map(T* arr, const int size, T (*func)(T&))
{
	for (size_t i = 0; i < size; i++)
		arr[i] = func(arr[i]);
}

bool isEven(int n)
{
	return n % 2 == 0;
}

template<typename T>
T* filter(const T* arr, const int size, bool (*pred)(T), int& newSize)
{
	if (!arr || !pred) 
		return nullptr;

	newSize = 0;
	for (int i = 0; i < size; i++)
	{
		if (pred(arr[i]))
		{
			newSize++;
		}
	}

	int* result = new (std::nothrow) int[newSize];
	if (!result) 
		return nullptr;

	for (int i = 0, j = 0; i < size; i++)
	{
		if (pred(arr[i]))
		{
			result[j++] = arr[i];
		}
	}
	return result;
}

template<typename T>
T fold(const T* arr, int size, int n, T (*f)(T, T))
{
	if (!arr || !f) 
		return 0;

	T sum = n;
	for (int i = 0; i < size; i++)
	{
		sum = f(sum, arr[i]);
	}

	return sum;
}

int main()
{
	// Theory task
	//func<int>(1, 2);        //1 -> 1 2
	//func(1, 2);             //2 -> 1 2
	//func<double>(1.5, 2);   //3 -> 1.5 2.0
	//func(1.2, 2);           //4 -> error (different types)
	//func(3, 'a');           //5 -> error (different types)
	//func<int>(3, 'a');      //6 -> 3 97
	//func<int>(3, 010);      //7 -> 3 8

	// Task 1
	//std::cout << sum(1, 2);

	// Task 2
	//int a = 4;
	//int b = 5;
	//swap(a, b);
	//std::cout << a << " " << b;

	// Task 3
	//int arr[] = { 1, 2, 3 };
	//char arr1[] = "Hi";

	//print(arr, 3);
	//print(arr1, strlen(arr1));

	// Task 4
	// printThree(1, 1.2, 'a');

	// Task 5
	//int arr[] = { 1, 2, 3, 4, 1 };
	//std::cout << std::boolalpha << elem(1, arr, 5);
	//std::cout << std::boolalpha << elem(7, arr, 5);

	// Task 6
	//int arr[] = { 1, 2, 3 };
	//map(arr, 3, powerOf2);
	//print(arr, 3);
	//std::cout << '\n';

	//int arr1[] = { 1, 2, 3, 4, 5 };
	//int newSize = 0;
	//int* res = filter(arr1, 5, isEven, newSize);
	//print(res, newSize);
	//std::cout << '\n';
	//delete[] res;

	//int arr[] = { 1,2,3,4,5 };
	//int size = 5;
	//std::cout << fold(arr, size, 0, sum) << '\n';
}
