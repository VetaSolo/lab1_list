#include <iostream>
#include "MyList.h"
using namespace std;

int main()
{
	MyList list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	cout << list << endl;
	cout << list.get_size()<<" - size" << endl;
	list.reverse();
	cout << list << " - reverse" << endl;

	list.push_front(2384);
	list.remove(2);
	cout << list << " - remove(2)" << endl;
	list.clear();
	cout << list << " - clear" << endl;;

	return 0;
}
