#pragma once
#include "Graphics.h"
#include "Vei2.h"
#include "WInArt.h"
#include "FailArt.h"
#include "Snowflakes.h"
#include <iostream>
#include <random>

class Background
{
public:
	Background() = default;
	
	void Snowinitailization();
	//back ground images
	static void MenuBackGround(Vei2& pos, Graphics& gfx);
	static void GameBackGround(Vei2& pos, Graphics& gfx);
	static void CloudArt(Vei2& pos, Graphics& gfx);
	static void GroundSnow(Vei2& pos, Graphics& gfx);
	//snow images and movement
	void DrawSnow(Graphics& gfx);
	void SnowSelection();
	void snowCollision();
	//game instruction images
	static void Spacebutton(Vei2& pos, Graphics& gfx);
	static void Enterbutton(Vei2& pos, Graphics& gfx);
	static void Instructionsbutton(Vei2& pos, Graphics& gfx);
	static void InstructionsMenu(Vei2& pos, Graphics& gfx);
	static void Exitbutton(Vei2& pos, Graphics& gfx);
	static void CharacterOptions(Vei2& pos, Graphics& gfx);
	static void CountOptions(Vei2& pos, Graphics& gfx);

	void TheWin(int random, Vei2& pos, Graphics& gfx);
	void TheLoss(int random, Vei2& pos, Graphics& gfx);
	
private:
	
	static constexpr int maxSnow = 10;
	Snowflakes snow[maxSnow];
	WInArt thewin;
	FailArt thefail;
	Vei2 pos;
};

