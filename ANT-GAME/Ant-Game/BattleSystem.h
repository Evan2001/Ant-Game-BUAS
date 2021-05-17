#pragma once

#include "surface.h"
#include "windows.h"
#include <ctime>
#include <cstdlib>
#include <cstdio> //printf
#include "iostream"

namespace AntGame {

	//int main;
	class Surface;
	class Game;
	class Enemy
	{
		
	};
	class Mantis : public Enemy
	{
		int mantis_dmg = 11;
		int grab_dmg = 0;
		int claw_dmg = 0;
		int bite_dmg = 0;

	};
	class Spider : public Enemy
	{
		int spider_dmg = 11;
		int grab_dmg = 0;
		int claw_dmg = 0;
		int bite_dmg = 0;

	};
	class Battle
	{
	public:
		void SetTarget(Surface* surface) { screen = surface; }
		void Init();
		void Shutdown();
		void Tick(float deltaTime);
		void MouseUp(int button) { /* implement if you want to detect mouse button presses */ }
		void MouseDown(int button) { /* implement if you want to detect mouse button presses */ }
		void MouseMove(int x, int y) { /* implement if you want to detect mouse movement */ }
		void KeyUp(int key) { /* implement if you want to handle keys */ }
		void KeyDown(int key) { /* implement if you want to handle keys */ }
	private:
		Surface* screen;
		//methods
		void playerAction(int index);
		void enemyAction(int index);
	};

}; // namespace Tmpl8