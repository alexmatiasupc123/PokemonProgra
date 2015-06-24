#pragma once
#include "Pokemon.h"

using namespace System::Windows::Forms;
using namespace System;

class CPersonaje
{
	private:
		int x, y, dx, dy, a, h;
		int xAnterior,yAnterior;
		int indi, indj;
		CPokemon**arrPokemones;
		int nPokemones;
	public:
		CPersonaje();
		~CPersonaje();
		void listar(ListBox^listbox);
		void agregarPokemon(CPokemon*pokemon);
		void pintar(Graphics ^g, Bitmap ^img);
		void mover(int mov);
		bool pokemonesTienenVida();
		void regenerarPokemones();
		int gety();
		int getx();
		int geta();
		int geth();
		void setx(int x);
		void sety(int y);
		void guardarPos();
		void regresarPos();
		CPokemon*getPokemonEnPos(int pos);

};

