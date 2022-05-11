#include <ctime>
#include "quickSort.h"
#include "testQuickSort.h"

int main()
{
	srand(std::time(NULL));

	testQuickSort T(quickSort);

	T.setTestData();

	T.start();

	return 0;
}
 