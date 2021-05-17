#pragma once

//class for the opponenets
class Opponent
{
    public:
		int DamageNumbers[3];
		char* DamageNames[3];
	    int hp;
	    int Values_Attacks;
		bool lost;
		bool played;
		void AttackPlayer();

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
    void PressOne();
	void PressTwo();
    void PressThree();
    void PressFour();
	int Player_Health;
	int Turn; //0 for player, 1 for opponent
	int Move_Choice;
	int Stampede_Damage;
	int Bite_Damage;
	int Claw_Damage;
	int Acid_Damage;
    int Grab_Damage;
    
	//void Battle(int main);
//private:
	Surface* screen;
	Opponent opponent[5];
	Opponent* CurrentOpponent;

};
}; // namespace Tmpl8        opponent[3].DamageNumbers[2] = 3;

		