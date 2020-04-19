#pragma once
#include "Vei2.h"
#include "Graphics.h"
class Snowflakes
{
public:
	Snowflakes() = default;
	void Thesnow(Vei2& pos, Vei2& vel);
	void snowinit();
	 void snowflake54( Graphics& gfx);
	 void snowflake80(Graphics& gfx);
	 void snowflake100(Graphics& gfx);
	 void snowflake150(Graphics& gfx);
	 void Collision();
	 bool IsInit();
	 bool Init();
	 int SelectedSnow(int snow);
	 int& mysnow();

private:
	Vei2 pos;
	Vei2 vel;
	const int snowdimension = 84;
	bool isinit = false;
	int selectedsnow = -1;
};

