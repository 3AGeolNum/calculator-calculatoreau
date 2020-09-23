#ifndef BLOC_h
#define BLOC_h

template<class T> class Bloc{
	public:
		Bloc( int nature, T item, Bloc* ptr_bas1 = nullptr, Bloc* ptr_bas2 = nullptr, Bloc* ptr_haut = nullptr );
		~Bloc();
		void Set_nature(int nature); //0 for nomber and 1 for operator
		int Get_nature();
		void Set_valeur();
		T Get_valeur();
		void Set_ptr();
	private :
		int nature_;//0 for nomber and 1 for operator
		T item_;
		Bloc* ptr_haut_;
		Bloc* ptr_bas1_;
		Bloc* ptr_bas2_;
		
}

#endif