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
        CurrentOpponent = &opponent[rand()%4];
        
        //slave ants
        opponent[0].hp = 50; 
        opponent[0].Values_Attacks = 3;
        opponent[0].DamageNames[0] = (char*)malloc(15);
        strcpy(opponent[0].DamageNames[0],"Swipe");
        opponent[0].DamageNumbers[0] = 3;
        opponent[0].DamageNames[1] = (char*)malloc(15);
        strcpy(opponent[0].DamageNames[1],"Tackle");
        opponent[0].DamageNumbers[1] = 3;
        opponent[0].DamageNames[2] = (char*)malloc(15);
        strcpy(opponent[0].DamageNames[2],"Bite");
        opponent[0].DamageNumbers[2] = 3;
        opponent[0].lost = false;
        opponent[0].played = false;
        
        //mantis
        opponent[1].hp = 100; 
        opponent[1].Values_Attacks = 1;
        opponent[1].DamageNames[0] = (char*)malloc(15);
        strcpy(opponent[1].DamageNames[0],"Grab");
        opponent[1].DamageNumbers[0] = 6;
        opponent[1].DamageNames[1] = (char*)malloc(15);
        strcpy(opponent[1].DamageNames[1],"Bite");
        opponent[1].DamageNumbers[1] = 3;
        opponent[1].DamageNames[2] = (char*)malloc(15);
        strcpy(opponent[1].DamageNames[2],"Claw");
        opponent[1].DamageNumbers[2] = 4;
        opponent[1].lost = false;
        opponent[1].played = false;
        //spider
        opponent[2].hp = 80; 
        opponent[2].Values_Attacks = 3;
        opponent[2].DamageNames[0] = (char*)malloc(15);
        strcpy(opponent[2].DamageNames[0], "Spiderweb");
        opponent[2].DamageNumbers[0] = 5;
        opponent[2].DamageNames[1] = (char*)malloc(15);
        strcpy(opponent[2].DamageNames[1],"Bite");
        opponent[2].DamageNumbers[1] = 3;
        opponent[2].DamageNames[2] = (char*)malloc(15);
        strcpy(opponent[2].DamageNames[2], "Acid");
        opponent[2].DamageNumbers[2] = 5;
        opponent[2].lost = false;
        opponent[2].played = false;

        //termite        
        opponent[3].hp = 100; 
        opponent[3].Values_Attacks = 1;
        opponent[3].DamageNames[0] = (char*)malloc(15);
        strcpy(opponent[3].DamageNames[0], "Bite");
        opponent[3].DamageNumbers[0] = 3;
        opponent[3].DamageNames[1] = (char*)malloc(15);
        strcpy(opponent[3].DamageNames[1], "Crush");
        opponent[3].DamageNumbers[1] = 4;
        opponent[3].DamageNames[2] = (char*)malloc(15);
        strcpy(opponent[3].DamageNames[2], "Claw");
        opponent[3].DamageNumbers[2] = 3;
        opponent[3].lost = false;
        opponent[3].played = false;

        //beetle
        opponent[4].hp = 150; 
        opponent[4].Values_Attacks = 1;
        opponent[4].DamageNames[0] = (char*)malloc(15);
        strcpy(opponent[4].DamageNames[0], "Tackle");
        opponent[4].DamageNumbers[0] = 3;
        opponent[4].DamageNames[1] = (char*)malloc(15);
        strcpy(opponent[4].DamageNames[1], "Fly");
        opponent[4].DamageNumbers[1] = 4;
        opponent[4].DamageNames[2] = (char*)malloc(15);
        strcpy(opponent[4].DamageNames[2], "Crush");
        opponent[4].DamageNumbers[2] = 3;
        opponent[4].lost = false;
        opponent[4].played = false;
    }
        
    void Game::Shutdown() {}

    void AttackPlayer(){
        //a.h.v. attack moet hp van player lager worden
        //als hp van player<=0 lost end game (met lost screen)
        //zo niet turn aan player
        //turtn switching werkt?
        //
        //
        //
        //
    }


    /*
        player controls    
    */
    void Game::PressOne(){ //Stampede
        screen->Clear(0);
        cout<<"KEY 1"<<endl;
        screen->Print("You chose Stmapede", 2, 2, 0xffffff);
        cout<<"Stampede_Damage"<< Stampede_Damage<<endl;
        cout<<"CurrentOpponent->hp"<< CurrentOpponent->hp<<endl;
        CurrentOpponent->hp -= Stampede_Damage;

    }
    
    //bite
    void Game::PressTwo(){ // Bite
        screen->Clear(0);
        cout << "Key: 2" << endl;
        screen->Print("You chose Bite", 2, 2, 0xffffff);
        CurrentOpponent->hp -= Bite_Damage;

/*        string s = to_string(12);
        char const* newchar = s.c_str();
        screen->Print((char*)newchar, 2, 2, 0xffffff);*/
    }
    
    //Claw
    void Game::PressThree(){ // Claw
        screen->Clear(0);
        cout << "Key: 3" << endl;
        screen->Print("You chose Claw", 2, 2, 0xffffff);
        CurrentOpponent->hp -= Claw_Damage;
    }
    
    //Acid
    void Game::PressFour(){ // Acid
        screen->Clear(0);
        cout << "Key: 4" << endl;
        screen->Print("You chose Acid", 2, 2, 0xffffff);
        CurrentOpponent->hp -= Acid_Damage;
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
