#pragma once
#include "Pokemon.h"
#include "Lider.h"
#include "Personaje.h"
#include "Arbol.h"
#include "Objeto.h"

using namespace System::Drawing;
class CJuego
{
	private:
		CLider *lider;
		CPersonaje *jugador;
		CPokemon **arrPokemonesSilvestres;
		int nPokemonesSilvestres;
		CObjeto ** arrObjetos;
		int nObjetos;
	public:
		CJuego();
		~CJuego();
		void agregarObjeto(CObjeto*arbol);
		void agregarPokemon(CPokemon*pokemon);
		void pintarMapa(Graphics ^g, Bitmap ^jugador, Bitmap^arbol, Bitmap^casa, Bitmap^centroP, Bitmap^pasto,Bitmap^gym);
		void pintarBatalla(Graphics ^g);
		void pintarGimnasio(Graphics ^g, Bitmap ^jugador,Bitmap^lider);
		void pintarCentroP(Graphics ^g, Bitmap ^jugador);
		void pintarPokemonesSilvestres(Graphics^g,Bitmap^pikachu);
		CPersonaje*getJugador();
		CPokemon*getPokemonEnPos(int pos);
		bool guardarObjetosEnArchivo(char *nombre);
		bool cargarObjetosDeArchivo(char *nombre);
		int colisionObjetos(int x,int y);
		int colisionPokemon(int x,int y);
		void eliminarEstadoEliminarse();
		void eliminarPokemonSilvestre(int posicion);
		CPokemon**CREAR_ARREGLO(int n);
		void ActualizarObjetos();
		//int colisionPokemonIndice(int x, int y);
};

