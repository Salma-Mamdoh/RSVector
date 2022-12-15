#include<iostream>
#include<iterator>
#include <stdexcept>
using namespace std;

#pragma once
#ifndef RSVECTOR_RSVECTOR_H
#define RSVECTOR_RSVECTOR_H

template <typename T> class RSVector;
template <typename T> ostream& operator<<(ostream& output, const RSVector <T>& another);
template<typename T>
class RSVector
{
private:
	int size, capacity;
	T* ptr;
public:
	RSVector(int x = 0);
	RSVector(T* arr, int n);
	RSVector(const RSVector& another);
	RSVector<T>& operator=(const RSVector<T>& another);
	RSVector<T>& operator=(RSVector<T>&& another);
	T& operator[](int index);
	void push_back(const T& data);
	T pop_back();
	typedef T* iterator;
	T* begin();
	T* end();
	const T& operator*(iterator it) const;
	T& operator++();
	T& operator+(int x);
	bool operator==(const RSVector<T>& another);
	bool operator< (const RSVector<T>& another);
	void erase(iterator it);
	void erase(iterator it1, iterator it2);
	void insert(iterator it, T x);
	int get_size() const;
	int get_capacity() const;
	int resize();
	bool empty();
	void clear();
	friend ostream& operator<< <T>(ostream& output, const RSVector <T>& another);
	~RSVector();
};

#endif

template<typename T>
inline RSVector<T>::RSVector(int x)
{

	if (x < 0) {
		cout << "INValid argument " << endl;
	}

	if (x == 0) {
		capacity = 0;
		size = 0;
	}
	else if (x > 0) {
		size = x;
		capacity = size * sizeof(T);
		ptr = new T[size];
	}

}

template<typename T>
inline RSVector<T>::RSVector(T* arr, int n)
{
	size = n;
	ptr = new T[size];
	capacity = size * sizeof(T);
	for (int i = 0; i < size; i++) {
		ptr[i] = arr[i];
		//cout << ptr[i] << endl;
	}
}

template<typename T>
inline RSVector<T>::RSVector(const RSVector& another)
{
	size = another.size;
	capacity = another.size * sizeof(T);
	ptr = new T[size];
	for (int i = 0; i < size; i++) {
		ptr[i] = another.ptr[i];
		cout << ptr[i] << endl;
	}
}

template<typename T>
inline RSVector<T>& RSVector<T>::operator=(const RSVector<T>& another)
{
	if (this != &another) {
		if (this->size != another.size) {
			delete[]ptr;
			size = another.size;
			capacity = size * sizeof(T);
			ptr = new T[size];
		}
		for (int i = 0; i < size; i++) {
			this->ptr[i] = another.ptr[i];
			cout << this->ptr[i] << endl;
		}
	}
	else {
		cout << "this self assignment " << endl;
	}
	return *this;
}

template<typename T>
inline RSVector<T>& RSVector<T>::operator=(RSVector<T>&& another)
{
	if (this != &another) {
		delete[]ptr;
		this->size = another.size;
		this->ptr = another.ptr;
		this->capacity = another.capacity;
		another.ptr = nullptr;
		another.size = 0;
		another.capacity = 0;
	}
	else {
		cout << "this is self assignment" << endl;
	}
	return *this;
}

template<typename T>
inline T* RSVector<T>::begin()
{
	return &ptr[0];
}

template<typename T>
inline T* RSVector<T>::end()
{
	return &ptr[size - 1];
}

template<typename T>
inline const T& RSVector<T>::operator*(iterator it) const
{
	if ((it - ptr) >= 0 && (it - ptr) < size) {
		return ptr[it - ptr];
	}
	else {
		throw exception();
	}
}

template<typename T>
inline T& RSVector<T>::operator++()
{
	
	if (ptr++<=this->end()) {
		ptr++;
	cout << ptr << endl;
	return *(ptr);
	}
	else {
		throw exception();
	}
}

