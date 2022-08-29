#include <iostream>
#include "header.h"
#include <string>
using std::cout;
int bag(int a, int b)
{
	return a + b;
}

struct String
{
public:
	char* line = nullptr;
};


int main() 
{
	setlocale(LC_ALL, "RUSSIAN");
	std::string a = "Bakit";

	cout << a;
}