 #pragma once
#include "Graphics.h"
#include "Vei2.h"
#include "Keyboard.h"


class Numbers
{
public:
	Numbers() = default;
	void Selection(Keyboard& kbd);
	void Draw(Graphics& gfx);
	//art
	 void Number0Art(int x, int y, Graphics& gfx);
	 void Number1Art(int x, int y, Graphics& gfx);
	 void Number2Art(int x, int y, Graphics& gfx);
	 void Number3Art(int x, int y, Graphics& gfx);
	 void Number4Art(int x, int y, Graphics& gfx);
	 void Number5Art(int x, int y, Graphics& gfx);
	 void Number6Art(int x, int y, Graphics& gfx);
	 void Number7Art(int x, int y, Graphics& gfx);
	 void Number8Art(int x, int y, Graphics& gfx);
	 void Number9Art(int x, int y, Graphics& gfx);
	int Count();
	
private:
	
	static constexpr int Totalcount = 10;
	int Mycount[Totalcount];
	int thecounter = 0;
	int numberdimension = 20;
	const Vei2 pos{ 250,70 };
};