template<typename T>
inline T& RSVector<T>::operator+(int x)
{
	
	if ((ptr+x) <= this->end()) {
		ptr = ptr + x;
		cout << ptr << endl;
		return *(ptr);
	}
	else {
		throw exception();
	}
}

template<typename T>
inline void RSVector<T>::erase(iterator it)
{
	int pos = it - ptr;
	if (pos >= 0 && pos < size) {
		for (int i = pos; i < size; i++) {
			ptr[i] = ptr[i + 1];
		}
		size--;
	}
	else {
		throw exception();
	}
}

template<typename T>
inline void RSVector<T>::erase(iterator it1, iterator it2)
{
	int pos1 = it1 - ptr;
	int pos2 = it2 - ptr;
	if ((pos1 >= 0 && pos1 < size) && ((pos2 >= 0 && pos2 < size))) {
		int diff = pos2 - pos1;
			diff++;
			for (int i = pos1; i < size; i++) {
				ptr[i] = ptr[i + diff];
			}
		size = size - diff;
	}
	else {
		throw exception();
	}
}

template<typename T>
inline void RSVector<T>::insert(iterator it, T x)
{
	int pos = it - ptr;
	if (pos >= 0 && it<=this->end()) {
		++size;
		for (int i = size - 1; i > pos; i--) {
			ptr[i] = ptr[i - 1];
		}
		ptr[pos] = x;
	}
	else {
		throw exception();
	}
}

template<typename T>
inline int RSVector<T>::get_size() const
{
	return size;
}

template<typename T>
inline ostream& operator<<(ostream& output, const RSVector<T>& another)
{
	cout << "The elements of arr is :";
	for (int i = 0; i < another.size; i++) {
		output << another.ptr[i] << " ";
	}
	return output;
}


template<typename T>
void RSVector<T>::push_back(const T& data) {
	if (size < capacity) {
		ptr[size++] = data;
	}
	else {
		cout << "Resizing to " << capacity * 2 << endl;
		T* newdata = new T[capacity * 2];
		capacity *= 2;

		for (int i = 0; i < size; i++) {
			newdata[i] = ptr[i];
		}
		delete[] ptr;
		ptr = new T[size * 2];
		ptr= newdata;
		delete[] newdata;
		ptr[size++] = data;
	}

}

template<typename T>
inline T RSVector<T>::pop_back() {
	if (size > 0) {
		size--;
		return ptr[size];
	}
	else {
		throw exception();
	}
}

template<typename T>
inline T& RSVector<T>::operator[](int index)
{
	if (index < 0 || index>= size) {
		throw exception();
	}
	return ptr[index];
	
}

template<typename T>
inline int RSVector<T>::get_capacity() const
{
	return capacity;
}

template<typename T>
inline bool RSVector<T>::empty() {
	if (size == 0)
		return true;
	return false;
}

template<typename T>
inline int RSVector<T>::resize() {
	if (capacity < 2 * size) {
		T* newptr = new T[capacity * 2];
		for (int i = 0; i < size; i++) {
			newptr[i] = ptr[i];
		}
		delete[] ptr;
		capacity *= 2;
		ptr = newptr;
	}
	size *= 2;
	return size;
}

template<typename T>
inline void RSVector<T>::clear()
{
	for (int i = 0; i < size; i++)
		ptr[i].~T();
	size = 0;
}

template<typename T>
inline bool RSVector<T>::operator==(const RSVector<T>& another)
{
	if (size != another.size) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (ptr[i] != another.ptr[i]) {
			return false;
		}
	}
	return true;
}

template<typename T>
inline bool RSVector<T>::operator<(const RSVector<T>& another)
{
	for (int i = 0; i < size; i++) {
		if (ptr[i] > another.ptr[i]) {
			return false;
		}
	}
	if (this->operator==(another))return false;
	return true;
}
template<typename T>
inline RSVector<T>::~RSVector()
{
	//delete ptr;
}

