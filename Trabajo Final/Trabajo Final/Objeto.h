#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace System::Drawing;
class CObjeto
{
protected:
	int x,y,a,h;
	int tipo;
public:
	CObjeto();
	CObjeto(int x, int y,int a,int h,int tipo);
	~CObjeto(void);
	void dibujar(Graphics^g,Bitmap^imgObj);
	int getx();
	int gety();
	int geta();
	int geth();
	void setA(int a);
	void setH(int h);
	int getTipo();
	void guardarEnArchivo(FILE *arch);
	void cargarDesdeArchivo(FILE *arch);
};

