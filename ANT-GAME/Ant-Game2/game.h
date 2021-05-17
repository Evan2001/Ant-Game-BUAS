#pragma once

namespace Tmpl8 {

//extern int main();
class Surface;

class Opponent
{
    public:
	    int hp; 
	    int Values_Attacks;
		std::pair <int, std::string> damages[3];

    private:
};

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
	int Player_Health,
		Turn,
		Move_Choice,
		Stampede_Damage,
		Bite_Damage,
		Claw_Damage,
		Acid_Damage,
        Grab_Damage;
    
	//void Battle(int main);
//private:
	Surface* screen;
	Opponent opponent[5];
	Opponent CurrentOpponent;

};
}; // namespace Tmpl8