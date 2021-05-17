#include "game.h"
#include "BattleSystem.h"
#include "surface.h"
#include "windows.h"
#include <cstdio> //printf
#include <iostream>

namespace AntGame
{
	/*Surface tiles("assets/anthill.png");
	Sprite ant(new Surface("antSprite.png"), 16);
	int px = 0, py = 0;

	void Game::Init() {}
	void Game::Shutdown() {}

	char map[5][30] = {
	   "kc kc kc kc kc kc kc kc kc kc",
	   "kc fb fb fb kc kc kc kc kc kc",
	   "kc fb fb fb fb fb kc kc kc kc",
	   "kc lc lc fb fb fb kc kc kc kc",
	   "kc kc kc lc lc lc kc kc kc kc" };

	void DrawSprite() {}


	void Game::Tick(float deltaTime)
	{
		screen->Clear(0);
		for (int y = 0; y < 5; y++)
			for (int x = 0; x < 10; x++)
			{
				int tx = map[y][x * 3] - 'a', ty = map[y][x * 3 + 1] - 'a';
				DrawSprite(tx, ty, screen, x * 32, y * 32);
			}
		if (GetAsyncKeyState(VK_LEFT)) { px--; ant.SetFrame(12); }
		if (GetAsyncKeyState(VK_RIGHT)) { px++; ant.SetFrame(4); }
		if (GetAsyncKeyState(VK_UP)) { py--; ant.SetFrame(0); }
		if (GetAsyncKeyState(VK_DOWN)) { py++; ant.SetFrame(8); }
		ant.Draw(screen, px, py);
	}*/

};
		//Player
		//Enemy1
		//Enemy2
		//Etc.

		//Worldscreen
		//Map
		//Movement

		// transistion between battle screen and world screen
		//Transition

		//where the player will stand and transition to the battle screen
		//Dot1
		//Dot2
		//Dot3

		//Battlescreen
		//(loops)
		//START
		//PLAYERTURN
		//ENEMY TURN
		//WON
		//LOST
		//If lose lose end game

		//If won over to screen1


           
     
//		static Sprite Mantis(new Surface("assets/mantis.png"), 1);
//		static Sprite Ant(new Surface("assets/soldierant.png"), 1);
//		static int frame = 0;
//
//		// -----------------------------------------------------------
//		// Main application tick function
//		// -----------------------------------------------------------
//		void Game::Tick(float deltaTime)
//		{
//			// clear the graphics window
//			screen->Clear(0);
//			// print something in the graphics window
//			screen->Print("BATTLE!!!", 2, 2, 0xffffff);
//			// print something to the text window
//			printf("this goes to the console window.\n");
//			// draw a sprite
//
//			Ant.SetFrame(frame);
//			Ant.DrawScaled(50, 120, 250, 150, screen);
//
//			Mantis.SetFrame(frame);
//			Mantis.DrawScaled( 550, 120, 250, 150, screen);
//			if (++frame == 1) frame = 0;
//
//			std::cout<< hp <<std::endl;
//
//			///if (GetAsyncKeyState(VK_ONE)) { }
//			//if (GetAsyncKeyState(VK_TWO)) {  }
//			//int px = 0, py = 0;
//			//tank.Draw(screen, px, py);
//	}
//};