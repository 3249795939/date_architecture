#include "HufSeqTab.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	HufSeqTab tree = createHufSeqTab(10, a);
	HufCode* ptr = createHufCode(tree, 10);
	for (int i = 0; i < 10; i++) {
		cout << ptr[i] << endl;
	}
	releaseHufCode(ptr, 10);
	releaseHufSeqTab(tree);

	return 0;
}