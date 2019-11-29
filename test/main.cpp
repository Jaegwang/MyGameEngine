
#include "ShortStringArray.h"

int main()
{
	ShortString<> a("abcgd");
	ShortString<> b("abceg");

	bool check = a != b;

	char c;
	std::cin >> c;

	return 0;
}