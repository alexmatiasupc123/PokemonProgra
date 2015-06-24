#include "Juego.h"
#include <stdlib.h>

CJuego::CJuego()
{
	lider = new CLider();
	jugador = new CPersonaje();
	arrPokemonesSilvestres = NULL;
	nPokemonesSilvestres = 0;
	arrObjetos = NULL;
	nObjetos = 0;

	//agrego un pokemon en el mapa
}
CJuego::~CJuego()
{
}
void CJuego::agregarObjeto(CObjeto*arbol)
{	
	if( arbol == NULL)
		return;
	CObjeto**temp = new CObjeto*[nObjetos+1];
	for(int i=0;i<nObjetos;i++)
		temp[i] = arrObjetos[i];
	temp[nObjetos] = arbol;
	if(arrObjetos != NULL)
		delete arrObjetos;
	arrObjetos = temp;
	nObjetos++;
}
void CJuego::agregarPokemon(CPokemon*pokemon)
{
	if(pokemon == NULL)
		return;
	CPokemon**temp = new CPokemon*[nPokemonesSilvestres+1];
	for(int i=0;i<nPokemonesSilvestres;i++)
		temp[i] = arrPokemonesSilvestres[i];
	temp[nPokemonesSilvestres] = pokemon;
	if(arrPokemonesSilvestres != NULL)
		delete[]arrPokemonesSilvestres;
	arrPokemonesSilvestres = temp;
	nPokemonesSilvestres++;
}
void CJuego::pintarMapa(Graphics ^g, Bitmap ^jugador, Bitmap^arbol, Bitmap^casa, Bitmap^centroP, Bitmap^pasto, Bitmap^gym)
{
	for(int i=0;i<25;i++)
		for(int j=0;j<15;j++)
			g->DrawImage(pasto,i*40,j*40,40,40);
	for(int i=0;i<nObjetos;i++)
		if(arrObjetos[i]->getTipo() == 0)
			arrObjetos[i]->dibujar(g,arbol);
		else if(arrObjetos[i]->getTipo() == 1)
			arrObjetos[i]->dibujar(g, casa);
		else if (arrObjetos[i]->getTipo() == 3)
			arrObjetos[i]->dibujar(g, gym);
		else
			arrObjetos[i]->dibujar(g,centroP);
	this->jugador->pintar(g,jugador);
}
void CJuego::pintarGimnasio(Graphics ^g, Bitmap ^jugador,Bitmap^lider)
{
	this->lider->pintar(g,lider);
	this->jugador->pintar(g,jugador);
}
void CJuego::pintarBatalla(Graphics ^g)
{
}
void CJuego::pintarCentroP(Graphics ^g, Bitmap ^jugador)
{
	this->jugador->pintar(g,jugador);
}
void CJuego::pintarPokemonesSilvestres(Graphics ^g,Bitmap^pikachu)
{
	eliminarEstadoEliminarse();

	for(int i=0;i<nPokemonesSilvestres;i++)
		arrPokemonesSilvestres[i]->pintar(g,pikachu);
}
CPersonaje*CJuego::getJugador()
{
	return jugador;
}
CPokemon*CJuego::getPokemonEnPos(int pos)
{
	return arrPokemonesSilvestres[pos];
}
bool CJuego::guardarObjetosEnArchivo(char *nombre)
{	
	FILE *arch = fopen(nombre, "wb");
	if(arch == NULL)
		return false;
	fwrite(&nObjetos, sizeof(nObjetos),1,arch);
	for(int i=0;i<nObjetos;i++)
		arrObjetos[i]->guardarEnArchivo(arch);
	fwrite(&nPokemonesSilvestres, sizeof(nPokemonesSilvestres),1,arch);
	for(int i=0;i<nPokemonesSilvestres;i++)
		arrPokemonesSilvestres[i]->guardarEnArchivo(arch);
	fclose(arch);
	return true;
}
bool CJuego::cargarObjetosDeArchivo(char *nombre)
{	
	FILE *arch = fopen(nombre, "rb");
	if(arch == NULL)
		return false;
	for(int i=0;i<nObjetos;i++)
		delete arrObjetos[i];
	for(int i=0;i<nPokemonesSilvestres;i++)
		delete arrPokemonesSilvestres[i];
	int ne;
	fread(&ne, sizeof(ne),1,arch);
	for(int i=0; i<ne; i++)
	{
		CObjeto* objeto = new CObjeto();
		objeto->cargarDesdeArchivo(arch);
		agregarObjeto(objeto);
	}
	fread(&ne, sizeof(ne),1,arch);
	for(int i=0; i<ne; i++)
	{
		CPokemon* pokemon = new CPokemon();
		pokemon->cargarDesdeArchivo(arch);
		agregarPokemon(pokemon);
	}
	fclose(arch);

	ActualizarObjetos();
	return true;
}
int CJuego::colisionObjetos(int x,int y)
{
	for(int i=0;i<nObjetos;i++)
	{
		CObjeto*aux = arrObjetos[i];
		if(aux->getx() + aux->geta() > jugador->getx() + x && aux->getx() < jugador->getx() + jugador->geta() + x &&
		   aux->gety() + aux->geth() > jugador->gety() + y && aux->gety() < jugador->gety() + jugador->geth() + y )
		{
			return aux->getTipo();
		}
	}
	return -1;
}
int CJuego::colisionPokemon(int x,int y)
{
	for(int i=0;i<nPokemonesSilvestres;i++)
	{
		CPokemon*aux = arrPokemonesSilvestres[i];
		if(aux->getx() + aux->geta() > jugador->getx() + x && aux->getx() < jugador->getx() + jugador->geta() + x &&
		   aux->gety() + aux->geth() > jugador->gety() + y && aux->gety() < jugador->gety() + jugador->geth() + y )
		{
			return i;
		}
	}
	return -1;
}
CPokemon**CJuego::CREAR_ARREGLO(int n)
{
	return new CPokemon*[n];
}
void CJuego::eliminarEstadoEliminarse()
{
	int contador = 0;

	for (int i = 0; i<nPokemonesSilvestres; i++)
		if (arrPokemonesSilvestres[i]->getEliminado())
			contador++;

	CPokemon**aux = CREAR_ARREGLO(nPokemonesSilvestres - contador);
	if (aux != NULL)
	{
		int j = 0;
		for (int i = 0; i<nPokemonesSilvestres; i++)
		{
			if (arrPokemonesSilvestres[i]->getEliminado() != true)
			{
				aux[j] = arrPokemonesSilvestres[i];
				j++;
			}
		}

		nPokemonesSilvestres = j;
		if (arrPokemonesSilvestres != NULL)
			delete []arrPokemonesSilvestres;

		arrPokemonesSilvestres = aux;
	}
}
void CJuego::eliminarPokemonSilvestre(int posicion)
{
	arrPokemonesSilvestres[posicion]->setEliminado();
}
void CJuego::ActualizarObjetos()
{
	for (int i = 0; i < nObjetos; i++)
	{
		if (arrObjetos[i]->getTipo() == 1)
		{
			arrObjetos[i]->setA(82);
			arrObjetos[i]->setH(109);
		}
	}

	CObjeto*gym = new CObjeto(127, 151, 97, 99, 3);
	agregarObjeto(gym);
}