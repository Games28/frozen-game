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
	static void Number0Art(int x, int y, Graphics& gfx);
	static void Number1Art(int x, int y, Graphics& gfx);
	static void Number2Art(int x, int y, Graphics& gfx);
	static void Number3Art(int x, int y, Graphics& gfx);
	static void Number4Art(int x, int y, Graphics& gfx);
	static void Number5Art(int x, int y, Graphics& gfx);
	static void Number6Art(int x, int y, Graphics& gfx);
	static void Number7Art(int x, int y, Graphics& gfx);
	static void Number8Art(int x, int y, Graphics& gfx);
	static void Number9Art(int x, int y, Graphics& gfx);
	int Count();
	
private:
	
	static constexpr int Totalcount = 10;
	int Mycount[Totalcount];
	int thecounter = 0;
	int numberdimension = 20;
	const Vei2 pos{ 250,70 };
};

