#pragma once
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <exception>
using namespace std;

template<typename T>
class DynamicArray
{
private:
	T* p_ptr;
	size_t arrSize;
	size_t arrCapacity;
	
public:

	DynamicArray();
	DynamicArray(const DynamicArray&);
	~DynamicArray();

	const T* data() const noexcept;

	void append(const T&) noexcept;
	bool exists(const T&) const noexcept;
	bool empty() const noexcept;

	int remove(const T&) noexcept;
	int remove(const T&, bool) noexcept;
	void clear() noexcept;
	void sort();

	size_t size()const noexcept;
	size_t capacity() const noexcept;
	int find(const T&) const noexcept;

	// Added by JTZR
	//======

	T& front() const;
	T& back() const;
	//======

	T& operator[](int index);
	const T& operator[](int index) const;
};

#endif

