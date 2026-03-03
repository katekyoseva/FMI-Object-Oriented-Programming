#include <iostream>

//Task 1
bool isEven(int num)
{
	return num % 2 == 0;
}

int countOfElements(const int* arr, int size, bool (*pred)(int))
{
	if (!arr || !pred) return 0;

	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (pred(arr[i])) 
		{
			counter++;
		}
	}
	return counter;
}
// recursive
int countRecursive(const int arr[], int size, bool (*pred)(int)) 
{
	if (!arr || !pred) return 0;

	if (size == 0) return 0;

	return (pred(arr[0]) ? 1 : 0) + countRecursive(arr + 1, size - 1, pred);
}

//Task 2
bool isPrime(int num)
{
	if (num <= 1)
	{
		return false;
	}

	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0) 
		{
			return false;
		}
	}
	return true;
}

int* filter(int* arr, int size, bool (*pred)(int), int& newSize)
{
	if (!arr || !pred) return nullptr;

	newSize = 0;
	for (int i = 0; i < size; i++)
	{
		if (pred(arr[i]))
		{
			newSize++;
		}
	}

	int* result = new (std::nothrow) int[newSize];
	if (!result) return nullptr;

	for (int i = 0, j = 0; i < size; i++)
	{
		if (pred(arr[i]))
		{
			result[j++] = arr[i];
		}
	}

	return result;

}
void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
}
// recursive
int* filterRecursive(const int arr[], int size, bool (*pred)(int), int& newSize)
{
	if (!arr || !pred) return nullptr;

	if (size == 0) {
		newSize = 0;
		return nullptr;
	}

	int restSize;
	int* rest = filterRecursive(arr + 1, size - 1, pred, restSize);

	if (pred(arr[0])) {

		newSize = restSize + 1;

		int* result = new (std::nothrow) int[newSize];
		if (!result) return nullptr;

		result[0] = arr[0];

		for (int i = 0; i < restSize; i++)
		{
			result[i + 1] = rest[i];
		}

		delete[] rest;
		return result;
	}
	else {
		newSize = restSize;
		return rest;
	}
}

//Task 3
enum class Suit
{
	Unknown = -1,
	Clubs = 1,
	Hearts,
	Diamonds,
	Spades,
};

enum class Card
{
	Unknown = -1,
	Ace = 1, 
	Two, 
	Three, 
	Four, 
	Five, 
	Six, 
	Seven, 
	Eight, 
	Nine, 
	Ten,
	Jack, 
	Queen, 
	King
};

const char* SUITS[] = {
	"Clubs",
	"Hearts" ,
	"Diamonds",
	"Spades"
};

const char* CARDS[] = {
	"Ace", 
	"Two",
	"Three",
	"Four",
	"Five",
	"Six",
	"Seven",
	"Eight",
	"Nine",
	"Ten",
	"Jack",
	"Queen",
	"King"
};

void printCard(int suit, int card)
{
	if (card < 2 || card > 14) return;
	std::cout << CARDS[card - 1] << " of " << SUITS[suit - 1] << '\n';
}

// Task 4
int sum(int a, int b) 
{
	return a + b;
}

int multiply(int a, int b) 
{
	return a * b;
}

int fold(const int* arr, int size, int n, int (*f)(int, int))
{
	if (!arr || !f) return 0;

	int sum = n;
	for (int i = 0; i < size; i++)
	{
		sum = f(sum, arr[i]);
	}
	return sum;
}

// recursive
int foldRecursive(const int arr[], int size, int n, int (*f)(int, int)) 
{
	if (!arr || !f) return 0;
	if (size == 0) return n;

	return foldRecursive(arr + 1, size - 1, f(n, arr[0]), f);
}

int main()
{
	//Task 1
	/*int arr[] = {1, 2, 3, 4, 5};
	std::cout << countOfElements(arr, 5, isEven) << '\n';
	std::cout << countRecursive(arr, 5, isEven);*/

	//Task 2
	/*int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int newSize = 0;
	int* res = filter(arr, 8, isPrime, newSize);

	int newSize2 = 0;
	int* res2 = filterRecursive(arr, 8, isPrime, newSize2);

	printArr(res, newSize);
	std::cout << '\n';
	printArr(res2, newSize2);

	delete[] res;
	delete[] res2;*/

	//Task 3
	/*unsigned int suit, card;

	std::cin >> suit >> card;
	printCard(suit, card);*/

	// Task 4
	/*int arr[] = { 1,2,3,4,5 };
	int size = 5;

	std::cout << fold(arr, size, 0, sum) << '\n';
	std::cout << fold(arr, size, 1, multiply) << '\n';

	std::cout << foldRecursive(arr, size, 0, sum) << '\n';
	std::cout << foldRecursive(arr, size, 1, multiply) << '\n';*/
	
}
