//input chaine de caract�re
#include <string>
#include <iostream>



Bloc lexer(const string& input) {
	/**
	Fonction qui prend une chaine de caract�res en entr�e correspondant aux op�rations.
		Elle renvoie un objet bloc.
	**/

	//Listes des symboles autoris�s.
	//String chiffres = "0123456789";
>>>>>>> Stashed changes
	String operateurs = "+-*/";
	DynArray<Bloc*> liste_des_blocs(input.size());
	int position_dans_array = 0; //position ou ranger le prochain bloc dans la liste des blocs.
	string nombre = 0;
	//Boucle pour parcourir la liste des �l�ments de la chaine.
	for (int position = 0; position < input.size(); ++position) {
		//si on rencontre un op�rateur
		if (operateurs.find(input[position]) >= 0)
		{
			liste_des_blocs[position_dans_array] = new Bloc(0, atof(nombre.c_str()), &liste_des_blocs[--position_dans_array]); //bloc nombre
			position_dans_array++;
			liste_des_blocs[position_dans_array] = new Bloc(1, input[position], &liste_des_blocs[position_dans_array-2], &liste_des_blocs[--position_dans_array], &liste_des_blocs[++position_dans_array]); //bloc op�rateur
		}
		else
			string + input[position];
	}
}

