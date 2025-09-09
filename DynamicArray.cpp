#include "DynamicArray.h"





template <typename T>
void DynamicArray<T>::mergeSort(T genericArr[], const int& beginningIndex, const int& endingIndex) {
	if (beginningIndex >= endingIndex) {
		return;
	}
	int middle = beginningIndex + (endingIndex - beginningIndex) / 2;
	mergeSort(genericArr, beginningIndex, middle);
	mergeSort(genericArr, middle + 1, endingIndex);
	merge(genericArr, beginningIndex, middle, endingIndex);
}


template <typename T>
void DynamicArray<T>::merge(T genericArr[], const int& beginningIndex, const int& middle, const int& endingIndex)
{
	int leftSize = middle - beginningIndex + 1;
	int rightSize = endingIndex - middle;


	T* leftArray = new T[leftSize];
	T* rightArray = new T[rightSize];

	for (int i = 0; i < leftSize; i++) {
		leftArray[i] = genericArr[beginningIndex + i];
	}
	for (int j = 0; j < rightSize; j++) {
		rightArray[j] = genericArr[middle + 1 + j];
	}
	int i = 0;
	int j = 0;
	int k = beginningIndex;
	while (i < leftSize && j < rightSize) {
		if (leftArray[i] <= rightArray[j]) {
			genericArr[k] = leftArray[i];
			i++;
		}
		else {
			genericArr[k] = rightArray[j];
			j++;
		}
		k++;
	}
	while (i < leftSize) {
		genericArr[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < rightSize) {
		genericArr[k] = rightArray[j];
		j++;
		k++;
	}
	delete[] leftArray;
	delete[] rightArray;
	}

template<typename T>
void DynamicArray<T>::sort() {
	if (p_size > 1) 
		mergeSort(p_ptr, 0, p_size - 1);
}

template<typename T>
DynamicArray<T>::DynamicArray() {
	p_ptr = nullptr;
	p_size = 0;
}
template <typename T>
DynamicArray<T>::DynamicArray(int new_size) {
	if (new_size < 0) {
		throw DynamicArray<T>::OutOfRange("ERROR: INVALID SIZE ENTERED. ");
	}
	p_ptr = new T[new_size];
	p_size = new_size;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& rhs) {
	if (rhs.p_size != 0 && rhs.p_ptr != nullptr) {
		p_ptr = new T[rhs.p_size];
		p_size = rhs.p_size;
		for (int i = 0; i < rhs.p_size;i++) {
			p_ptr[i] = rhs.p_ptr[i];
		}
	}
	else {
		p_ptr = nullptr;
		p_size = rhs.p_size;
	}
}
template<typename T>
DynamicArray<T>::~DynamicArray() {
		delete[] p_ptr;
		p_ptr = nullptr;
		p_size = 0;
}
template <typename T>
void DynamicArray<T>::append(const T& nVal) {
	if (p_ptr != nullptr) {
		T* n_ptr = nullptr;
		n_ptr = new T[p_size + 1];
		for (int i = 0; i < p_size;i++) {
			n_ptr[i] = p_ptr[i];
		}
		n_ptr[p_size] = nVal;
		delete[] p_ptr;
		p_ptr = n_ptr;
	}
	else {
		p_ptr = new T[1];
		p_ptr[0] = nVal;
	}
	p_size++;
	sort();
}
template <typename T>
void DynamicArray<T>::insert(const T& nVal, const int& sIndex) {
	if (sIndex < 0 || sIndex > p_size) {
		throw OutOfRange("ERROR: INVALID INDEX ATTEMPTED.");
	}
	T* n_ptr = new T[p_size + 1];
	for (int i = 0; i < sIndex; i++) {
		n_ptr[i] = p_ptr[i];
	}
	n_ptr[sIndex] = nVal;
	for (int i = sIndex; i < p_size; i++) {
		n_ptr[i + 1] = p_ptr[i];
	}
	delete[] p_ptr;
	p_ptr = n_ptr;
	p_size++;
	sort();
}

template <typename T>
const T& DynamicArray<T>::retrieve(const int& sIndex) const {
	if (sIndex < 0 || sIndex >= p_size) {
		throw OutOfRange("ERROR: INVALID INDEX ATTEMPTED. ");
	}
	else
		return p_ptr[sIndex];
}
template <typename T>
void DynamicArray<T>::remove(const int& sIndex) {
	if (sIndex < 0 || sIndex >= p_size) {
		throw OutOfRange("ERROR: INVALID INDEX ATTEMPTED.");
	}

	if (p_size == 1) { 
		delete[] p_ptr;
		p_ptr = nullptr;
		p_size = 0;
		return;
	}
	T* n_ptr = new T[p_size - 1];
	int j = 0;
	for (int i = 0; i < p_size; i++) {
		if (i != sIndex) {
			n_ptr[j++] = p_ptr[i];
		}
	}

	delete[] p_ptr;
	p_ptr = n_ptr;
	p_size--;
}

template<typename T>
bool DynamicArray<T>::exists(const T& needle) const{
	if (p_size == 0) return false;
	for (int i = 0; i < p_size;i++) {
		if (needle == p_ptr[i])return true;
	}
	return false;
}

template <typename T>
int DynamicArray<T>::size() const {
	return p_size;
}
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& rhs) {
	if (this != &rhs) {
		delete[] p_ptr;
		p_size = rhs.p_size;
		p_ptr = new T[rhs.p_size];
		for (int i = 0; i < p_size;i++) {
			p_ptr[i] = rhs.p_ptr[i];
		}
	}
		return *this;
	
}



template<typename T>
const T* DynamicArray<T>::data() const  {
	return p_ptr;
}

template <typename T>
bool DynamicArray<T>::erase(const T& needle, bool allOrOne) {
	return true;
}