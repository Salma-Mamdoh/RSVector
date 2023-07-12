// problem 9 Templete set.cpp : This file contains the 'main' function. Program execution begins and ends there.
//9.	Template – Set. Abdullah Mohamed uses a C++ version that does not support STL 
//and he needs a set class for his programming job. Help him by writing a template-based class that implements a set of items.
//  A set is a collection of items in which no item occurs more than once.
//  Internally, you may represent the set using the data structure of your choice (for example, list, vector, arrays, etc.).
//  However, the class should externally support the following functions:
//•	Add a new item to the set.If the item is already in the set then nothing happens.
//•	Remove an item from the set.
//•	Return the number of items in the set.
//•	Determine if an item is a member of the set.
//•	Return a pointer to a dynamically created array containing each item in the set.
//The caller of this function is responsible for de - allocating the memory.
//Test your class by creating different sets of different data types(for example, strings, integers, or other classes).
//If you add objects to your set, then you may need to overload the == and != operators for 
//the object’s class so your template - based set class can properly determine membership
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class SET {
private:
	T* ptr;
	vector<T>vec;
	int size,capacity;
public:
	SET(){};
	void add_item(T x);
	void remove_duplicates(vector<T>& v);
	void Print_set();
	int get_size();
	void remove_item(T x);
	bool is_exist(T x);
	void get_pointer();
	~SET();
	bool operator==(SET another);
	bool operator!=(SET another);

};

template<typename T>
void SET<T>::add_item(T x)
{
	vec.push_back(x);
	remove_duplicates(vec);
	sort(vec.begin(), vec.end());

}

template<typename T>
void SET<T>::remove_duplicates(vector<T>& v)
{
	auto end = v.end();
	for (auto it = v.begin(); it != end; ++it) {
		end = remove(it + 1, end, *it);
	}

	v.erase(end, v.end());
}

template<typename T>
void SET<T>::Print_set()
{
	cout << "the elements of the set is :";
	for (int i = 0; i < vec.size(); i++) {
		cout<< vec[i] << " ";
	}
	cout << endl;
}

template<typename T>
int SET<T>::get_size()
{
	return vec.size();
}

template<typename T>
void SET<T>::remove_item(T x)
{
	bool is_exist = false;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == x) {
			is_exist = true;
			vec.erase(vec.begin() + i);
		}
	}
	if (is_exist == 0) {
		cout << "This item is not in the set :)" << endl;
	}
}

template<typename T>
bool SET<T>::is_exist(T x)
{
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == x) {
			return 1;
		}
	}
	return 0;
}

template<typename T>
void SET<T>::get_pointer()
{
	size = vec.size();
	capacity = size * sizeof(T);
	ptr = new T[size];
	for (int i = 0; i < vec.size(); i++) {
		ptr[i] = vec[i];
	}
	cout << ptr << endl;
	cout << *ptr << endl;
}

template<typename T>
SET<T>::~SET()
{
	delete[] ptr;
}

template<typename T>
bool SET<T>::operator==(SET another)
{
	if (this->vec.size() != another.vec.size()) {
		return 0;
	}
	else {
		for (int i = 0; i < this->vec.size(); i++) {
			if (this->vec[i] != another.vec[i]) {
				return 0;
			}
		}
	}
	return 1;
}

template<typename T>
bool SET<T>::operator!=(SET another)
{
	if ((this->operator==(another)) == 1) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	// int 

	SET<int>s1;
	cout << "-----------test for int type set -----------" << endl;
	s1.add_item(10);
	s1.add_item(15);
	s1.add_item(10);
	s1.add_item(2);
	s1.Print_set();
	cout << s1.get_size() << endl;
	s1.remove_item(15);
	s1.Print_set();
	s1.remove_item(20);
	cout<<s1.is_exist(10)<<endl;
	cout << s1.is_exist(5) << endl;
	s1.get_pointer();
	SET<int>s3;
	s3.add_item(2);
	s3.add_item(10);
	cout << (s1 == s3) << endl;
	cout << (s1 != s3) << endl;
	
	// string
	SET<string>s2;
	cout << "-----------test for string type set -----------" << endl;
	s2.add_item("salma");
	s2.add_item("Mamdoh");
	s2.add_item("sabry");
	s2.add_item("Mamdoh");
	s2.Print_set();
	cout << s2.get_size() << endl;
	s2.remove_item("sabry");
	s2.Print_set();
	s2.remove_item("mogahed");
	cout << s2.is_exist("salma") << endl;
	cout << s2.is_exist("mogahed") << endl;
	s2.get_pointer();
	SET<string>s4;
	s4.add_item("salma");
	s4.add_item("mamdoh");
	s4.add_item("sabry");
	cout << (s2 == s4) << endl;
	cout << (s2 != s4) << endl;

}