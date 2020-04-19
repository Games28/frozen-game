#pragma once
#include "Vei2.h"
#include "Graphics.h"
class Characters
{
public:
	//menu art
	void ElsaMenuArt(Vei2& pos, Graphics& gfx);
	void AnnaMenuArt(Vei2& pos, Graphics& gfx);
	void OlafMenuArt(Vei2& pos, Graphics& gfx);
	void LizardMenuArt(Vei2& pos, Graphics& gfx);
	void SnowSelector(Vei2& pos, Graphics& gfx);
	void Count10(Vei2& pos, Graphics& gfx);
	void Count25(Vei2& pos, Graphics& gfx);
	void Count50(Vei2& pos, Graphics& gfx);
	//game art
	void ElsaGameArt(int x, int y, Graphics& gfx);
	void AnnaGameArt(int x, int y, Graphics& gfx);
	void OlafGameArt(int x, int y, Graphics& gfx);
	void LizardGameArt(int x, int y, Graphics& gfx);
	void TheAmount(Vei2& pos, Graphics& gfx);

	
	
};

