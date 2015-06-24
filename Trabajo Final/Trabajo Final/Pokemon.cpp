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
	da�o1 = 0;
	da�o2 = 0;
	da�o3 = 0;
	da�o4 = 0;
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
void CPokemon::setAtaque(char*ataque,int da�o,int num)
{
	switch(num)
	{
		case 1:	strcpy(ataque1,ataque);	da�o1 = da�o;	break;
		case 2:	strcpy(ataque2,ataque);	da�o2 = da�o;	break;
		case 3: strcpy(ataque3,ataque);	da�o3 = da�o;	break;
		default:strcpy(ataque4,ataque);	da�o4 = da�o;	break;
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
int CPokemon::getDa�oAtaque1()
{
	return da�o1;
}
int CPokemon::getDa�oAtaque2()
{
	return da�o2;
}
int CPokemon::getDa�oAtaque3()
{
	return da�o3;
}
int CPokemon::getDa�oAtaque4()
{
	return da�o4;
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
	fwrite(&da�o1, sizeof(da�o1),1,arch);

	cantLetras = strlen(ataque2)+1;
	fwrite(&cantLetras, sizeof(cantLetras),1,arch);
	fwrite(&ataque2, sizeof(char),cantLetras,arch);
	fwrite(&da�o2, sizeof(da�o2),1,arch);

	cantLetras = strlen(ataque3)+1;
	fwrite(&cantLetras, sizeof(cantLetras),1,arch);
	fwrite(&ataque3, sizeof(char),cantLetras,arch);
	fwrite(&da�o3, sizeof(da�o3),1,arch);

	cantLetras = strlen(ataque4)+1;
	fwrite(&cantLetras, sizeof(cantLetras),1,arch);
	fwrite(&ataque4, sizeof(char),cantLetras,arch);
	fwrite(&da�o4, sizeof(da�o4),1,arch);
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
	fread(&da�o1, sizeof(da�o1),1,arch);

	fread(&cantLetras, sizeof(cantLetras),1,arch);
	fread(&ataque2, sizeof(char),cantLetras,arch);
	fread(&da�o2, sizeof(da�o2),1,arch);

	fread(&cantLetras, sizeof(cantLetras),1,arch);
	fread(&ataque3, sizeof(char),cantLetras,arch);
	fread(&da�o3, sizeof(da�o3),1,arch);

	cantLetras = strlen(ataque4)+1;
	fread(&cantLetras, sizeof(cantLetras),1,arch);
	fread(&ataque4, sizeof(char),cantLetras,arch);
	fread(&da�o4, sizeof(da�o4),1,arch);
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
void CPokemon::setDa�oAtaque1(int da�o1)
{
	this->da�o1 = da�o1;
}
void CPokemon::setDa�oAtaque2(int da�o2)
{
	this->da�o2 = da�o2;
}
void CPokemon::setDa�oAtaque3(int da�o3)
{
	this->da�o3 = da�o3;
}
void CPokemon::setDa�oAtaque4(int da�o4)
{
	this->da�o4 = da�o4;
}
bool CPokemon::getEliminado()
{
	return eliminado;
}
void CPokemon::setEliminado()
{
	eliminado = true;
}