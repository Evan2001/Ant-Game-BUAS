#pragma once

//class for the opponenets
class Opponent
{
    public:
		int DamageNumbers[3];//the damage number that will be used to exxtract from the player health. 
		char* DamageNames[3];//names of the moves the opponents can use. Every opponent can use up to 3 moves
		char* OpponentName;// name of the opponent, this prints out at template.cpp line ....
		int hp;//able to print the hp on the screen, we need to use a char* instead of an integer
	    int Values_Attacks;
		bool lost;//checks if the game is lost
		bool played;//checks which opponent has already been defeated or played against
};

namespace Tmpl8 {

class Surface;

class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime, int opponent);
    void PressOne();//controls: key one
	void PressTwo();//controls: key two
    void PressThree();//controls: key three
    void PressFour();//controls: key four
	void PrintChoice(int choice);
	int AttackPlayer();//for opponent turn
	
	// player's data
	int  Player_Health;
	int Turn; //0 for player, 1 for opponent
	int Move_Choice;//attack of the PlayerHP
	//Damage of different arracks
	int Stampede_Damage;
	int Bite_Damage;
	int Claw_Damage;
	int Acid_Damage;
    int Grab_Damage;
	bool lost; //player lost or not
	bool played[5];//Which opponents already played

    
	Surface* screen;
	int CurrentOpponentNum; //number of current opponent
	Opponent *opponent[5];//array for there to be 5 opponents 
	Opponent* CurrentOpponent;//pointer for class opponent

};
}; // namespace Tmpl8        opponent[3].DamageNumbers[2] = 3;

		