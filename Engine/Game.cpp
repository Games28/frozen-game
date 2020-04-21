/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"


#include <random>

Game::Game(MainWindow& wnd)
    :
    wnd(wnd),
    gfx(wnd),
    rng(rd()),
    X50(1, 10),
    Y50(1, 5),
    X25(1, 5),
    Y25(1,2),
    X10(1,9),
    Rnumber(1,8)
    
{
   
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    
    back.Snowinitailization();
    back.snowCollision();
    backF.Snowinitailization();
    backF.snowCollision();
    
    switch (state)
    {

    case gameState::TITLE:
        if (wnd.kbd.KeyIsPressed(VK_SPACE))
        {

            state = gameState::MENU;
        }
        break;
    case gameState::MENU:

        MenuSelection();
        Randomnumber = Rnumber(rng);
        
        
        
        
        if (numbers == Math::TEN)
        {
            randomX = X10(rng);
            randomY = Y10;
        }
        if (numbers == Math::TWENTYFIVE)
        {
            randomX = X25(rng);
            randomY = Y25(rng);
        }
        if (numbers == Math::FIFTY)
        {
            randomX = X50(rng);
            randomY = Y50(rng);
        }
        
        
            if (countchecked && characterchecked && wnd.kbd.KeyIsPressed(VK_SPACE))
            {  
               
                state = gameState::GAME;
            }
        
        break;
    case gameState::GAME:
       
       
        
        
        Randomtotal = randomY * randomX;
            number.Selection(wnd.kbd);
           
           
             if (wnd.kbd.KeyIsPressed(VK_RETURN))
             {
                 Counttotal = number.Count();
                 if (Counttotal == Randomtotal)
                 {
                     state = gameState::WIN;
                 }
                 else if (Counttotal != Randomtotal)
                 {
                     state = gameState::LOSE;
                 }
             }
            
        
        break;
    case gameState::WIN:
    {
        if (wnd.kbd.KeyIsPressed(VK_BACK))
        {
            Counttotal = 0;
            characterchecked = false;
            countchecked = false;
            numbers = Math::DEFAULT;
            player = Player::DEFUALT;
            state = gameState::MENU;
        }
        break;
    }
    case gameState::LOSE:
    {
        if (wnd.kbd.KeyIsPressed(VK_BACK))
        {
            Counttotal = 0;
            characterchecked = false;
            countchecked = false;
            numbers = Math::DEFAULT;
            player = Player::DEFUALT;
            state = gameState::MENU;
        }
        break;
    }

    }
    
}


void Game::ComposeFrame()
{
    for (int y = 0; y < Graphics::ScreenHeight - 1; y++)
    {
        for (int x = 0; x < Graphics::ScreenWidth - 1; x++)
        {
            int r = 0;
            int g = 170;
            int b = 210;
            gfx.PutPixel(x, y, r, g, b);
        }
    }
    
    switch (state)
    {
    case gameState::TITLE:

        back.DrawSnow(gfx);
        back.MenuBackGround(Vei2{ 100,100 }, gfx);
        backF.DrawSnow(gfx);
        backF.CloudArt(Vei2{ 0,0 }, gfx);
        back.GroundSnow(Vei2{ 25,494 }, gfx);
        back.Spacebutton(Vei2{ 200,540 }, gfx);
        break;

    case gameState::MENU:
        back.DrawSnow(gfx);
            back.MenuBackGround(Vei2{ 100,100 }, gfx);
            backF.DrawSnow(gfx);
            backF.CloudArt(Vei2{ 0,0 }, gfx);
            back.GroundSnow(Vei2{ 25,494 }, gfx);
            MenuCharacters();
            back.CharacterOptions(Vei2{ 600, 120 }, gfx);
            back.CountOptions(Vei2{ 10,420 }, gfx);
            back.Spacebutton(Vei2{ 200,540 }, gfx);
        
        break;
    case gameState::GAME:

        back.DrawSnow(gfx);
            back.GameBackGround(Vei2{ 100,100 }, gfx);
            backF.DrawSnow(gfx);
            
            DrawCharacters();
            backF.CloudArt(Vei2{ 0,0 }, gfx);
            back.GroundSnow(Vei2{ 25,494 }, gfx);
            character.TheAmount(Vei2{ 0,0 }, gfx);
            number.Draw(gfx);
           
        
        break;
    case gameState::WIN:

        back.TheWin(Randomnumber, Vei2{ 250,200 }, gfx);
        back.Exitbutton(Vei2{ 500,500 }, gfx);
        break;
    case gameState::LOSE:

        back.TheLoss(Randomnumber, Vei2{ 200,100 }, gfx);
            back.Exitbutton(Vei2{ 500,500 }, gfx);
        break;
    }
    back.Instructionsbutton(Vei2{ 550,0 }, gfx);
   if (wnd.kbd.KeyIsPressed(VK_TAB))
    {
    
        back.InstructionsMenu(Vei2{ 100,100 }, gfx);
       
    }
}



