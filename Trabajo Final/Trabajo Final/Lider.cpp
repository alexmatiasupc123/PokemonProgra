#include "Lider.h"

CLider::CLider()
{
	x = 380;
	y = 60;
}
CLider::~CLider()
{
}
void CLider::pintar(Graphics ^g, Bitmap ^img)
{
	g->DrawImage(img, x, y, 40, 40);
}
int CLider::getx()
{
	return x;
}
int CLider::gety()
{
	return y;
}
void CLider::sety(int y)
{
	this->y = y;
}
void CLider::setx(int x)
{
	this->x = x;
}