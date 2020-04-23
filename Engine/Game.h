/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Background.h"
#include "Characters.h"
#include "Numbers.h"
#include "FailArt.h"
#include "InfoArt.h"


enum class gameState
{
    TITLE,
    MENU,
    GAME,
    WIN,
    LOSE
};

enum class Math
{
   TEN,
   TWENTYFIVE,
   FIFTY,
    DEFAULT
};

enum class Player
{
    ELSA,
    ANNA,
    OLAF,
    LIZARD,
    DEFUALT
};
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
    void DrawCharacters();
    void MenuCharacters();
    void MenuSelection();
    void Counting();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
    Background back;
    Background backF;
    Characters character;
    gameState state = gameState::MENU;
    Math numbers = Math::DEFAULT;
    Player player = Player::DEFUALT;
    Numbers number;
    int charwidth = 74;
    int charheight = 74;
    std::random_device rd;
    std::mt19937 rng;
    std::uniform_int_distribution<int> X50;
    std::uniform_int_distribution<int> Y50;
    std::uniform_int_distribution<int> X25;
    std::uniform_int_distribution<int> Y25;
    std::uniform_int_distribution<int> X10;
    int Y10 = 1;
    std::uniform_int_distribution<int> Rnumber;
    Vei2 charPos{ 10,150 };
    bool isRandomized = false;
    int randomX;
    int randomY;
    int Counttotal;
    int Randomtotal;
    int Randomnumber;
    bool countchecked = false;
    bool characterchecked = false;
    
    
	/********************************/
	/*  User Variables              */
	/********************************/
};