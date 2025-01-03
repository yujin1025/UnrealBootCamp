#include "SimpleVector.h"
#include <iostream>

int main() {
	SimpleVector<int> vec;

	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(7);

	vec.print();

	vec.sortData();
	std::cout << "���� �� : ";
	vec.print();

	vec.pop_back();
	std::cout << "������ ���� ���� �� : ";
	vec.print();

	return 0;
}

