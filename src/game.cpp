#include "game.h"
#include <SDL/SDL.h>

class Game{

	public:
		Init(){
			// Initialize SDL
			if (SDL_Init(SDL_INIT_VIDEO) != 0)
			{
				SDL_Log("Failed to initialize SDL.");
				return false;
			}

			

			// Initialize Renderer
			if (!mRenderer.Init(1024, 768))
			{
				SDL_Log("Failed to initialize renderer.");
				return false;
			}

			// Start frame timer
			mTimer.Start();

			// Run any code at game start
			StartGame();

			return true;
		}

		void Quit(){

		}
}