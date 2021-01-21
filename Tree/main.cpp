#include <iostream>
#include "BinTree.h"
using namespace std;

int main()
{
	BinSearchTree T1;
	
	int len;
	cout << "len = ";
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		int k;
		cin >> k;
		T1.insert_1(k);
	}
	cout << endl;
	
	/*if (T1.find(l)) 
	{ 
		cout << "good" << endl; 
	}
	else 
	{
		cout << "not good" << endl;
	}*/

	cout << endl;

	
	cout << endl;
	T1.count_0();
	cout << endl;
	
	return 0;
}