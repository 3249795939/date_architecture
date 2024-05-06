#include "DoubleLinkLoopList.h"
#include <iostream>

using namespace std;

int main(void)
{
	DoubleLinkLoopList* ptr = createDoubleLinkLoopList();
	puts("");
	ptr = initDoubleLinkLoopList(ptr);
	puts("");
	for (int i = 1; i <= 5; i++) {
		insertDoubleLinkLoopListHeader(ptr, i);
		puts("");
	}
	for (int i = 10; i <= 15; i++) {
		insertDoubleLinkLoopListRear(ptr, i);
		puts("");
	}
	cout << ptr->node_sum << endl;
	insertDoubleLinkLoopListKth(ptr, 100, 20);
	puts("");
	delDoubleLinkLoopListKth(ptr, 20);
	puts("");
	delDoubleLinkListHeader(ptr);
	puts("");
	cout << ptr->node_sum << endl;
	delDoubleLinkLoopListRear(ptr);
	puts("");
	cout << ptr->rear->val << endl;
	DoubleLinkLoopListTraversal(ptr);
	puts("");
	relDoubleLinkLoopList(ptr);
	return 0;
}