#pragma once
#include "Vei2.h"
#include "Graphics.h"
class Characters
{
public:
	//menu art
	static void ElsaMenuArt(Vei2& pos, Graphics& gfx);
	static void AnnaMenuArt(Vei2& pos, Graphics& gfx);
	static void OlafMenuArt(Vei2& pos, Graphics& gfx);
	static void LizardMenuArt(Vei2& pos, Graphics& gfx);
	static void SnowSelector(Vei2& pos, Graphics& gfx);
	static void Count10(Vei2& pos, Graphics& gfx);
	static void Count25(Vei2& pos, Graphics& gfx);
	static void Count50(Vei2& pos, Graphics& gfx);
	//game art
	static void ElsaGameArt(int x, int y, Graphics& gfx);
	static void AnnaGameArt(int x, int y, Graphics& gfx);
	static void OlafGameArt(int x, int y, Graphics& gfx);
	static void LizardGameArt(int x, int y, Graphics& gfx);
	static void TheAmount(Vei2& pos, Graphics& gfx);

	
	
};

