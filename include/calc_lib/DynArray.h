#ifndef DYNARRAY_h
#define DYNARRAY_h

#include <iostream>
#include <assert.h>

template <class T> class DynArray {
public:
	DynArray( int size );
	DynArray(const DynArray<T>& other);
	~DynArray();


	int size() const;
	void resize(int new_size); //attention
	DynArray<T>& operator=(DynArray<T> const& other);
	int push_back( const T& elt );
	const T& operator[](int index ) const;
	T& operator[](int index );
	void grow();
	void copy(const T* from, T* to);

private:
	T* elts_;
	int capacity_;
	int size_;
};
template <class T> DynArray<T>::DynArray(int size) : size_(size), elts_(new T[size]), capacity_(size) {
	assert(size >= 0);
}

template <class T> DynArray<T>::~DynArray() {
	delete[] elts_;
}

template <class T> T& DynArray<T>::operator[](int index) {
	//assert(index <= 0 && index > size_);
	return elts_[index];
}

template <class T> const T& DynArray<T>::operator[](int index) const {
	//assert(index >= 0 && index < size_);
	return elts_[index];
}
template <class T> DynArray<T>::DynArray(const DynArray<T>& other) : size_(other.size_), elts_(new T[other.capacity_]), capacity_(other.capacity_) {
	for (int ia = 0; ia < size_; ia++) {
		elts_[ia] = other.elts_[ia];
	}
}

template <class T> DynArray<T>& DynArray<T>::operator=(const DynArray<T>& other) {
	if (other != *this) {
		delete[] elts_;
	}
	size_ = other.size_;
	elts_ = new T[other.capacity_];
	capacity_ = other.capacity_;
	for (int ia = 0; ia < size_; ia++) {
		elts_[ia] = other.elts_[ia];
	}
}

template <class T> void DynArray<T>::grow()
{
	std::cout << "==> DynArray<T>::grow" << std::endl;
	capacity_ *= 2;
	T* bigger_elets = new T[capacity_];
	copy(elts_, bigger_elets);
	delete[] elts_;
	elts_ = bigger_elets;
}

template <class T> void DynArray<T>::copy(const T* from, T* to)
{
	for (int i = 0; i < size_; i++)
	{
		to[i] = from[i];
	}
	std::cout << "DynArray<T>::copy " << std::endl;
}

template <class T> int DynArray<T>::push_back(const T& elt) {
	if (size_ == capacity_)
	{
		grow();
	}
	elts_[size_] = elt;
	size_++;
	std::cout << "DynArray<T>::pushback " << elt << std::endl;

	return size_ - 1;
}

template <class T> int DynArray<T>::size() const {
	return size_;
}

template <class T> void DynArray<T>::resize(int new_size) {
	size_ = new_size;
}
#endif