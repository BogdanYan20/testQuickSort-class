#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class testQuickSort
{

public:

	testQuickSort(void (*foo)(std::vector<int>&, int, int));

	void setTestData();

	void setTestDataManual();

	void start();

private:

	void (*foo)(std::vector<int>&, int, int);

	int nTests = 0;

	std::vector<std::vector<int>> data;

	std::vector<int> reference;

	void getIntVector(std::vector<int> &test, std::string str);
};
 