#include "Objeto.h"

CObjeto::CObjeto()
{
	x = y = a = h = tipo = 0;
}
CObjeto::CObjeto(int x,int y,int a,int h,int tipo)
{
	this->x = x;
	this->y = y;
	this->a = a;
	this->h = h;
	this->tipo = tipo;
}
CObjeto::~CObjeto(void)
{
}
void CObjeto::dibujar(Graphics^g,Bitmap^imgObj)
{
	g->DrawImage(imgObj,x,y,a,h);
}
int CObjeto::getx()
{
	return x;
}
int CObjeto::gety()
{
	return y;
}
int CObjeto::geta()
{
	return a;
}
int CObjeto::geth()
{
	return h;
}
int CObjeto::getTipo()
{
	return tipo;
}
void CObjeto::setA(int a)
{
	this->a = a;
}
void CObjeto::setH(int h)
{
	this->h = h;
}
void CObjeto::guardarEnArchivo(FILE *arch)
{	
	fwrite(&x, sizeof(x),1,arch);
	fwrite(&y, sizeof(y),1,arch);
	fwrite(&a, sizeof(a),1,arch);
	fwrite(&h, sizeof(h),1,arch);
	fwrite(&tipo, sizeof(tipo),1,arch);
}
void CObjeto::cargarDesdeArchivo(FILE *arch)
{	
	fread(&x, sizeof(x),1,arch);
	fread(&y, sizeof(y),1,arch);
	fread(&a, sizeof(a),1,arch);
	fread(&h, sizeof(h),1,arch);	
	fread(&tipo, sizeof(tipo),1,arch);	
}