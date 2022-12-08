// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include<bits/stdc++.h>
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
	int size,capacity;
	T* ptr;
public:
	RSVector(int x = 0);
	RSVector(T* arr, int n);
	RSVector(const RSVector& another);
	RSVector<T>& operator=(const RSVector<T>& another);
	RSVector<T>& operator=( RSVector<T>&& another);
    T& operator[](int index);
    int push_back(T data );
    T pop_back();
	typedef T* iterator;
	T* begin();
	T* end();
    bool operator==(const RSVector<T>& another);
    bool operator< (const RSVector<T>& another);
	T*& operator++();
	T* operator*();
	iterator operator+(iterator it);
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
		cout << ptr[i] << endl;
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
	return &ptr[size-1];
}

template<typename T>
inline T*& RSVector<T>::operator++()
{
	// // O: insert return statement here
}

template<typename T>
inline T* RSVector<T>::operator*()
{
	return nullptr;
}



template<typename T>
inline void RSVector<T>::erase(iterator it)
{
	// don't forget to check out of range

	int pos = it-ptr;
	for (int i = pos; i < size; i++) {
		ptr[i] = ptr[i + 1];
	}
	size--;
}

template<typename T>
inline void RSVector<T>::erase(iterator it1, iterator it2)
{
	cout << "herr";
	int pos1 = it1 - ptr;
	int pos2 = it2 - ptr;
	int diff = pos2 - pos1;
	diff++;
	for (int i = pos1; i < size; i++) {
		ptr[i] = ptr[i + diff];
	}
	size = size - diff;
}

template<typename T>
inline void RSVector<T>::insert(iterator it, T x)
{
	// don't forget to check the validation of input
	/*
	int pos = it - ptr;
	int z = ptr[size - 1];
	size++;
	for (int i = size - 2; i >= pos; i--) {
		ptr[i] = ptr[i - 1];
	}
	ptr[pos] = x;
	ptr[size - 1] = z;
	*/

}

template<typename T>
inline int RSVector<T>::get_size() const
{
	return size;
}

template<typename T>
inline RSVector<T>::~RSVector()
{
	delete[] ptr;
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
inline int RSVector<T>::push_back(T data) {
    if(size == capacity){
        T* newdata = new T[capacity*2];
        for(int i = 0; i < size; i++){
            newdata[i] = ptr[i];
        }
        delete[] ptr;
        capacity*=2;
        ptr = newdata;
    }
    ptr[size++] = data;
    return size;
}

template<typename T>
inline T RSVector<T>::pop_back(){
    if(size>0){
        size--;
        return ptr[size];
    }
}

template<typename T>
inline T& RSVector<T>::operator[](int index)
{
    if(index>=size){
        cout<<"Error array index is out of range"<<endl;
        exit(-1);
    }
    return ptr[index];
    /*try{
        if(index >= size)
            throw;
        cout<<"yes";
        return ptr[index];
    }
    catch (...){
        cout<<"Error array index is out of range"<<endl;
        exit(0);
    }*/
}

template<typename T>
inline int RSVector<T>::get_capacity() const
{
    return capacity;
}

template<typename T>
inline bool RSVector<T>::empty() {
    if(size==0)
        return true;
    return false;
}

template<typename T>
inline int RSVector<T>::resize() {
    T* newdata = new T[capacity*2];
    for(int i = 0; i < size; i++){
        newdata[i] = ptr[i];
    }
    delete[] ptr;
    capacity*=2;
    ptr = newdata;
    return size;
}

template<typename T>
inline void RSVector<T>::clear()
{
    for(int i=0;i<size;i++)
        ptr[i].~T();
    size=0;
}

template<typename T>
inline bool RSVector<T>::operator==(const RSVector<T>& another)
{
    if(size!=another.size) {
        return false;
    }
    for(int i=0;i<size;i++){
        if(ptr[i]!=another.ptr[i]){
            return false;
        }
    }
    return true;
}

template<typename T>
inline bool RSVector<T>::operator<(const RSVector<T>& another)
{
    for(int i=0;i<size;i++){
        if(ptr[i]>another.ptr[i] ){
            return false;
        }
    }
    if(this->operator==(another))return false;
    return true;
}
