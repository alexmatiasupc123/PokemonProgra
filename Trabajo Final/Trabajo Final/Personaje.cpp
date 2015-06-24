#include "Personaje.h"
#include <stdlib.h>
#include <string.h>

CPersonaje::CPersonaje()
{
	x = 647;
	y = 306;
	dx = 5;
	dy = 5;
	a = 30;
	h = 40;
	indi = indj = 0;
	arrPokemones = NULL;
	nPokemones = 0;
	
	//agrego pikachu al equipo de ash
	CPokemon*pokemon = new CPokemon(0,0,"pikachu");
	pokemon->setAtaque("Ataque Basico",5,1);
	pokemon->setAtaque("Impact Trueno",10,2);
	pokemon->setAtaque("Embestida",6,3);
	pokemon->setAtaque("Golpe Trueno",8,4);
	agregarPokemon(pokemon);
}
CPersonaje::~CPersonaje()
{
}
void CPersonaje::listar(ListBox^listbox)
{
	listbox->Items->Clear();
	for(int i=0;i<nPokemones;i++)
		listbox->Items->Add(gcnew String(arrPokemones[i]->getNombre()));
}
void CPersonaje::agregarPokemon(CPokemon*pokemon)
{
	if(pokemon == NULL)
		return;
	CPokemon**temp = new CPokemon*[nPokemones+1];
	for(int i=0;i<nPokemones;i++)
		temp[i] = arrPokemones[i];
	temp[nPokemones] = pokemon;
	if(arrPokemones != NULL)
		delete arrPokemones;
	arrPokemones = temp;
	nPokemones++;
}
void CPersonaje::pintar(Graphics ^g, Bitmap ^img)
{
	int anchoImagen = img->Width/3;
	int altoImagen = img->Height/4;
	Rectangle porcionAusar = Rectangle(indi*anchoImagen, indj*altoImagen, anchoImagen, altoImagen);
	Rectangle pintarEn = Rectangle(x, y, a, h);
	g->DrawImage(img, pintarEn, porcionAusar, GraphicsUnit::Pixel);
}
void CPersonaje::mover(int mov)
{
	switch (mov)
	{
		case 1://DERECHA
			indj = 1;
			x += dx;
			break;
		case 2://IZQUIERDA
			indj = 3;
			x -= dx;
			break;
		case 3://ARRIBA
			indj = 0;
			y -= dy;
			break;
		case 4://ABAJO
			indj = 2;
			y += dy;
			break;
	}	
	indi++;
	if (indi > 2)
		indi = 0;
}
int CPersonaje::gety()
{
	return y;
}
int CPersonaje::getx()
{
	return x;
}
int CPersonaje::geta()
{
	return a;
}
int CPersonaje::geth()
{
	return h;
}
void CPersonaje::setx(int x)
{
	this->x = x;
}
void CPersonaje::sety(int y)
{
	this->y = y;
}
void CPersonaje::guardarPos()
{
	xAnterior = x;
	yAnterior = y;
}
void CPersonaje::regresarPos()
{
	x = xAnterior;
	y = yAnterior;
}
CPokemon*CPersonaje::getPokemonEnPos(int pos)
{
	return arrPokemones[pos];
}
bool CPersonaje::pokemonesTienenVida()
{
	for (int i = 0; i < nPokemones; i++)
		if (arrPokemones[i]->getVidaActual() > 0)
			return true;
	return false;
}
void CPersonaje::regenerarPokemones()
{
	for (int i = 0; i < nPokemones; i++)
		arrPokemones[i]->setVidaActual(50);
}