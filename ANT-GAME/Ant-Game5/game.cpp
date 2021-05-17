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

        //Initialization of player's data
        Player_Health = 100;
        Turn = 0;
        Move_Choice;
        Stampede_Damage = 10;
        Bite_Damage = 4;
        Claw_Damage = 4;
        Acid_Damage = 6;
        lost  = false;


        for(int i = 0;i<5; i++)
            played[i] = false;
        //Grab_Damage = 6;
        
        time_t t;
        /* Intializes random number generator */
       
        /*
            The Opponent cards. These cards have the neccessary data for the opponent like: 
            name, damage, move names and amount of moves. 
        */


        /*
         * Initialization of opponent's data. For detailed description check the the header file
        */

        //slave ants
        opponent[0]= new Opponent;
        opponent[0]->OpponentName = (char*)malloc(15);
        if(opponent[0]->OpponentName!=nullptr)
            strcpy (opponent[0]->OpponentName,"Slave ants");
        opponent[0]->hp = 25; 
        opponent[0]->Values_Attacks = 3;
        opponent[0]->DamageNames[0] = (char*)malloc(10);
        if(opponent[0]->DamageNames[0]!=nullptr)
            strcpy(opponent[0]->DamageNames[0],"Swipe");
        opponent[0]->DamageNumbers[0] = 3;
        opponent[0]->DamageNames[1] = (char*)malloc(10);
        if(opponent[0]->DamageNames[1]!=nullptr)
            strcpy(opponent[0]->DamageNames[1],"Tackle");
        opponent[0]->DamageNumbers[1] = 3;
        opponent[0]->DamageNames[2] = (char*)malloc(10);
        if(opponent[0]->DamageNames[2]!=nullptr)
            strcpy(opponent[0]->DamageNames[2],"Bite");
        opponent[0]->DamageNumbers[2] = 3;
        opponent[0]->lost = false;
        opponent[0]->played = false;
        
        //mantis
        opponent[1]= new Opponent;
        opponent[1]->OpponentName = (char*)malloc(10);
        if(opponent[1]->OpponentName!=nullptr)
            strcpy(opponent[1]->OpponentName, "Mantis");
        opponent[1]->hp = 50; 
        opponent[1]->Values_Attacks = 1;
        opponent[1]->DamageNames[0] = (char*)malloc(10);
        if (opponent[1]->DamageNames[0] != nullptr)
            strcpy(opponent[1]->DamageNames[0],"Grab");
        opponent[1]->DamageNumbers[0] = 6;
        opponent[1]->DamageNames[1] = (char*)malloc(10);
        if (opponent[1]->DamageNames[1] != nullptr)
            strcpy(opponent[1]->DamageNames[1],"Bite");
        opponent[1]->DamageNumbers[1] = 3;
        opponent[1]->DamageNames[2] = (char*)malloc(10);
        if (opponent[1]->DamageNames[2] != nullptr)
            strcpy(opponent[1]->DamageNames[2],"Claw");
        opponent[1]->DamageNumbers[2] = 4;
        opponent[1]->lost = false;
        opponent[1]->played = false;

        //spider
        opponent[2]= new Opponent;
        opponent[2]->OpponentName = (char*)malloc(10);
        if(opponent[2]->OpponentName!=nullptr)
            strcpy(opponent[2]->OpponentName, "Spider");
        opponent[2]->hp = 30; 
        opponent[2]->Values_Attacks = 3;
        opponent[2]->DamageNames[0] = (char*)malloc(15);
        if (opponent[2]->DamageNames[0] != nullptr)
            strcpy(opponent[2]->DamageNames[0], "Spiderweb");
        opponent[2]->DamageNumbers[0] = 5;
        opponent[2]->DamageNames[1] = (char*)malloc(10);
        if (opponent[2]->DamageNames[1] != nullptr)
            strcpy(opponent[2]->DamageNames[1],"Bite");
        opponent[2]->DamageNumbers[1] = 3;
        opponent[2]->DamageNames[2] = (char*)malloc(10);
        if (opponent[2]->DamageNames[2] != nullptr)
            strcpy(opponent[2]->DamageNames[2], "Acid");
        opponent[2]->DamageNumbers[2] = 5;
        opponent[2]->lost = false;
        opponent[2]->played = false;

        //termite    
        opponent[3] = new Opponent;
        opponent[3]->OpponentName = (char*)malloc(10);
        if (opponent[3] != nullptr)
            strcpy(opponent[3]->OpponentName, "Termite");
        opponent[3]->hp = 45; 
        opponent[3]->DamageNames[0] = (char*)malloc(12);
        
        if (opponent[3]->DamageNames[0] != nullptr)
            strcpy(opponent[3]->DamageNames[0], "Bite");
        opponent[3]->DamageNumbers[0] = 3;
        opponent[3]->DamageNames[1] = (char*)malloc(10);
        if (opponent[3]->DamageNames[1] != nullptr)
            strcpy(opponent[3]->DamageNames[1], "Crush");
        opponent[3]->DamageNumbers[1] = 4;
        opponent[3]->DamageNames[2] = (char*)malloc(10);
        if (opponent[3]->DamageNames[2] != nullptr)
            strcpy(opponent[3]->DamageNames[2], "Claw");
        opponent[3]->DamageNumbers[2] = 3;
        opponent[3]->lost = false;
        opponent[3]->played = false;

        //beetle
        opponent[4]= new Opponent;
        opponent[4]->OpponentName = (char*)malloc(10);
        if(opponent[4]->OpponentName!=(char*)NULL)
            strcpy (opponent[4]->OpponentName, "Beetle");
        opponent[4]->hp = 55; 
        opponent[4]->Values_Attacks = 1;
        opponent[4]->DamageNames[0] = (char*)malloc(10);
        if (opponent[4]->DamageNames[0] != nullptr)
            strcpy (opponent[4]->DamageNames[0], "Tackle");
        opponent[4]->DamageNumbers[0] = 3;
        opponent[4]->DamageNames[1] = (char*)malloc(10);
        if (opponent[4]->DamageNames[1] != nullptr)
            strcpy (opponent[4]->DamageNames[1], "Fly");
        opponent[4]->DamageNumbers[1] = 4;
        opponent[4]->DamageNames[2] = (char*)malloc(10);
        if (opponent[4]->DamageNames[2] != nullptr)
            strcpy (opponent[4]->DamageNames[2], "Crush");
        opponent[4]->DamageNumbers[2] = 3;
        opponent[4]->lost = false;
        opponent[4]->played = false;

        int num = rand()%5;
        CurrentOpponentNum = num;
        srand((unsigned) time(&t));   
        CurrentOpponent = opponent[num];
        played[num] = true;
        
    }
        
    void Game::Shutdown() {
        /*for(int i=0; i<5; i++){
            free(opponent[i]->OpponentName);
            for(int j=0; j<2; j++){
                free(opponent[i]->DamageNames[j]);

            }
        }*/

    }

    /*
        An attack moment for the enemy when it's there turn.
    */
    
    int Game::AttackPlayer(){
        cout<<"start attacking player\n";
        time_t t;
        srand((unsigned) time(&t)); //time seed
        int num = rand()%3; //generate random value between 0 and number of possible attacks-1

        
        Player_Health -= CurrentOpponent->DamageNumbers[num];
        if (Player_Health <= 0){ //check if player is dead
            lost = true;
            screen->Print("You Lost", 70, 70, 0xffffff);
        }
        cout<<"attacking player ended\n";
        return num;
    }


    /*
        player controls    
    */

    //prints out what move the player chose on the screen
    void Game::PrintChoice(int choice){
        switch (choice)
        {
            case 1:
                cout<<"------------->KEY 1"<<endl;
                screen->Print("You chose Stampede", 250, 480, 0xffffff);
                break;
            case 2:
                cout << "------------->Key: 2" << endl;
                screen->Print("You chose Bite", 250, 480, 0xffffff);
                break;
            case 3:
                cout << "------------->Key: 3" << endl;
                screen->Print("You chose Claw", 250, 480, 0xffffff);
                break;
            case 4:
                cout << "------------->Key: 4" << endl;
                screen->Print("You chose Acid", 250, 480, 0xffffff);
                break;
            default:
                break;
        
        }
    }
    /*
     *input handlers
     */
    void Game::PressOne(){ //Stampede
        screen->Clear(0);
        CurrentOpponent->hp -= Stampede_Damage;

    }
    
    //bite
    void Game::PressTwo(){ // Bite
        screen->Clear(0);
        CurrentOpponent->hp -= Bite_Damage;

    }
    
    //Claw
    void Game::PressThree(){ // Claw
        screen->Clear(0);
        CurrentOpponent->hp -= Claw_Damage;
    }
    
    //Acid
    void Game::PressFour(){ // Acid
        screen->Clear(0);
        CurrentOpponent->hp -= Acid_Damage;
    }
    


    // all of the sprites the game provides
    static Sprite Mantis(new Surface("assets/mantis.png"), 1);
    static Sprite Ant(new Surface("assets/mier.png"), 1);//player sprite
    static Sprite Spider(new Surface("assets/spider.png"), 1);
    static Sprite Heart(new Surface("assets/heart.png"), 1);
    static Sprite HeartOpponent(new Surface("assets/heart.png"), 1);
    static Sprite SlaveAnt(new Surface("assets/soldierant.png"), 1);
    static Sprite Beetle(new Surface("assets/beetle.png"), 1);
    static Sprite Termite(new Surface("assets/termite.png"), 1);
    
    static int frame = 0;

    // -----------------------------------------------------------
    // Main application tick function
    // -----------------------------------------------------------
    void Game::Tick(float deltaTime, int opponent)
    {
        Ant.SetFrame(frame);//player sprite
        Ant.DrawScaled(50, 340, 250, 150, screen); // y = 120
        
        //Chech which opponent should be displayed
        if (opponent == 0) {
            SlaveAnt.SetFrame(frame);
            SlaveAnt.DrawScaled(550, 120, 250, 150, screen);
        }else if (opponent == 1) {
            Mantis.SetFrame(frame);
            Mantis.DrawScaled(550, 120, 250, 150, screen);            
        }else if (opponent == 2) {
            Spider.SetFrame(frame);
            Spider.DrawScaled(550, 120, 250, 150, screen);            
        }else if (opponent == 3) {
            Termite.SetFrame(frame);
            Termite.DrawScaled(550, 120, 250, 150, screen);
        }else if (opponent == 4) {
            Beetle.SetFrame(frame);
            Beetle.DrawScaled(550, 120, 250, 150, screen);
            
        }

        //heart sprite for player
        Heart.SetFrame(frame);
        Heart.DrawScaled(240, 450, 15, 15, screen); 

        //heart sprite for opponent
        HeartOpponent.SetFrame(frame);
        HeartOpponent.DrawScaled(450, 90, 15, 15, screen); 

        if (++frame == 1) frame = 0;
     
    }
        
        
};

//int x = 65435413;
//int b = 3;
//
//
//int *naam;
//
//int *b; b---->|314| b=true;
//b=5;  b-->|5|
//int *a; a-->|  rgarewhbe|
//a = b  b--->|5|<---a
//
//
//b--->|5|
//
//|     |    || |
//

