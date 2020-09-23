#ifndef DYNARRAY.h
#define DYNARRAY.h

#include <iostream>

template <class T> class DynArray {
public:
	DynArray( int size );
	DynArray(const DynArray<T>& other);
	~DynArray();


	int size() const;
	DynArray<T>& operator=(DynArray<T> const& other);
	T& push_back( const T& elt );
	const T& operator[](int index ) const;
	T& operator[](int index );

private:
	T* elts_;
	int capacity_;
	int size_;
};

#endif