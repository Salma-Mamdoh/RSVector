// Assignment 3 Group Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"RSVector.h"
int main()
{
	RSVector<int>rs0(-100);
	int arr[5]={1,5,6,10,8};
	RSVector<int>rs1(10);
	cout << rs1.get_size() << endl;
	RSVector<int>rs2(arr, 3);
	cout << endl;
	RSVector<int>rs3(rs2);
	cout << endl;
	RSVector<int>rs4;
	rs4 = rs2;
	RSVector<int>rs5;
	rs5 = move(rs4);
	cout << rs5 << endl;
	//cout << rs4 << endl;
	cout << *(rs5.begin()) << endl;
	cout << *(rs5.end()) << endl;
	
	auto it = rs5.begin();
	cout << it << endl;
	cout << *it << endl;
	it++; // built in 
	cout << it << endl;
	cout << *it << endl;
	rs5.erase(it);
	cout << rs5 << endl;
	RSVector<int>rs10(arr, 4);
	// 1 5 6 10 
	rs10.erase(rs10.begin()+1, rs10.end()-1);
	cout << rs10 << endl;
	RSVector<int>rs11(arr, 4);
	//rs11.insert(rs11.begin(), 4);
	//cout << rs11 << endl;

}

