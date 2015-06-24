#pragma once
using namespace System::Drawing;
#include <stdio.h>
class CPokemon
{
private:
	int x,y;
	int a,h;
	int vidaActual,vidaMaxima;
	int exp;
	int nivel;
	char nombre[20];
	char ataque1[20]; int da�o1;
	char ataque2[20]; int da�o2;
	char ataque3[20]; int da�o3;
	char ataque4[20]; int da�o4;
	bool eliminado;

public:
	CPokemon();
	CPokemon(int x,int y,char*nombre);
	~CPokemon();
	void pintar(Graphics^g,Bitmap^pokemon);
	int getx();
	int gety();
	int geta();
	int geth();
	int getVidaActual();
	void setVidaActual(int vidaActual);
	int getVidaMaxima();
	char*getNombre();
	void quitarVida(int vida);
	void recuperarVida();
	void setAtaque(char*ataque,int da�o,int num);
	char*getAtaque1();
	char*getAtaque2();
	char*getAtaque3();
	char*getAtaque4();
	void setAtaque1(char*ataque1);
	void setAtaque2(char*ataque2);
	void setAtaque3(char*ataque3);
	void setAtaque4(char*ataque4);
	void setDa�oAtaque1(int da�o1);
	void setDa�oAtaque2(int da�o2);
	void setDa�oAtaque3(int da�o3);
	void setDa�oAtaque4(int da�o4);
	bool getEliminado();
	void setEliminado();


	int getDa�oAtaque1();
	int getDa�oAtaque2();
	int getDa�oAtaque3();
	int getDa�oAtaque4();
	void guardarEnArchivo(FILE *arch);
	void cargarDesdeArchivo(FILE *arch);
};

