#pragma once
using namespace System::Drawing;
class CLider
{
	private:
		int x, y, a, h;
	public:
		CLider();
		~CLider();
		void pintar(Graphics ^g, Bitmap ^img);
		int getx();
		int gety();
		void sety(int y);
		void setx(int x);
};

