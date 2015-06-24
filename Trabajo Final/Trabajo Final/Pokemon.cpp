#include "Pokemon.h"
#include <string.h>

CPokemon::CPokemon()
{
	eliminado = false;
}
CPokemon::CPokemon(int x,int y,char*nombre)
{	
	this->x = x;
	this->y = y;
	a = h = 40;
	vidaActual = vidaMaxima = 50;
	exp = 0;
	nivel = 1;
	daño1 = 0;
	daño2 = 0;
	daño3 = 0;
	daño4 = 0;
	strcpy(this->nombre,nombre);
	eliminado = false;
}
CPokemon::~CPokemon()
{
}
void CPokemon::pintar(Graphics^g,Bitmap^pokemon)
{
	g->DrawImage(pokemon,x,y,a,h);
}
int CPokemon::getx()
{
	return x;
}
int CPokemon::gety()
{
	return y;
}
int CPokemon::geta()
{
	return a;
}
int CPokemon::geth()
{
	return h;
}
int CPokemon::getVidaActual()
{
	return vidaActual;
}
void CPokemon::setVidaActual(int vidaActual)
{
	this->vidaActual = vidaActual;
}
int CPokemon::getVidaMaxima()
{
	return vidaMaxima;
}
char* CPokemon::getNombre()
{
	return nombre;
}
void CPokemon::quitarVida(int vida)
{
	this->vidaActual-=vida;
	//if(vidaActual<=0)
		//vidaActual = 1;
}
void CPokemon::recuperarVida()
{
	if(vidaActual < vidaMaxima)
		vidaActual++;
}
void CPokemon::setAtaque(char*ataque,int daño,int num)
{
	switch(num)
	{
		case 1:	strcpy(ataque1,ataque);	daño1 = daño;	break;
		case 2:	strcpy(ataque2,ataque);	daño2 = daño;	break;
		case 3: strcpy(ataque3,ataque);	daño3 = daño;	break;
		default:strcpy(ataque4,ataque);	daño4 = daño;	break;
	}
}
char*CPokemon::getAtaque1()
{
	return ataque1;
}
char*CPokemon::getAtaque2()
{
	return ataque2;
}
char*CPokemon::getAtaque3()
{
	return ataque3;
}
char*CPokemon::getAtaque4()
{
	return ataque4;
}
int CPokemon::getDañoAtaque1()
{
	return daño1;
}
int CPokemon::getDañoAtaque2()
{
	return daño2;
}
int CPokemon::getDañoAtaque3()
{
	return daño3;
}
int CPokemon::getDañoAtaque4()
{
	return daño4;
}
void CPokemon::guardarEnArchivo(FILE *arch)
{	
	fwrite(&x, sizeof(x),1,arch);
	fwrite(&y, sizeof(y),1,arch);
	fwrite(&a, sizeof(a),1,arch);
	fwrite(&h, sizeof(h),1,arch);
	fwrite(&vidaActual, sizeof(vidaActual),1,arch);
	fwrite(&vidaMaxima, sizeof(vidaMaxima),1,arch);
	fwrite(&exp, sizeof(exp),1,arch);

	int cantLetras = strlen(nombre)+1;
	fwrite(&cantLetras, sizeof(cantLetras),1,arch);
	fwrite(&nombre, sizeof(char),cantLetras,arch);

	cantLetras = strlen(ataque1)+1;
	fwrite(&cantLetras, sizeof(cantLetras),1,arch);
	fwrite(&ataque1, sizeof(char),cantLetras,arch);
	fwrite(&daño1, sizeof(daño1),1,arch);

	cantLetras = strlen(ataque2)+1;
	fwrite(&cantLetras, sizeof(cantLetras),1,arch);
	fwrite(&ataque2, sizeof(char),cantLetras,arch);
	fwrite(&daño2, sizeof(daño2),1,arch);

	cantLetras = strlen(ataque3)+1;
	fwrite(&cantLetras, sizeof(cantLetras),1,arch);
	fwrite(&ataque3, sizeof(char),cantLetras,arch);
	fwrite(&daño3, sizeof(daño3),1,arch);

	cantLetras = strlen(ataque4)+1;
	fwrite(&cantLetras, sizeof(cantLetras),1,arch);
	fwrite(&ataque4, sizeof(char),cantLetras,arch);
	fwrite(&daño4, sizeof(daño4),1,arch);
}
void CPokemon::cargarDesdeArchivo(FILE *arch)
{	
	fread(&x, sizeof(x),1,arch);
	fread(&y, sizeof(y),1,arch);
	fread(&a, sizeof(a),1,arch);
	fread(&h, sizeof(h),1,arch);
	fread(&vidaActual, sizeof(vidaActual),1,arch);
	fread(&vidaMaxima, sizeof(vidaMaxima),1,arch);
	fread(&exp, sizeof(exp),1,arch);

	int cantLetras;
	fread(&cantLetras, sizeof(cantLetras),1,arch);
	fread(&nombre, sizeof(char),cantLetras,arch);

	fread(&cantLetras, sizeof(cantLetras),1,arch);
	fread(&ataque1, sizeof(char),cantLetras,arch);
	fread(&daño1, sizeof(daño1),1,arch);

	fread(&cantLetras, sizeof(cantLetras),1,arch);
	fread(&ataque2, sizeof(char),cantLetras,arch);
	fread(&daño2, sizeof(daño2),1,arch);

	fread(&cantLetras, sizeof(cantLetras),1,arch);
	fread(&ataque3, sizeof(char),cantLetras,arch);
	fread(&daño3, sizeof(daño3),1,arch);

	cantLetras = strlen(ataque4)+1;
	fread(&cantLetras, sizeof(cantLetras),1,arch);
	fread(&ataque4, sizeof(char),cantLetras,arch);
	fread(&daño4, sizeof(daño4),1,arch);
}
void CPokemon::setAtaque1(char*ataque1)
{
	strcpy(this->ataque1, ataque1);
}
void CPokemon::setAtaque2(char*ataque2)
{
	strcpy(this->ataque2, ataque2);
}
void CPokemon::setAtaque3(char*ataque3)
{
	strcpy(this->ataque3, ataque3);
}
void CPokemon::setAtaque4(char*ataque4)
{
	strcpy(this->ataque4, ataque4);
}
void CPokemon::setDañoAtaque1(int daño1)
{
	this->daño1 = daño1;
}
void CPokemon::setDañoAtaque2(int daño2)
{
	this->daño2 = daño2;
}
void CPokemon::setDañoAtaque3(int daño3)
{
	this->daño3 = daño3;
}
void CPokemon::setDañoAtaque4(int daño4)
{
	this->daño4 = daño4;
}
bool CPokemon::getEliminado()
{
	return eliminado;
}
void CPokemon::setEliminado()
{
	eliminado = true;
}