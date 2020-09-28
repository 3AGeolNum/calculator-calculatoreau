#include <iostream>

template <class T> DynArray<T>::DynArray( int size ): size_(size), elts_(new T[2*size]), capacity_(2*size){
	std::cout<<"coucou je suis un tableau dynamique de taille " << size_ << std::endl;
	assert( size >= 0 );
}

template <class T> DynArray<T>::~DynArray() {
	std::cout << "j'ai atomisé le tableau de taille " << size_ << std::endl;
	delete[] elts_;
}	

template <class T> T& DynArray<T>::operator[](int index ) {
	assert(index >= 0 && index < size_);
	return elts_[index];
}

template <class T> const T& DynArray<T>::operator[](int index) const {
	assert(index >=0 && index < size_);
        return elts_[index];
}
template <class T> DynArray<T>::DynArray(const DynArray<T>& other): size_(other.size_), elts_(new T[other.capacity_]), capacity_(other.capacity_) {
	for(int ia = 0; ia < size_; ia++) {
		elts_[ia] = other.elts_[ia];
	}
	std::cout<<"coucou je suis un tableau dynamique copié de taille " << size_ << std::endl;
}

template <class T> DynArray<T>& DynArray<T>::operator=(const DynArray<T>& other) {
	if( other != *this){
		delete[] elts_;
	}
	size_ = other.size_;
       	elts_ = new T[other.capacity_];
        capacity_ = other.capacity_;	
	for(int ia = 0; ia < size_; ia++) {
                elts_[ia] = other.elts_[ia];
        }
	std::cout<<"coucou je suis un tableau dynamique copié par opérateur = et de taille " << size_ << std::endl;
}

template <class T> T& DynArray<T>::push_back(const T& elt ) {
	assert( size_ < capacity_);
	elts_[size_] = elt;
	size_ += 1;
	std::cout << "on vient d'ajouter l'element " << elt << " a la fin du tableau" << std::endl;
}

template <class T> int DynArray<T>::size() const {
	return size_;
}
