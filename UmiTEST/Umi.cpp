#include <ResourceManager.h>
#include "TestGame.h"

TestGame game;

int main(int argc, char* args[])
{
	game.Init(1280, 720);
	

	game.MainLoop();
	game.Exit();
	return 0;
}