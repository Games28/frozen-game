#pragma once
#include "Graphics.h"
#include "Vei2.h"
#include "WinArt.h"
#include "FailArt.h"
#include "Snowflakes.h"
#include <iostream>
#include <random>
#include "InfoArt.h"

class Background
{
public:
	Background() = default;
	//code for snow initiating and animation
	void Snowinitailization();
	void DrawSnow(Graphics& gfx);
	void SnowSelection();
	void snowCollision();

	//code for title and instruction art
	void titleInit();
	void TitleDraw(Graphics& gfx);

	//code for menu
	void instructDraw(Graphics& gfx);
	void MenuDraw(Graphics& gfx);

	//code for game background
	void GameInit();
	void GameDraw(Graphics& gfx);

	//code for winning
	void WinInit();
	void WinDraw(int n,Graphics& gfx);

	//code for Failing
	void FailInit();
	void FailDraw(int n,Graphics& gfx);


private:

	static constexpr int maxSnow = 10;
	Snowflakes snow[maxSnow];
	static constexpr int Total = 10;
	InfoArt themenu[Total];
	
	
	WinArt thewin[Total];
	FailArt thefail[Total];
	Vei2 pos;
	
};

