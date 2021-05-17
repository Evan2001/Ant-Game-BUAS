#pragma once

//class for the opponenets
class Opponent
{
    public:
		int DamageNumbers[3];
		char* DamageNames[3];
		char* OpponentName;
	    int hp;
	    int Values_Attacks;
		bool lost;
		bool played;
};

namespace Tmpl8 {

//extern int main();
class Surface;



class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
    void PressOne();//controls: key one
	void PressTwo();//controls: key two
    void PressThree();//controls: key three
    void PressFour();//controls: key four
	void AttackPlayer();//class for opponent turn
	
	//variables 
	int Player_Health;
	int Turn; //0 for player, 1 for opponent
	int Move_Choice;
	int Stampede_Damage;
	int Bite_Damage;
	int Claw_Damage;
	int Acid_Damage;
    int Grab_Damage;
	bool lost;
	bool played[5];

    
	//void Battle(int main);
//private:
	Surface* screen;
	Opponent opponent[5];//array for there to be 5 opponents 
	Opponent* CurrentOpponent;//pointer for class opponent

};
}; // namespace Tmpl8        opponent[3].DamageNumbers[2] = 3;

		