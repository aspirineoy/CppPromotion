#include "CustomString.h"

CustomString::CustomString()
{
	length = 0;
	str = new char[length + 1];
	str[0] = '\0';
}

CustomString::CustomString(const char* s)
{
	length = strlen(s);
	str = new char[length + 1];
	strcpy(str, s);
}

CustomString::CustomString(const CustomString& other)
{
	length = other.length;
	str = new char[length + 1];
	strcpy(str, other.str);
}

CustomString::~CustomString()
{
	delete[] str;
}

CustomString& CustomString::operator=(const CustomString& other)
{
	if (this != &other) {
		delete[] str;
		length = other.length;
		str = new char[length + 1];
		strcpy(str, other.str);
	}
	return *this;
}

int CustomString::len() const
{
	return length;
}

CustomString CustomString::append(const CustomString& other) const
{
	CustomString result;
	result.length = length + other.length;
	result.str = new char[result.length + 1];
	strcpy(result.str, str);
	strcat(result.str, other.str);
	return result;
}

bool CustomString::isEqual(const CustomString& other) const
{
	return (strcmp(str, other.str) == 0);
}
