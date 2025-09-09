#pragma once

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <exception>
using std::exception;

template<typename T>
class DynamicArray
{
private:
	int p_size;
	T* p_ptr;


	void mergeSort(T genericArr[], const int& beginningIndex, const int& endingIndex);
	void merge(T [], const int& , const int& , const int& );
	void sort();

	class OutOfRange : public exception {
	private:
		const char* msg;

	public:
		OutOfRange() : msg("ERROR: INVALID RANGE ENTERED. "){}
		OutOfRange(const char* nMsg) : msg(nMsg) {}
		const char* what() noexcept {
			return msg;
		}
	};
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&);
	~DynamicArray();

	void append(const T&);
	void insert(const T&, const int&);
	const T& retrieve(const int&) const;
	void remove(const int&);
	bool exists(const T&) const;
	int size()const;

	bool erase(const T& needle, bool allOrOne);
	DynamicArray& operator=(const DynamicArray&);

	const T* data() const;
	friend class Statistical;
};

#endif