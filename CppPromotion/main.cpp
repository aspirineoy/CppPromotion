#include "CustomString.h"

int main() {
	auto str1 = CustomString("test1");
	auto str2 = CustomString("test2, test3");

	cout << str1.len() << endl;
	cout << str2.len() << endl;
	str1 = "test31";
	cout << str1.len() << endl;

	auto str3=str1.append(str2);
	cout << str3.len() << endl;

}