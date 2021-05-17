#include "game.h"
#include "surface.h"
#include "windows.h"
#include <ctime>
#include <cstdlib>
#include <cstdio> //printf
#include "iostream"

using namespace std;

namespace Tmpl8
{
    void Game::Init() {


        //int main()
        //{
        int Player_Health = 100,
            Computer_Health = 100,
            Turn = 0,
            Move_Choice,
            Computer_Weapon,
            Stampede_Damage = 0,
            Bite_Damage = 0,
            Claw_Damage = 0,
            Acid_Damage = 0,
            Grab_Damage;
        int Player_CannonQty = 3;
        //int Player_GrenadeQty = 4;
        //int Computer_CannonQty = 3;
        //int Computer_GrenadeQty = 4;


        srand(static_cast<int>(time(0)));

        do
        {

            if (Turn == 0)// Player Turn
            {
                //Surface* screen = new Surface;
                
                cout << "Pick a Move. <1> <2> <3> or <4>:\n";
                cout << "1. Stampede" << GetAsyncKeyState(VK_NUMPAD1) << endl;  //0x31 1111 Surface* screen; 
                cout << "2. Bite\n";
                cout << "3. Swipe\n";
                cout << "4. Acid\n";
                cin >> Move_Choice;

                /*screen->Print("1. stampede", 2, 2, 0xffffff);
                screen->Print("2. bite", 2, 2, 0xffffff);
                screen->Print("3. swipe", 2, 2, 0xffffff);
                screen->Print("4. acid", 2, 2, 0xffffff);*/
                //Validate weapon choice

                while ((Move_Choice < 1 || Move_Choice > 4))

                {
                    //cout << "\nPlease enter a valid option\n";
                    cin >> Move_Choice;
                }

                switch (Move_Choice)
                {

                case 1: // player chooses to attack with Stampede
                    Stampede_Damage = (10 + rand() % 6);
                    cout << "\nYou chose Stampede" << endl;
                    Computer_Health = Computer_Health - Stampede_Damage;
                    cout << "You inflicted " << Stampede_Damage << " points on your enemy." << endl;
                    cout << "Your health is " << Player_Health << endl;
                    cout << "The computer's health is " << Computer_Health << endl;
                    break;


                case 2:
                    Bite_Damage = (7 + rand() % 13);
                    cout << "\nYou chose Bite" << endl;
                    Computer_Health = Computer_Health - Bite_Damage;
                    cout << "You inflicted " << Bite_Damage << " points on your enemy." << endl;
                    cout << "Your health is " << Player_Health << endl;
                    cout << "The computer's health is " << Computer_Health << endl;
                    break;

                case 3:
                    Claw_Damage = (3 + rand() % 9);
                    cout << "\nYou chose Swipe" << endl;
                    Computer_Health = Computer_Health - Claw_Damage;
                    cout << "You inflicted " << Claw_Damage << " points on your enemy." << endl;
                    cout << "Your health is " << Player_Health << endl;
                    cout << "The computer's health is " << Computer_Health << endl;
                    break;

                case 4:
                    Acid_Damage = (9 + rand() % 9);
                    cout << "\nYou chose Acid" << endl;
                    Computer_Health = Computer_Health - Acid_Damage;
                    cout << "You inflicted " << Acid_Damage << " points on your enemy." << endl;
                    cout << "Your health is " << Player_Health << endl;
                    cout << "The computer's health is " << Computer_Health << endl;
                    break;
                }

            }



            if (Turn == 1) // Computer Turn
            {
                Computer_Weapon = rand() % 3;


                switch (Computer_Weapon)
                {

                case 1:

                    Grab_Damage = (10 + rand() % 6);
                    cout << "\nYour opponent used Grab and inflicted " << Grab_Damage << " points on you." << endl;
                    Player_Health = Player_Health - Grab_Damage;
                    cout << "Your health is " << Player_Health << endl;
                    cout << "The computer's health is " << Computer_Health << endl;
                    break;

                case 2:
                    Bite_Damage = (7 + rand() % 6);
                    cout << "\nYour opponent used Bite and inflicted " << Bite_Damage << " points on you." << endl;
                    Player_Health = Player_Health - Bite_Damage;
                    cout << "Your health is " << Player_Health << endl;
                    cout << "The computer's health is " << Computer_Health << endl;
                    break;

                case 3:
                    Claw_Damage = (3 + rand() % 10);
                    cout << "\nYour opponent used Swipe and inflicted " << Claw_Damage << " points on you." << endl;
                    Player_Health = Player_Health - Claw_Damage;
                    cout << "Your health is " << Player_Health << endl;
                    cout << "The computer's health is " << Computer_Health << endl;
                    break;


                }

            }


        } while (Player_Health >= 0 && Computer_Health >= 0); //loops while both players are alive



        if (Computer_Health < 0)
            cout << "Congratulations! You won!" << endl;

        if (Player_Health < 0)
            cout << "YOU HAVE DIED! GAME OVER!" << endl;;



        // std::cout<< "Press ENTER to continue..." << flush;

        // cin.ignore(cin.rdbuf()->in_avail()+1);

        //return 0;
        //};
    }

    
  //};

    void Game::Shutdown() {}


    


    static Sprite Mantis(new Surface("assets/mantis.png"), 1);
    static Sprite Ant(new Surface("assets/soldierant.png"), 1);
    static int frame = 0;

    // -----------------------------------------------------------
    // Main application tick function
    // -----------------------------------------------------------
    void Game::Tick(float deltaTime)
    {
        // clear the graphics window
        screen->Clear(0);
        // print something in the graphics window
        //screen->Print("BATTLE!!!", 2, 2, 0xffffff);
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
