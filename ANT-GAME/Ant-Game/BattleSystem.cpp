#include "BattleSystem.h"
//#include "game.h"
#include "surface.h"
#include "windows.h"
#include <ctime>
#include <cstdlib>
#include <cstdio> //printf
#include "iostream"

using namespace std;

namespace AntGame
{

	void Enemy()
	{
		
	};



void Battle::playerAction(int index)
{
    unsigned int playerHP = 35;
    //unsigned int computerhp = 25;
	unsigned int MantisHP = 25;

    int Turn = 0; //rand() 2%
    int Player_Move;
    //int Computer_Move; 

	int player_dmg = 10;
	int computer_dmg = 
	mantis_dmg = 11,
	spider_dmg = 8,
	enemyant_dmg = 9;

	unsigned int Attack = 
    bite_dmg = 1,
    scratch_dmg = 1.5,
    acid_dmg = 0,
	stampede_dmg = 0,
    swipe_dmg = 0,
    grab_dmg = 0,
    claw_dmg = 0;


    cout << "Player's HP:" << playerhp << endl;
    cout << "Enemies HP" << computerhp << endl;
    cout << "Bite = " << bite_dmg << endl;



	do 
	{

		if (Turn == 0)
		cout << "1. Bite\n" << bite_dmg << endl;
		cout << "2. Acid\n" << acid_dmg << endl;
		cout << "3. Scratch\n" << scratch_dmg << endl;
		cout << "2. Stampede\n" << stampede_dmg << endl;
		cin >> Player_Move;


		switch(Player_Move)
		{

		case 1:
			Attack = Attack * player_dmg;
			computerhp = Attack - computerhp;
			break;

		}

		Turn == 1;

		switch (Computer_Move)
		{

		case 1:
			Attack = Attack * computer_dmg;
			playerhp = Attack - playerhp;
			break;
		}
	}



	while (playerhp >= 0 && computerhp >= 0); //loops while both players are alive

	if (playerhp == 0)
	{
		cout << "Game-Over" << endl;
	};

	if (computerhp == 0)
	{
		cout << "You Win" << endl;
	};





    //class Battle
    //{
        //srand(static_cast<int>(time(0)));
	
        // std::cout<< "Press ENTER to continue..." << flush;

        // cin.ignore(cin.rdbuf()->in_avail()+1);

        return 0;
    }


	


	static Sprite Mantis(new Surface("assets/mantis.png"), 1);
	static Sprite Ant(new Surface("assets/soldierant.png"), 1);
	static int frame = 0;

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Battle::Tick(float deltaTime)
	{
		// clear the graphics window
		screen->Clear(0);
		// print something in the graphics window
		screen->Print("BATTLE!!!", 2, 2, 0xffffff);
		// print something to the text window
		printf("this goes to the console window.\n");
		// draw a sprite

		Ant.SetFrame(frame);
		Ant.DrawScaled(50, 120, 250, 150, screen);

		Mantis.SetFrame(frame);
		Mantis.DrawScaled(550, 120, 250, 150, screen);
		if (++frame == 1) frame = 0;

		//std::cout << hp << std::endl;

		///if (GetAsyncKeyState(VK_ONE)) { }
		//if (GetAsyncKeyState(VK_TWO)) {  }
		//int px = 0, py = 0;
		//tank.Draw(screen, px, py);
	}
};



