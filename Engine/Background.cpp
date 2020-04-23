#include "Background.h"




void Background::Snowinitailization()
{
	
		for (int i = 0; i < maxSnow; i++)
		{
			if (!snow[i].IsInit())
			{
				std::random_device rd;
				std::mt19937 rng(rd());
				std::uniform_int_distribution<int> xdist(50, 550);
				std::uniform_int_distribution<int> vRangey(1, 4);
				std::uniform_int_distribution<int> vRangex(-1, 1);
				std::uniform_int_distribution<int> Pick(1, 4);
				
				Vei2 Pos = { xdist(rng), 10 };
				Vei2 Vel = { vRangex(rng), vRangey(rng) };
				snow[i].Thesnow(Pos, Vel);
				snow[i].SelectedSnow(Pick(rng));
				snow[i].Init();
				
			}


		}
		
}





void Background::DrawSnow(Graphics& gfx)
{
	
	for (int i = 0; i < maxSnow; i++)
	{

		if (snow[i].IsInit())
		{
			
			if (snow[i].mysnow() == 1)
			{
				snow[i].snowflake100(gfx);
			}
			else if (snow[i].mysnow() == 2)
			{
				snow[i].snowflake54(gfx);
			}
			else if (snow[i].mysnow() == 3)
			{
				snow[i].snowflake150(gfx);
			}
			else if (snow[i].mysnow() == 4)
			{
				snow[i].snowflake80(gfx);
			}
		}
	}
	
}

void Background::SnowSelection()
{
	for (int i = 0; i < maxSnow; i++)
	{
		if (!snow[i].IsInit())
		{
			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<int> Pick(1, 4);
			snow[i].SelectedSnow(Pick(rng));
		}
	}
}

void Background::snowCollision()
{
	for (int i = 0; i < maxSnow; i++)
	{
		snow[i].Collision();
	}
}

void Background::titleInit()
{
	themenu[0] = InfoArt("back\\menubackground.bmp");
	themenu[1] = InfoArt("back\\cloud.bmp");
	Snowinitailization();
	snowCollision();
	themenu[2] = InfoArt("back\\groundsnow.bmp");
	themenu[3] = InfoArt("back\\spacebutton.bmp");
	themenu[4] = InfoArt("back\\countoptions.bmp");
	themenu[5] = InfoArt("back\\characteroptions.bmp");
	themenu[6] = InfoArt("back\\instructionsbutton.bmp");
	themenu[7] = InfoArt("back\\snowflake.bmp");
	themenu[8] = InfoArt("back\\gamebackground.bmp");
}

void Background::TitleDraw(Graphics& gfx)
{
	gfx.DrawSpriteI(100, 100, themenu[0]);
	gfx.DrawSpriteI(25, 494, themenu[2]);
	DrawSnow(gfx);
	gfx.DrawSpriteI(10, 2, themenu[1]);
	gfx.DrawSpriteI(200, 540, themenu[3]);
	gfx.DrawSpriteI(550, 0, themenu[6]);
}

void Background::instructDraw(Graphics& gfx)
{
	gfx.DrawSpriteI(100, 100, themenu[7]);
	
}

void Background::MenuDraw(Graphics& gfx)
{
	gfx.DrawSpriteI(100, 100, themenu[0]);
	gfx.DrawSpriteI(25, 494, themenu[2]);
	DrawSnow(gfx);
	gfx.DrawSpriteI(10, 2, themenu[1]);
	gfx.DrawSpriteI(200, 540, themenu[3]);
	gfx.DrawSpriteI(600, 120, themenu[5]);
	gfx.DrawSpriteI(10, 420, themenu[4]);
	gfx.DrawSpriteI(550, 0, themenu[6]);
}

void Background::GameInit()
{
	Snowinitailization();
	snowCollision();
}

void Background::GameDraw(Graphics& gfx)
{
	gfx.DrawSpriteI(100, 100, themenu[8]);
	gfx.DrawSpriteI(25, 494, themenu[2]);
	DrawSnow(gfx);
	gfx.DrawSpriteI(10, 2, themenu[1]);
	gfx.DrawSpriteI(550, 0, themenu[6]);
}

void Background::WinInit()
{
	thewin[0] = WinArt("win\\win1.bmp");
	thewin[1] = WinArt("win\\win2.bmp");
	thewin[2] = WinArt("win\\win3.bmp");
	thewin[3] = WinArt("win\\win4.bmp");
	thewin[4] = WinArt("win\\win5.bmp");
	thewin[5] = WinArt("win\\win6.bmp");
	thewin[6] = WinArt("win\\win7.bmp");
	thewin[7] = WinArt("win\\win8.bmp");
	thewin[8] = WinArt("win\\exitbutton.bmp");

}

void Background::WinDraw(int n,Graphics& gfx)
{
    gfx.DrawSpriteW(1200, 300, thewin[8]);
	gfx.DrawSpriteW(100, 100, thewin[0]);
	//if (n == 1)
	//{
	//	gfx.DrawSpriteW(100, 100, thewin[0]);
	//}
	//else if (n == 2)
	//{
	//	gfx.DrawSpriteW(100, 100, thewin[1]);
	//}
	//else if (n == 3)
	//{
	//	gfx.DrawSpriteW(100, 100, thewin[2]);
	//}
	//else if (n == 4)
	//{
	//	gfx.DrawSpriteW(100, 100, thewin[3]);
	//}
	//else if (n == 5)
	//{
	//	gfx.DrawSpriteW(100, 100, thewin[4]);
	//}
	//else if (n == 6)
	//{
	//	gfx.DrawSpriteW(100, 100, thewin[5]);
	//}
	//else if (n == 7)
	//{
	//	gfx.DrawSpriteW(100, 100, thewin[6]);
	//}
	//else if (n == 8)
	//{
	//	gfx.DrawSpriteW(100, 100, thewin[7]);
	//}
}

void Background::FailInit()
{
	thefail[0] = FailArt("fail\\fail1.bmp");
	thefail[1] = FailArt("fail\\fail2.bmp");
	thefail[2] = FailArt("fail\\fail3.bmp");
	thefail[3] = FailArt("fail\\fail4.bmp");
	thefail[4] = FailArt("fail\\fail5.bmp");
	thefail[5] = FailArt("fail\\fail6.bmp");
	thefail[6] = FailArt("fail\\fail7.bmp");
	thefail[7] = FailArt("fail\\exitbutton.bmp");
}

void Background::FailDraw(int n,Graphics& gfx)
{
	gfx.DrawSpriteF(100, 300, thefail[7]);
	gfx.DrawSpriteF(100, 100, thefail[0]);
	//if (n == 1)
	//{
	//	gfx.DrawSpriteF(100, 100, thefail[0]);
	//}
	//else if (n == 2)
	//{
	//	gfx.DrawSpriteF(100, 100, thefail[1]);
	//}
	//else if (n == 3)
	//{
	//	gfx.DrawSpriteF(100, 100, thefail[2]);
	//}
	//else if (n == 4)
	//{
	//	gfx.DrawSpriteF(100, 100, thefail[3]);
	//}
	//else if (n == 5)
	//{
	//	gfx.DrawSpriteF(100, 100, thefail[4]);
	//}
	//else if (n == 6)
	//{
	//	gfx.DrawSpriteF(100, 100, thefail[5] );
	//}
	//else if (n == 7)
	//{
	//	gfx.DrawSpriteF(100, 100, thefail[6]);
	//}
	//else if (n == 8)
	//{
	//	gfx.DrawSpriteF(100, 100, thefail[7]);
	//}
}	



