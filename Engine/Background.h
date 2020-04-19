#pragma once
#include "Graphics.h"
#include "Vei2.h"
#include "WInArt.h"
#include "FailArt.h"
#include "Snowflakes.h"

#include <random>

class Background
{
public:
	Background() = default;
	
	void Snowinitailization();
	//back ground images
	 void MenuBackGround(Vei2& pos, Graphics& gfx);
	 void GameBackGround(Vei2& pos, Graphics& gfx);
	 void CloudArt(Vei2& pos, Graphics& gfx);
	 void GroundSnow(Vei2& pos, Graphics& gfx);
	//snow images and movement
	void DrawSnow(Graphics& gfx);
	void SnowSelection();
	void snowCollision();
	//game instruction images
	 void Spacebutton(Vei2& pos, Graphics& gfx);
	 void Enterbutton(Vei2& pos, Graphics& gfx);
	 void Instructionsbutton(Vei2& pos, Graphics& gfx);
	 void InstructionsMenu(Vei2& pos, Graphics& gfx);
	 void Exitbutton(Vei2& pos, Graphics& gfx);
	 void CharacterOptions(Vei2& pos, Graphics& gfx);
	 void CountOptions(Vei2& pos, Graphics& gfx);

	void TheWin(int random, Vei2& pos, Graphics& gfx);
	void TheLoss(int random, Vei2& pos, Graphics& gfx);
	
private:
	
	static constexpr int maxSnow = 10;
	Snowflakes snow[maxSnow];
	WInArt thewin;
	FailArt thefail;
	Vei2 pos;
};

