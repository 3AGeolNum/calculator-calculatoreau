#include <calc_lib\bloc.h>
#include <calc_lib\DynArray.h>

DynArray<Bloc*> generate_operator_array(const DynArray<Bloc*>& calcul_initial);
bool link_bloc( const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, const DynArray<Bloc*>& calcul_initial,int num_ope, int num_bloc1, int num_bloc2, bool if_precedent_edited );

void initializing_links_for_plusminus( const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, 
const DynArray<Bloc*>& calcul_initial,int num_ope, int num_bloc1, int num_bloc2, bool if_precedent_edited );
void edit_links1( const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, const DynArray<Bloc*>& calcul_initial );
void seeker_and_fill(std::string symb, const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, int& count);
void ordonate_array(const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated);
DynArray<Bloc*> parser(const DynArray<Bloc*>& calcul_initial);