#include "game.h"
#include "surface.h"
#include "windows.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio> //printf
#include "iostream"
#include<ctime>

using namespace std;

namespace Tmpl8
{
    void Game::Init() {
        Player_Health = 100;
        Turn = 0;
        Move_Choice;
        Stampede_Damage = 6;
        Bite_Damage = 3;
        Claw_Damage = 4;
        Acid_Damage = 5;
        //Grab_Damage = 6;
        
        time_t t;
        /* Intializes random number generator */
        srand((unsigned) time(&t));        
        CurrentOpponent = opponent[rand()%4];
        
        //slave ants
        opponent[0].hp = 50; 
        opponent[0].Values_Attacks = 3;
        opponent[0].damages[0].first = "Swipe";
        opponent[0].damages[0].second = 3;
        opponent[0].damages[1].first = "Tackle";
        opponent[0].damages[1].second = 3;
        opponent[0].damages[2].first = "Bite";
        opponent[0].damages[2].second = 3;
        
        //mantis
        opponent[1].hp = 100; 
        opponent[1].Values_Attacks = 1;
        opponent[0].damages[0].first = "Grab";
        opponent[0].damages[0].second = 6;
        opponent[0].damages[1].first = "Bite";
        opponent[0].damages[1].second = 3;
        opponent[0].damages[2].first = "Claw";
        opponent[0].damages[2].second = 4;
   
        //spider
        opponent[2].hp = 80; 
        opponent[2].Values_Attacks = 1;
        opponent[0].damages[0].first = "Spiderweb";
        opponent[0].damages[0].second = 5;
        opponent[0].damages[1].first = "Bite";
        opponent[0].damages[1].second = 3;
        opponent[0].damages[2].first = "Acid";
        opponent[0].damages[2].second = 5;

        //termite
        
        opponent[3].hp = 100; 
        opponent[3].Values_Attacks = 1;

        opponent[0].damages[0].first = "Bite";
        opponent[0].damages[0].second = 3;
        opponent[0].damages[1].first = "Crush";
        opponent[0].damages[1].second = 4;
        opponent[0].damages[2].first = "Claw";
        opponent[0].damages[2].second = 3;
        
        //beetle
        opponent[4].hp = 150; 
        opponent[4].Values_Attacks = 1;
        opponent[0].damages[0].first = "Tackle";
        opponent[0].damages[0].second = 3;
        opponent[0].damages[1].first = "Fly";
        opponent[0].damages[1].second = 4;
        opponent[0].damages[2].first = "Crush";
        opponent[0].damages[2].second = 3;

    }

    void Game::Shutdown() {}




    /*
        player controls    
    */
    void Game::PressOne(){ //
        screen->Clear(0);
        //char const* newchar = s.c_str();
        char test[10] = "HALLO\n";
        screen->Print(test, 2, 2, 0xffffff);
        
        Stampede_Damage = (10 + rand() % 6);
        Computer_Health -= Stampede_Damage;
        string stpd_dmg;
        string plyr_health;
        string cpt_health;

        //convert the values of health to string

    }
    
    //bite
    void Game::PressTwo(){
        screen->Clear(0);
        cout << "Key: 2" << endl;
        string s = to_string(12);
        char const* newchar = s.c_str();
        screen->Print((char*)newchar, 2, 2, 0xffffff);
    }
    
    //Claw
    void Game::PressThree(){
        screen->Clear(0);
        cout << "Key: 3" << endl;
    }
    
    //Acid
    void Game::PressFour(){
        screen->Clear(0);
        cout << "Key: 4" << endl;
    }
    


    static Sprite Mantis(new Surface("assets/mantis.png"), 1);
    static Sprite Ant(new Surface("assets/soldierant.png"), 1);
    static int frame = 0;

    // -----------------------------------------------------------
    // Main application tick function
    // -----------------------------------------------------------
    void Game::Tick(float deltaTime)
    {
        // clear the graphics window
        //screen->Clear(0);
        // print something in the graphics window
        //screen->Print("BATTLE!!!", 3, 3, 0xffffff);
        //screen->Print("BATTLE!!!", 4, 4, 0xffffff);
        // print something to the text window
        // printf("this goes to the console window.\n");
        // draw a sprite

        Ant.SetFrame(frame);
        Ant.DrawScaled(50, 120, 250, 150, screen);

        Mantis.SetFrame(frame);
        Mantis.DrawScaled(550, 120, 250, 150, screen);
        if (++frame == 1) frame = 0;

     
    }
        
        
};