void Game::DrawCharacters()
{
  for (int y = 0; y < randomY; y++)
    {
        for (int x = 0; x < randomX; x++)
        {
            if (player == Player::ELSA)
            {
                character.ElsaGameArt(charPos.x + (x * charwidth), charPos.y + (y * charheight), gfx);
            }
            else if (player == Player::ANNA)
            {
                character.AnnaGameArt(charPos.x + (x * charwidth), charPos.y + (y * charheight), gfx);
            }
            else if (player == Player::OLAF)
            {
                character.OlafGameArt(charPos.x + (x * charwidth), charPos.y + (y * charheight), gfx);
            }
            else if( player == Player::LIZARD)
            {
                character.LizardGameArt(charPos.x + (x * charwidth), charPos.y + (y * charheight), gfx);
             
            }
           
        }
    }
}

void Game::MenuCharacters()
{
    character.ElsaMenuArt(Vei2{ 520,120 }, gfx);
    character.AnnaMenuArt(Vei2{ 520,240 }, gfx);
    character.OlafMenuArt(Vei2{ 520,365 }, gfx);
    character.LizardMenuArt(Vei2{ 520,480 }, gfx);
    character.Count10(Vei2{ 10,120 }, gfx);
    character.Count25(Vei2{ 10,240 }, gfx);
    character.Count50(Vei2{ 10,365 }, gfx);
    switch (player)
    {
    case Player::ELSA:
        character.SnowSelector(Vei2{ 455,120 }, gfx);
        break;
    case Player::ANNA:
        character.SnowSelector(Vei2{ 455,240 }, gfx);
        break;
    case Player::OLAF:
        character.SnowSelector(Vei2{ 455,365 }, gfx);
        break;
    case Player::LIZARD:
        character.SnowSelector(Vei2{ 455,480}, gfx);
        break;
    }
    switch (numbers)
    {
    case Math::TEN:
        character.SnowSelector(Vei2{ 170,120 }, gfx);
        break;
    case Math::TWENTYFIVE:
        character.SnowSelector(Vei2{ 170,240 }, gfx);
        break;
    case Math::FIFTY:
        character.SnowSelector(Vei2{ 200,365 }, gfx);
        break;
    }
}

void Game::MenuSelection()
{
    if (wnd.kbd.KeyIsPressed(VK_F1))
    {
        numbers = Math::TEN;
        countchecked = true;
    }
    if (wnd.kbd.KeyIsPressed(VK_F2))
    {
        numbers = Math::TWENTYFIVE;
        countchecked = true;
    }
    if (wnd.kbd.KeyIsPressed(VK_F3))
    {
        numbers = Math::FIFTY;
        countchecked = true;
    }
    if (wnd.kbd.KeyIsPressed(VK_F4))
    {
        player = Player::ELSA;
        characterchecked = true;
    }
    if (wnd.kbd.KeyIsPressed(VK_F5))
    {
        player = Player::ANNA;
        characterchecked = true;
    }
    if (wnd.kbd.KeyIsPressed(VK_F6))
    {
        player = Player::OLAF;
        characterchecked = true;
    }
    if (wnd.kbd.KeyIsPressed(VK_F7))
    {
        player = Player::LIZARD;
        characterchecked = true;
    }
    


}

void Game::Counting()
{
    int count = 0;
    for (int y = 0; y < randomY; y++)
    {
        
        for (int x = 0; x < randomX; x++)
        {
            count += y + x;
        }
    }
    Randomtotal = count;
    
}
