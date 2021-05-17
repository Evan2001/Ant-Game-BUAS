switch (event.key.keysym.sym)
			{
			case SDL_QUIT:
				exitapp = 1;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) 
				{
					exitapp=1;
				}
				if (event.key.keysym.sym == SDLK_1) 
				{
					pressed = true;
					game->Move_Choice=1;
					game->PressOne();
				}
				if (event.key.keysym.sym == SDLK_2)
				{
					pressed = true;
					game->Move_Choice=2;
					game->PressTwo();
				}
				if (event.key.keysym.sym == SDLK_3)
				{
					game->Move_Choice=3;
					pressed = true;
					game->PressThree();
				}
				if (event.key.keysym.sym == SDLK_4)
				{
					pressed = true;
					game->Move_Choice=4;
					game->PressFour();
				}
					
        /*
			player
		*/
				//cout<<"TURN: "<< game->Turn<<endl;
				if(game->Turn==0){
					surface->Print("Pick a Move. <1> <2> <3> or <4>:", 2, 2,0xffffff);
					surface->Print("1. Stampede", 2, 22 , 0xffffff);
					surface->Print("2. Bite", 2, 42,0xffffff);
					surface->Print("3. Swipe", 2, 62,0xffffff);
					surface->Print("4. Acid", 2, 82, 0xffffff);
				}
				if(pressed){
					if(game->CurrentOpponent->hp<=0){
						game->CurrentOpponent->lost = true;
						cout<<"current opponent died."<< endl;
						int i=0;
						while(i<5 && game->played[i]){
							i++;
						}
						if (i >= 5) {
							cout<<"YOU WON AGAINST ALL ENEMIES\n"<<endl;
						}
							
						

					}
					if (game->Turn == 0)
						game->Turn = 1;
					else{
                        cout<<"start attacking player"
						game->AttackPlayer();
						game->Turn = 0;
					}

					pressed = false;
				}

				break;
			case SDLK_1:
				if (event.key.keysym.sym == SDLK_1)
				break;
			case SDLK_2:
				break;
			case SDLK_3:
				break;
			case SDLK_4:
				break;

			default:
				break;
			}
		}
	}