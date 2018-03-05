#include "../SDL/include/SDL.h"

#pragma comment(lib, "../SDL/libx86/SDL2main.lib")
#pragma comment(lib, "../SDL/libx86/SDL2.lib")

int main(int argc, char* argv[])
{
	bool run = true;
	SDL_Event ev;
	SDL_Window *window;                    // Declare a pointer
	SDL_Surface* screenSurface = NULL;
	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
	int x = 50;
	int y = 50;
	SDL_Rect Rect;
	Rect.w = 200;
	Rect.h = 200;
	Rect.x = 50;
	Rect.y = 50;
	SDL_Rect bullet;
	bullet.w = 50;
	bullet.h = 50;
	bullet.x = Rect.x;
	bullet.y = Rect.y;
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);

	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"Moving Square",                          // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		720,                               // width, in pixels
		480,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
	);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	// Check that the window was successfully created
	if (window == NULL) {
		// In the case that the window could not be made...
		
		return 1;
	}

	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);

	//Fill the surface blue
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 255));

	//Update the surface
	SDL_UpdateWindowSurface(window);

	while (run)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT)
			{
				run = false;
			}
			keystate = SDL_GetKeyboardState(NULL);
			if (keystate[SDL_SCANCODE_LEFT]) {
				Rect.x -= 4;
				bullet.x -= 4;
			}
			if (keystate[SDL_SCANCODE_RIGHT]) {
				Rect.x += 4;
				bullet.x += 4;
			}
			if (keystate[SDL_SCANCODE_UP]) {
				Rect.y -= 4;
				bullet.y -= 4;
			}
			if (keystate[SDL_SCANCODE_DOWN]) {
				Rect.y += 4;
				bullet.y += 4;
			}
			if (keystate[SDL_SCANCODE_SPACE])
			{
				for (bullet.x = Rect.x; bullet.x < 720; bullet.x += 10)
				{
					SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
					SDL_RenderClear(renderer);
					SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
					SDL_RenderFillRect(renderer, &Rect);
					SDL_SetRenderDrawColor(renderer, 0, 255, 25, 0);
					SDL_RenderFillRect(renderer, &bullet);
					SDL_RenderPresent(renderer);

					if (SDL_PollEvent(&ev) != 0)
					{
						if (keystate[SDL_SCANCODE_LEFT]) {
							Rect.x -= 4;
						
						}
						if (keystate[SDL_SCANCODE_RIGHT]) {
							Rect.x += 4;
						
						}
						if (keystate[SDL_SCANCODE_UP]) {
							Rect.y -= 4;
						
						}
						if (keystate[SDL_SCANCODE_DOWN]) {
							Rect.y += 4;
							
						}
					}
				}
				bullet.x = Rect.x;
				bullet.y = Rect.y;
				
			}
			//Clear screen
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
			SDL_RenderClear(renderer);

			//Render red filled quad

			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
			SDL_RenderFillRect(renderer, &Rect);
	

			//Render green filled bulled
			SDL_SetRenderDrawColor(renderer, 0, 255, 25, 0);
			SDL_RenderFillRect(renderer, &bullet);
			SDL_RenderPresent(renderer);
		}
	}
	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}

