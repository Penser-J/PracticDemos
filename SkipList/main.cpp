#include <iostream>
#include "SkipList.h"

using namespace std;
int main()
{
	SkipList sl;
	sl.insertListNode(1);
	sl.insertListNode(3);
	sl.insertListNode(2);
	sl.insertListNode(4);
	sl.insertListNode(5);
	sl.insertListNode(-1);

	sl.display(); // 查看跳表结构

	cout << "Search for 2: " << (sl.searchListNode(2) ? "Found" : "Not Found") << endl;
	cout << "Search for 6: " << (sl.searchListNode(6) ? "Found" : "Not Found") << endl;

	cout << "Erase 3: " << (sl.eraseListNode(3) ? "Success" : "Not Found") << endl;
	cout << "Erase 10: " << (sl.eraseListNode(10) ? "Success" : "Not Found") << endl;

	sl.display();

	system("pause");
	return 0;
}