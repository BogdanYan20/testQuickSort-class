#include "testQuickSort.h"

testQuickSort::testQuickSort(void (*foo)(std::vector<int>&, int, int))
{
	this->foo = foo;
}

void testQuickSort::start()
{
	if (nTests > 0)
	{
		for (size_t i = 0; i < nTests; i++)
		{
			if (data[i].size() != 0)
			{
				bool result = true;

				for (size_t j = 0; j < data[i].size(); j++)
				{
					reference.push_back(data[i][j]);
				}

				std::sort(reference.begin(), reference.end());

				foo(data[i], 0, data[i].size() - 1);

				for (size_t j = 0; j < data[i].size(); j++)
				{
					if (data[i][j] != reference[j])
					{
						result = false;
					}
				}

				if (result)
				{
					std::cout << "Test #" << i << ": Success" << std::endl;
				}

				else
				{
					std::cout << std::endl  << "Test #" << i << ": Fail\n Sort result: " << std::endl;

					for (auto el : data[i])
					{
						std::cout << el << " ";
					}

					std::cout << std::endl << "Reference: ";

					for (auto el : reference)
					{
						std::cout << el << " ";
					}

					std::cout << std::endl << std::endl;
				}

				reference.clear();
			}
			
			else
			{
				std::cout << std::endl << "Test #" << i << " are empty." << std::endl << std::endl;
			}
		}
	}

	else
	{
		std::cout << "Please, set data first." << std::endl;
	}
}

void testQuickSort::setTestData()
{
	nTests = rand() % 10 + 1;

	std::vector<int> temp;

	for (size_t i = 0; i < nTests; i++)
	{
		for (size_t i = 0; i < rand() % 20; i++)
		{
			temp.push_back(rand() % 100);
		}

		data.push_back(temp);

		temp.clear();
	}
}

void testQuickSort::setTestDataManual()
{
	std::vector<int> temp;

	std::string inputData = "";

	std::cout << "Set input data: ";

	std::getline(std::cin, inputData);

	std::cout << std::endl;

	getIntVector(temp, inputData);

	data.push_back(temp);

	nTests++;
}

void testQuickSort::getIntVector(std::vector<int> &temp, std::string str)
{
	if (str.size() != 0 && str.find_first_of("1234567890", 0) != str.npos)
	{
		size_t subStrEnd = 0;

		while (subStrEnd != str.npos)
		{
			size_t subStrBegin = str.find_first_of("1234567890", subStrEnd);

			subStrEnd = str.find_first_not_of("1234567890", subStrBegin);

			if (subStrEnd != str.npos)
			{
				temp.push_back(std::stoi(str.substr(subStrBegin, subStrEnd - subStrBegin)));
			}

			else
			{
				temp.push_back(std::stoi(str.substr(subStrBegin, subStrEnd)));
			}
		}
	}
}
 