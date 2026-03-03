Пресметнете и проверете чрез оператора `sizeof` колко е големината на следните структури.
```c++
struct empty {
};
// 1

struct test1 {
	int number;
};
// 4

struct test2 {
	char symbol;
	int number;
};
// 8

struct test3 {
	char symbol;
	short sh;
	int number;
};
// 8

struct test4 {
	char symbol1;
	int number;
	char symbol2;
};
// 12

struct student {
	char* name;
	int* grades;
};
// 64-bit system - char* = 8B, int* = 8B => 16
// 32-bit system - char* = 4B, int* = 4B => 8

struct test5 {
	char a[5];
	int b;
	double c;
};
// 24

struct test6 {
	char a[3];
	short b;
	double c[4];
	char d;
};
// 48

```
---
```c++
struct A
{
	double c;
	char b; 
};
// 16

struct B
{
	char c;
};
// 1

struct C
{
	A obj;
	B obj2;
};
// 24 (we look at the largest primitive type - in this case double (from A))
```
---
```c++
struct A
{
	double c;
	char b;
	int k;
	char s;
};
// 24

struct B
{
	int a;
	char c;
	char d;
	float f;
};
// 12

struct C
{
	char arr[3];
	float f;
};
// 8

struct D
{
	C obj1;
	A obj2;
	int i;
	char c;
	B obj3;
	bool b;
	double d;
};
// 64 -> alignment is the biggest primitive type in the struct and the position that the instance strats on should be dividable by it
```
---
```c++
struct A
{
	int a;
	char b;
};
//8

struct B
{
	char c;
};
// 1

struct C
{
	char f;
	A obj; 
	B obj2;
	double d;
};
// 24
```