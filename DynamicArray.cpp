#include "DynamicArray.h"
#include <exception>
using namespace std;

constexpr int ALLOC_INCREMENTS = 5;



/*

Sort():
Best (O(n)) - once sorted
worst (O(n^2)) - mixed indices
*/
template<typename T>
void DynamicArray<T>::sort() {
	//base case: test if the array has only 1 element, as it'd be sorted. 
	if (arrSize <= 1) return;
	//begin array at index[1]
	for (int i = 1; i < arrSize; i++) {
		//set current comparison factor to arr[i]
			T key = p_ptr[i];
			//set separate index to [i-1]
			int j = i - 1;
			//test if j is >= 0, and while it is greater than j+1
		while (j >= 0 && p_ptr[j] > key) {
			//set j+1 (i) to it's previous value. 
			p_ptr[j + 1] = p_ptr[j];
			//iterate downward. 
			j--;
		}
		//otherwise reassign. 
		p_ptr[j + 1] = key;
	}
}


template<typename T>//default constructor to set ptr = null and all other values to 0. 
DynamicArray<T>::DynamicArray() : p_ptr(nullptr), arrSize(0), arrCapacity(0) {};


template<typename T>//copy constructor, which takes a const reference to avoid manipulation of it's direct values. 
DynamicArray<T>::DynamicArray(const DynamicArray& other) {
	//equate both array sizes 
	arrSize = other.arrSize;
	//equate both capacities. 
	arrCapacity = other.arrCapacity;
	//if capacity is greater than 0 (initialized)
	if (arrCapacity > 0) {
		//allocate n amount of elements equal to other capacity. 
		p_ptr = new T[arrCapacity];
		//iterate over the array elements of the other array. 
		for (int i = 0; i < arrSize; i++)
			p_ptr[i] = other.p_ptr[i]; // copy elements.
	}
	else {
		p_ptr = nullptr;//otherwise set to nullptr;
	}
}
//destructor
template<typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] p_ptr; // return pointer & memory to heap
	p_ptr = nullptr;
	arrSize = 0;
	arrCapacity = 0;
}

//precondition: none
//postcondition: the constant reference to data pointer (array beginning)
template<typename T>
const T* DynamicArray<T>::data() const noexcept {
	return p_ptr;
}

//precondition: valid state obj (initialized or overloaded with assignment operator
//postcondition: increased size (or adjusted capacity), with size+1 number of elements. 
template<typename T>
void DynamicArray<T>::append(const T& obj) noexcept {
	if (!p_ptr) {
		arrCapacity = ALLOC_INCREMENTS;
		p_ptr = new T[arrCapacity];
		p_ptr[0] = obj;
		arrSize++;
	}
	else {
		//if within current capacity, assign current index to passed index. 
		if (arrSize < arrCapacity) {
			p_ptr[arrSize] = obj;
			arrSize++;
		}
		else {
			//re-allocate 5 slots after completion
			T* newArr = nullptr;
			newArr = new T[arrCapacity + ALLOC_INCREMENTS];
			for (int i = 0; i < arrSize;i++)
				newArr[i] = p_ptr[i];
			delete[] p_ptr;
			p_ptr = newArr;
			p_ptr[arrSize] = obj;
			arrSize++;
		}
	}
}
//precondition: valid state needle to compare for existence. 
//postcondition: boolean returning existence of search target
template<typename T>
bool DynamicArray<T>::exists(const T& needle) const noexcept {
	if (p_ptr) {
		for (int i = 0; i < arrSize;i++)
			if (p_ptr[i] == needle)return true;
	}
	return false;
}
//precondition: none
//postcondition: returns current state of dynamicArray size
template<typename T>
bool DynamicArray<T>::empty() const noexcept {
	return (arrSize == 0);
}

//precondition: valid state needle or overloaded == operator for comparison
//postcondition: -1 if found, otherwise returns 1. 
template <typename T>
int DynamicArray<T>::remove(const T& needle) noexcept {
	int numInstances = 0;
	//test for null ptr
	if (!p_ptr) return -1;
	//test if the arr is size of 1 and if it is the search target
	else if (arrSize == 1 && p_ptr[0] == needle) {
		//reduce size
		arrSize--;
		return ++numInstances;
	}
	//if size if > 1 and not a nullptr;
	else {
		//iterate over array
		for (int i = 0; i < arrSize;i++) {
			//test if the current item is equal to search target
			if (p_ptr[i] == needle) {
				//
				for (int j = i; j < arrSize-1;j++) {
					p_ptr[j] = p_ptr[(j+1)];
				}
				arrSize--;
				return ++numInstances;
			}
		}
	}
	return -1;
}
//precondition: valid state needle and boolean true for all instances and false for one
// postcondition: removal of all instances of needle. 
//returns the number of instances removed. 
template<typename T>
int DynamicArray<T>::remove(const T& needle, bool allOrOne)noexcept {
	if (!p_ptr) return 0;
	int instances = 0;

	for (int i = 0; i < arrSize; i++) {
		if (p_ptr[i] == needle) {
			instances++;
			for (int j = i; j < arrSize - 1; j++)
				p_ptr[j] = p_ptr[j + 1];
			arrSize--;
			if (!allOrOne) break;
			i--;
		}
	}
	return instances;
}
//precondition: none
//postcondition: clears all elements in dynamic array
template<typename T>
void DynamicArray<T>::clear() noexcept {
	delete[] p_ptr;
	p_ptr = nullptr;
	arrSize = 0;
	arrCapacity = 0;
}
//precondition: none
//postcondition: returns size of current array. 
template<typename T>
size_t DynamicArray<T>::size()const noexcept {
	return arrSize;
}
//precondition: none
//postcondition: returns capacity of array 
template<typename T>
size_t DynamicArray<T>::capacity() const noexcept {
	return arrCapacity;
}
//precondition: valid state needle to search for
//postcondition: index of target or -1 if not found. 
template<typename T>
int DynamicArray<T>::find(const T& needle) const noexcept {
	if (!p_ptr)return -1;

	for (size_t i = 0; i < arrSize;i++) 
		if (p_ptr[i] == needle)return (int)i;

	return -1;
}
//overload
template<typename T>
T& DynamicArray<T>::operator[](int index) {
	if (index < 0 || index >= arrSize || !p_ptr)
		throw std::exception("ERROR: OUT OF BOUNDS. ");

	return p_ptr[index];
}
//overload
template<typename T>
const T& DynamicArray<T>::operator[](int index) const {
	if (index < 0 || index >= arrSize || !p_ptr)
		throw std::exception("ERROR: OUT OF BOUNDS. ");
	return p_ptr[index];
}
